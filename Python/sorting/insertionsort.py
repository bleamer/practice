#!/usr/bin/python

# """
# Implements insertion sort
# """			
def insertionSort( data ):
	for x in xrange(0,len(data)):
		tmp = data[x]
		curIdx = x
		while (curIdx > 0 and tmp < data[curIdx-1]):
			data[curIdx] = data[curIdx-1]
			curIdx -= 1
		data[curIdx] = tmp




# Test Code	
if __name__ == '__main__':
	import random
	import sys
	import time
	shortSize = 10
	popSize = shortSize * 10
	shortData = random.sample(range(0, popSize), shortSize)
	print "short data = "+ str(shortData)
	insertionSort(shortData)
	print "sorted short data = "+ str(shortData)
 	
	largeSize = 1000000
	popSize = largeSize * 10
	largeData = random.sample(range(0, popSize), largeSize)
	# print "large data = "+ str(largeData)
	starttime = time.time()
	insertionSort(largeData)
	print ("Sorted %d elements in %d seconds"%( largeSize, time.time()-starttime ) )
	# print "sorted large data = "+ str(largeData)

 
