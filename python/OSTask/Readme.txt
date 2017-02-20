Readme.txt

This collection of files intends to simulate a realtime dashboard displaying temperature values to all subcribed clients

File components

[Server/main.py]
This file implements the dashboard server, which accepts temperature value published by sensor simulator app (sensor.py)
and publishes the temperature values of all the sensors along with sensor labels as JSON data to all the subscribed clients.
The server uses server sent event to achieve push message update for the subscribers, supported by all HTML5 clients
It also pushes a webclient "/" URI 

[templates/home.html]
Basic webclient showing realtime values of sensors received as JSON data in unformatted table

[Sensor/sensor.py]
This file implements basic sensor simulator generating random temperature value periodically and publishing them 
to publish URI for dashboard server

INSTALLATION
- Need python 3.4 or above
- need to install gevent, flask module in python 
These can be installed using python pip installer as:
$ sudo pip install gevents
$ sudo pip install flask
or these can installed using Linux native distro package managers

USAGE

1. Launch server
	$ python main.py
2. Launch client
	Change directory to Sensor folder
	Launch 3 sensors for trials (Can be more)
	$ python sensor.py sensor1 &
	$ python sensor.py sensor2 &
	$ python sensor.py sensor3 &

3. Launch a browser and navigate to subscription page
	- Assuming the server and client both will be running on localhost
	In the browser navigate to:
		http://127.0.0.1:5000/subscribe

	- This can be done in more than 1 browser
		Everytime the link is visited the subscription count on the server is increased

	- Total number of subscribers can be checked on the debug page as:
		http://127.0.0.1:5000/debug

		Showing a message like :
		Currently 3 subscriptions	

4. Monitor: To monitor the dashboard in client for realtime updates,
	Navigate to the / page as:
		http://127.0.0.1:5000/

		It should show updating messages like :
		{"sensor1": "25.019397664", "sensor3": "25.0167480684", "sensor2": "25.0589327963"}

		indicating 3 temperature sensors : sensor1, sensor2, sensor3
		and their respective last temperture values



FUTURE
Features can be added to:
- Unsubscritbe a client from receiving messages
- Authenticate sensor messages before updating dashboard
 etc.




