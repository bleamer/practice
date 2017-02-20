import gevent
from gevent.wsgi import WSGIServer
from gevent.queue import Queue
from flask import Flask, Response, render_template

import sys
import json

sys.path.append("../Sensor")

import sensor
import threading

# Map to store last know value of temperature sensors
sensors = dict()	

class ServerSentEvent(object):

	def __init__(self, data):
		self.data = data
		self.event = None
		self.id = None
		self.desc_map = {
			self.data : "data",
			self.event : "event",
			self.id : "id"
		}

	def encode(self):
		if not self.data:
			return ""
		lines = ["%s: %s" % (v, k) 
				 for k, v in self.desc_map.iteritems() if k]
		
		return "%s\n\n" % "\n".join(lines)

app = Flask(__name__)

# List of subscribed clients
subscriptions = []

# At '/' URL return with the template page
@app.route("/")
def index():
	return render_template('home.html')


# At /debug indicate the number of subscriptions
@app.route("/debug")
def debug():
	return "Currently %d subscriptions" % len(subscriptions)

# The sensors can do a get request to URI /publish/<sensorname>/<temperatureValue>
# Eg. 127.0.0.1:5000/publish/sensor1/50.1
@app.route("/publish/<sensor>/<temp>")
def publish(sensor, temp):

	#  Add the data to the map of sensor values
	sensors[sensor] = temp
	print ("Server:" + str(sensors[sensor]))

	# print('sensor -> ' + str(sensor) +', '+ str(temp) )
	def notify():
		# msg = '%s,%s'% (str(sensor), str(temp))
		# Publish all the temperatures to all subscribers
		msg = json.dumps(sensors, ensure_ascii=False)
		for sub in subscriptions[:]:
			sub.put(msg)

	# Sent a gevent alert to all clients waiting for a message
	gevent.spawn(notify)

	return "OK"

# A client can visit /subscribe URL to subscribe for realtime temperature
@app.route("/subscribe")
def subscribe():
	def gen():
		q = Queue()
		# Add all the clients visiting this URI to list of subscibers
		subscriptions.append(q)
		try:
			while True:
				result = q.get()
				ev = ServerSentEvent(str(result))
				yield ev.encode()
		except GeneratorExit: # Or maybe use flask signals
			subscriptions.remove(q)

	return Response(gen(), mimetype="text/event-stream")

if __name__ == "__main__":
	# Spawn the app and keep serving till applicatoin is killed
	app.debug = True
	server = WSGIServer(("", 5000), app)
	server.serve_forever()

	# s1thread = threading.Thread(target=sensor.postTemp, args=sense1)
	# s2thread = threading.Thread(target=sensor.postTemp, args=sense2)
	# s1thread.start()
	# s2thread.start()
	# sensor.postTemp(sense1)
	# sensor.postTemp(sense2)
	# Then visit http://localhost:5000 to subscribe 
	# and send messages by visiting http://localhost:5000/publish
























# from flask import Flask
# import random

# app = Flask(__name__)

# @app.route('/')
# def index():
# 	return 'Temperature monitoring solution'

# @app.route('/sensor/<sensorNum>')
# def getTemp(sensorNum):
# 	print('getTemp' + str(sensorNum))
# 	return 'The temperature is %s' % str(int(sensorNum) + random.random()/100)


# @app.route('/sse_notify')
# def sse_notify():
# 	def ready():
# 		try :
# 			while True:
# 				gevent.sleep()
# 				ev = ServerSentEvent(str('Ready'))
# 				yield ev.encode()
# 		except GeneratorExit:
# 			pass



# if __name__== "__main__":
# 	app.run(debug=True)