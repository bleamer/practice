#!/usr/bin/python

'''
Implements Heapsort
'''

# This function swaps the element in array 'Arr' at indices x and y
def swap (Arr, x, y):
	Arr[x], Arr[y] = Arr[y], Arr[x]

# This function heap sorts the data (list) and return the
# the sorted data in 'data' (list)
def heapSort( data ):
	datalen = len(data) - 1

	# Build the array with Heap property such
	# that root of the heap is the largest element
	least = datalen / 2
	for x in xrange(least, -1, -1):
		heapify(data, x, datalen)

	for x in xrange(datalen,0,-1):
		if data[0] > data[x]:
			swap (data, 0, x)
			heapify(data, 0, x-1)
		
# This function organises the data to adhere to Heap property
# inputs data - list containing data to be organized
# first - Index of the first element of interest in the list 'data'
# last - Index of the last element of interest in the list 'data'
def heapify(data, first, last):
	rightChild = (2 * first) + 1   # Right child is at position (2*n) + 1
	while rightChild <= last:
		if ( (rightChild < last) and (data[rightChild] < data[rightChild+1]) ):
			rightChild +=1

		# If right child is greater than parent
		# then swap them
		if (data[rightChild] > data[first]):
			swap (data, rightChild, first)

			# Start working on right Child's tree
			first = rightChild;
			rightChild = 2*first+1

		else:
			break;



# Test Code	
if __name__ == '__main__':
	import random
	import sys
	import time
	shortSize = 10
	popSize = shortSize * 10
	shortData = random.sample(range(0, popSize), shortSize)
	print "short data = "+ str(shortData)
	heapSort(shortData)
	print "sorted short data = "+ str(shortData)
 	
	largeSize = 1000000
	popSize = largeSize * 10
	largeData = random.sample(range(0, popSize), largeSize)
	# print "large data = "+ str(largeData)
	starttime = time.time()
	heapSort(largeData)
	print ("Sorted %d elements in %d seconds"%( largeSize, time.time()-starttime ) )
	# print "sorted large data = "+ str(largeData)

 