import gevent
from gevent.wsgi import WSGIServer
from gevent.queue import Queue

from flask import Flask, Response
import time

import sys
import json

sys.path.append("../Sensor")

import sensor
import threading

sensors = dict()

# SSE "protocol" is described here: http://mzl.la/UPFyxY
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
subscriptions = []

# Client code consumes like this.
@app.route("/")
def index():
	debug_template = """
	 <html>
	 <head>
	 </head>
	 <body>
	   <h1>Server sent events</h1>
	   <div id="event">
		 <table border="1">
		   <tr>
			 <td>hello</td>
			 <td id ="temp1">1.0</td>
		   </tr>
		 </table>
	   </div>
	   <script type="text/javascript">

		 //var eventOutputContainer = document.getElementById("event");
		 var eventOutputContainer = document.getElementById("temp1");
		 var evtSrc = new EventSource("/subscribe");

		 evtSrc.onmessage = function(e) {
		   console.log(e.data);
		   eventOutputContainer.innerHTML = e.data;
		 };

	   </script>
	 </body>
	 </html>
	"""
	return(debug_template)

@app.route("/debug")
def debug():
	return "Currently %d subscriptions" % len(subscriptions)

# @app.route("/publish")
# def publish():
#	 #Dummy data - pick up from request for real data
#	 def notify():
#		 msg = str(time.time())
#		 for sub in subscriptions[:]:
#			 sub.put(msg)
	
#	 gevent.spawn(notify)
	
#	 return "OK"

@app.route("/publish/<sensor>/<temp>")
def publish(sensor, temp):
	#Dummy data - pick up from request for real data
	sensors[sensor] = temp
	print ("Server:" + str(sensors[sensor]))

	# print('sensor -> ' + str(sensor) +', '+ str(temp) )
	def notify():
		# msg = '%s,%s'% (str(sensor), str(temp))
		msg = json.dumps(sensors, ensure_ascii=False)
		for sub in subscriptions[:]:
			sub.put(msg)

	gevent.spawn(notify)

	return "OK"

@app.route("/subscribe")
def subscribe():
	def gen():
		q = Queue()
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
	app.debug = True
	server = WSGIServer(("", 5000), app)
	server.serve_forever()

	s1thread = threading.Thread(target=sensor.postTemp, args=sense1)
	s2thread = threading.Thread(target=sensor.postTemp, args=sense2)
	s1thread.start()
	s2thread.start()
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