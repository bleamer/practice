import requests
import argparse
import random
import sys
import time


def postTemp(sensor):
	while True:
		temp = 25.0 + random.random() / 10
		payload = {'temp': '%s'%(str(temp))}
		postAdd = 'http://127.0.0.1:5000/publish/'+ str(sensor) + '/' +str(temp)
		print(str(sensor)+": "+ str(postAdd))
		# r = requests.get("http://127.0.0.1:5000/publish/ss1/1231")
		try:
			r = requests.get(str(postAdd))
			print(r.status_code)
		except:
			pass
		time.sleep(1)

if __name__ == "__main__":
	if len(sys.argv) == 2:
		postTemp(sys.argv[1])