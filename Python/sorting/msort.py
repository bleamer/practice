'''
Merge sort : Sorts the passed array list in place using mergeSort
'''

def mergeSort( data ):
	size = len(data)

	if (size > 1):						# If there are elements to sort
		# if ((size / 2) % 2):
		# 	mid = (size / 2) - 1
		# else:
		mid = (size / 2)

		# print mid
		lArray = data[0:mid]
		# print lArray				
		rArray = data[mid:]

		lSize = len(lArray)
		rSize = len(rArray)

		mergeSort(lArray)				# sort the left array
		#print lArray
		mergeSort(rArray)				# sort the right array
		# print rArray
		lIdx = 0						# Current element index left array
		rIdx = 0						# Current element index in right array

		# Merge the left and right arrays
		for x in xrange(0,size):
			if lIdx < lSize:
				lValue = lArray[lIdx] 
			else: 
			 	lValue = None
			 	# print lIdx, lSize

			if rIdx < rSize:
				rValue = rArray[rIdx] 
			else: 
			 	rValue = None

			# if left array value and right array value arre both valid and left value is less than right value
			# OR 
			# there was no valid rValue then select the lValue
			if (lValue and rValue and lValue < rValue) or (rValue is None):
				data[x] = lValue
				lIdx += 1						# Advance the left index
			# else if lValue and rValue are both valid and right Value is less than left Value
			# OR 
			# there was no valid lValue then select the rValue
			elif (lValue and rValue and rValue < lValue) or (lValue is None):
				data[x] = rValue
				rIdx += 1
			else:
				Exception('Total subarray element count does not match parent array')
			# print x, lIdx, rIdx
		


# Test Code	
if __name__ == '__main__':
	import random
	import sys
	import time
	shortSize = 10
	popSize = shortSize * 10
	shortData = random.sample(range(0, popSize), shortSize)
	print "short data = "+ str(shortData)
	mergeSort(shortData)
	print "sorted short data = "+ str(shortData)
 	
	largeSize = 1000000
	popSize = largeSize * 10
	largeData = random.sample(range(0, popSize), largeSize)
	# print "large data = "+ str(largeData)
	starttime = time.time()
	mergeSort(largeData)
	print ("Sorted %d elements in %d seconds"%( largeSize, time.time()-starttime ) )
	# print "sorted large data = "+ str(largeData)

 