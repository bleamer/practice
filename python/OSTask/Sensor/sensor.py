import requests
import argparse
import random
import sys
import time


''' Temperature sensor simulator
	It ncessarily accepts a sensor name, and publishes random temperature values periodically to the server URI'''

def postTemp(sensor):
	while True:
		temp = 25.0 + random.random() / 10 # Generate random temperature around 25.0 C
		payload = {'temp': '%s'%(str(temp))}
		postAdd = 'http://127.0.0.1:5000/publish/'+ str(sensor) + '/' +str(temp) 
		print(str(sensor)+": "+ str(postAdd))
		# r = requests.get("http://127.0.0.1:5000/publish/ss1/1231")
		try:
			r = requests.get(str(postAdd)) # publish this message to publish URI for the dashboard server
			print(r.status_code)
		except:
			pass
		time.sleep(1) # publish the message periodically

if __name__ == "__main__":
	# Assume the scipt is invoked with sensor name as argument
	# if the script is invoked with sensor name only then generate random temperatures
	if len(sys.argv) == 2:
		postTemp(sys.argv[1])
	else:
		print("Please run the application with sensor name argument. E.g    $python sensor.py sensor1 ")
