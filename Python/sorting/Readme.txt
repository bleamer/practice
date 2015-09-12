The file is an introduction the solution implmented for PS 5.

"Given a huge Data and a small data, perform the top sorting algorithms and compare the time
taken by each algorithm with each of the data set. Show us the result on a webpage."
--------------------------------------------------------
Usage:
The attached binary file 'server' is compiled to run on AMD_64bit Linux machine and can be invoked from command line.

Alternatively, the server application can be invoked from python interpreter (on MS Windows or Linux) using the attached source code as 

# python server.py

This is shall start the server on local machine and can be accessed via browser as

http://127.0.0.1:8080

on the same machine as server.

The default page on the server provides the option to start and cancel the comparison the comparison of algorithms namely, mergesort, quicksort, heapsort, insertion sort, and selection sort on small and large datasets 

Each algorithm will be run using generated random data sets of 10 elements(short data) and 10000 elements(large data) for comparison and their execution times compared. These dataset  size values are configurable inside the code to by altering values of 'shortSize' and 'largeSize' variables in algoEntry.py files

The webpage updates shall indicate the the random raw data as well as sorted data for all the compared algorithms for small and large datasets. 

The source code uses cherrypy library for setting up server and live rendering the results on the webpage, which can be installed using the attached archive (CherryPy-3.8.0.tar.gz) if 'server' executable needs to be run from source code.

Each sort algorithm file has included its test code, and the test code is executed when these files are invoked directly (not as imported modules)

###############
TROUBLESHOOTING
###############
In case the webpage does not display updated results, please install cherry python file (instructions for installation in the CherryPy-3.8.0.tar.gz archive) and invoke the server.py from interpreter keeping all source python files in same folder.
--------------------------------------------------------
SOLUTION AND IMPLEMENTATION OVERVIEW

The solution to the problem PS 5 is runs 5 sorting algorithms on small and large datasets, and is implemented in 7 files:
-----------
server.py
algoEntry.py

msort.py
quicksort.py
heapsort.py
selectionsort.py
insertionsort.py
--------------

Code flow :
The server.py sets up the server and invokes algoEntry.py and updates the received data on the webpage / webserver. The algoEntry.py module generates random data sets of modifiable sizes and invokes different sorting algorithms on these datasets.

