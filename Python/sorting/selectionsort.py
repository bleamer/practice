#!/usr/bin/python

'''
Implements selection sort
'''


def swap (Arr, x, y):
	Arr[x], Arr[y] = Arr[y], Arr[x]


def selectionSort(data):
	dataLength = len(data)
	for x in xrange(0,dataLength):				# For each element in the give data
		smallest = x;							# consider current element as the smallest
		for y in xrange(x+1,dataLength):		# From current element onwards
			if( data[y] < data[smallest]):		# if the current data is smaller than older smallest element
				smallest = y					# save the index of this new element
		swap(data, smallest, x)					# Swap the current element with smallest element found previously



# Test Code	
if __name__ == '__main__':
	import random
	import sys
	import time
	shortSize = 10
	popSize = shortSize * 10
	shortData = random.sample(range(0, popSize), shortSize)
	print "short data = "+ str(shortData)
	selectionSort(shortData)
	print "sorted short data = "+ str(shortData)
 	
	largeSize = 100000
	popSize = largeSize * 10
	largeData = random.sample(range(0, popSize), largeSize)
	# print "large data = "+ str(largeData)
	starttime = time.time()
	selectionSort(largeData)
	print ("Sorted %d elements in %d seconds"%( largeSize, time.time()-starttime ) )
	# print "sorted large data = "+ str(largeData)

 