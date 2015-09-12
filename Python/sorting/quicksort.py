#!/usr/bin/python

'''
Quick : Implements quick sort inplace sorting algorithm
'''

import random

def quickSort(data):
	doQuickSort( data, 0, len(data)-1)

def swap (Arr, x, y):
	Arr[x], Arr[y] = Arr[y], Arr[x]

def partitionArray(data, first, last):
	# Select a random pivot element between first and last element
	pivot = random.randint(first, last)

	# Move this pivot element to the end of list
	# by swapping with the last element
	swap(data, pivot, last)
	# for each element between first and last element
	for x in xrange(first,last):
		# if the current element is less than pivot element
		if data[x] <= data[last]:
			# Swap the element at current position with 
			# at first position
			swap(data, x, first)
			# Advance to the position where the next value
			# less than pivotal value will be swapped
			first += 1		
		# print data, x, data[last]
	# Swap the pivot element with first element		

	# the above operation will leave data in array such that
	# elements less pivot will be separated from elements more that pivot
	swap (data, first, last)		
	return first

def doQuickSort( data, first, last):
	if (first < last): 				# check for boundary condition
		# Partition the given data array around a random pivotal element
		pivot = partitionArray (data, first, last)
		# print pivot, data[pivot], data
		# Sort the array data till this pivot element
		doQuickSort(data, first, pivot-1)
		# Sort the array data after the pivot element
		doQuickSort(data, pivot + 1, last)




# Test Code	
if __name__ == '__main__':
	import random
	import sys
	import time
	shortSize = 10
	popSize = shortSize * 10
	shortData = random.sample(range(0, popSize), shortSize)
	print "short data = "+ str(shortData)
	quickSort(shortData)
	print "sorted short data = "+ str(shortData)
 	
	largeSize = 10000000
	popSize = largeSize * 10
	largeData = random.sample(range(0, popSize), largeSize)
	# print "large data = "+ str(largeData)
	starttime = time.time()
	quickSort(largeData)
	print ("Sorted %d elements in %d seconds"%( largeSize, time.time()-starttime ) )
	# print "sorted large data = "+ str(largeData)

 