#!/usr/bin/python

from msort import mergeSort
from insertionsort import insertionSort
from quicksort import quickSort
from selectionsort import selectionSort
from heapsort import heapSort

import copy
import random
import sys
import time
import datetime
from sys import stdout

def executeAlgos():
	# yield 'Starting executeAlgos...\n'

	shortSize = 10
	popSize = shortSize * 10
	shortData = random.sample(range(0, popSize), shortSize) # Generate Random data
	copyShortData = copy.deepcopy(shortData) # Maintain a copy for other algorithms
	print ("Generated random short data with %d elements\n"%shortSize)
	print "short data = "+ str(shortData) + "\n"
	stdout.flush()
	# yield ("Generated random short data with %d elements"%shortSize)

	# ------- SMALL DATASETS SORTING --------
	# Merge sort : small dataset
	startTime = datetime.datetime.now()
	mergeSort(shortData)
	endTime = datetime.datetime.now()
	elapsedTime = endTime - startTime
	print "Merge sorted short data = "+ str(shortData) + " in "+str(elapsedTime)+"\n"
	stdout.flush()
	# yield "\nMerge sorted short data = "+ str(shortData) + " in "+str(elapsedTime)

	# Quick sort : small dataset
	shortData = copy.deepcopy(copyShortData)
	startTime = datetime.datetime.now()
	quickSort(shortData)
	endTime = datetime.datetime.now()
	elapsedTime = endTime - startTime
	print "Quick sorted short data = "+ str(shortData) + " in "+str(elapsedTime) + "\n"
	stdout.flush()
	# yield "\nQuick sorted short data = "+ str(shortData) + " in "+str(elapsedTime)
		
	# Heap sort : small dataset
	shortData = copy.deepcopy(copyShortData)
	startTime = datetime.datetime.now()
	heapSort(shortData)
	endTime = datetime.datetime.now()
	elapsedTime = endTime - startTime
	print "Heap sorted short data = "+ str(shortData) + " in "+str(elapsedTime) + "\n"
	stdout.flush()
	# yield "\nQuick sorted short data = "+ str(shortData) + " in "+str(elapsedTime)

	# Insertion sort : small dataset
	shortData = copy.deepcopy(copyShortData)
	startTime = datetime.datetime.now()
	insertionSort(shortData)
	endTime = datetime.datetime.now()
	elapsedTime = endTime - startTime
	print "Insertion sorted short data = "+ str(shortData) + " in "+str(elapsedTime)+ "\n"
	stdout.flush()
	
	# Selection sort : small dataset
	shortData = copy.deepcopy(copyShortData)
	startTime = datetime.datetime.now()
	selectionSort(shortData)
	endTime = datetime.datetime.now()
	elapsedTime = endTime - startTime
	print "Selection sorted short data = "+ str(shortData) + " in "+str(elapsedTime)+ "\n"
	stdout.flush()
	



	# -------- LARGE DATA -------

	print '\n\n--------- Large data sets ---------\n\n' 	

	largeSize = 10000    # Data set size for large data set demonstration
	popSize = largeSize * 10 # Domain of random numbers allowed in random data set
	largeData = random.sample(range(0, popSize), largeSize) # Genrate Random data
	copyLargeData = copy.deepcopy(largeData) # Maintain a copy for other algorithms
	print ("Generated random large data with %d elements\n"%largeSize)
	# print "Large data = "+ str(largeData)+"\n"
	stdout.flush()
	# yield ("Generated random large data with %d elements"%largeSize)

	# Merge sort : large dataset
	print 'Merge sorting large data (%d elements)...\n' %( largeSize) 
	stdout.flush()
	startTime = datetime.datetime.now()
	mergeSortLargeData = copy.deepcopy(copyLargeData) # Maintain a copy for other algorithms
	mergeSort(mergeSortLargeData)
	endTime = datetime.datetime.now()
	elapsedTime = endTime - startTime
	print ("Merge sorted large data (%d elements) in "%( largeSize) + str(elapsedTime) ) + "\n"
	stdout.flush()
	# yield ("Merge sorted large data (%d elements) in "%( largeSize) + str(elapsedTime) )

	# Quick sort : large dataset
	print 'Quick sorting large data (%d elements)...\n' %( largeSize) 
	stdout.flush()
	quickSortLargeData = copy.deepcopy(copyLargeData)
	startTime = datetime.datetime.now()
	quickSort(quickSortLargeData)
	endTime = datetime.datetime.now()
	elapsedTime = endTime - startTime
	print ("Quick sorted large data (%d elements) in "%( largeSize) + str(elapsedTime)+ "\n" )
	stdout.flush()
	# yield ("Quick sorted large data (%d elements) in "%( largeSize) + str(elapsedTime) )

	# Heap sort : large dataset
	print 'Heap sorting large data (%d elements)...\n' %( largeSize) 
	stdout.flush()
	heapSortLargeData = copy.deepcopy(copyLargeData)
	startTime = datetime.datetime.now()
	heapSort(heapSortLargeData)
	endTime = datetime.datetime.now()
	elapsedTime = endTime - startTime
	print ("Heap sorted large data (%d elements) in "%( largeSize) + str(elapsedTime)+ "\n" )
	stdout.flush()
	# yield ("Quick sorted large data (%d elements) in "%( largeSize) + str(elapsedTime) )


	# Insertion sort : large dataset
	print 'Insertion sorting large data (%d elements)...\n' %( largeSize) 
	stdout.flush()
	insertionSortLargeData = copy.deepcopy(copyLargeData)
	startTime = datetime.datetime.now()
	insertionSort(insertionSortLargeData)
	endTime = datetime.datetime.now()
	elapsedTime = endTime - startTime
	print ("Insertion sorted large data (%d elements) in "%( largeSize) + str(elapsedTime)+ "\n" )
	stdout.flush()
	
	# Selection sort : large dataset
	print 'Selection sorting large data (%d elements)...\n' %( largeSize) 
	stdout.flush()
	largeSelectionSortData = copy.deepcopy(copyLargeData)
	startTime = datetime.datetime.now()
	selectionSort(largeSelectionSortData)
	endTime = datetime.datetime.now()
	elapsedTime = endTime - startTime
	print ("Selection sorted large data (%d elements) in "%( largeSize) + str(elapsedTime) + "\n")
	stdout.flush()
	

	print "Printing large data sets...\n"
	print "Raw large data set = "+ str(largeData)+"\n\n\n\n"
	print "\n\n ------ Sorted Large Data sets ------\n\n"
	print "Merge sorted large data = "+ str(mergeSortLargeData)+"\n\n\n\n"
	print "Quick Sorted large data = "+ str(quickSortLargeData)+"\n\n\n\n"
	print "Heap Sorted large data = "+ str(heapSortLargeData)+"\n\n\n\n"
	print "Insertion Sorted large data = "+ str(insertionSortLargeData)+"\n\n\n\n"
	print "Selection Sorted large data = "+ str(selectionSortLargeData)+"\n\n\n\n"
	print '\nAlgorithms execution ended ...\n'
	stdout.flush()

	
if __name__ == '__main__':
	print 'Starting algorithms execution ...\n'
	executeAlgos()
	# count = 5
	# for outputs in executeAlgos():
	# 	print(outputs+"\n")


# <!DOCTYPE html>
# <html>
# <body>

# <h1>What Can JavaScript Do?</h1>

# <p id="demo">JavaScript can change HTML content.</p>

# <button type="button"
# onclick="document.getElementById('demo').innerHTML = 'Hello JavaScript!'">
# Click Me!</button>

# </body>
# </html>
