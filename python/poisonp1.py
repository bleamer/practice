import os
import sys

def stackImmortal(pArray, sImmortal):
	# First plant is immortal
	sImmortal = [(pArray[0],0)]
	for cur in range(1,len(pArray)-1):
		# if the current element is less than top of stack,
		# then this plant will never die, add this to stack
		# and save it's stack
		# print(pArray[cur])
		if (pArray[cur] <= TOS(sImmortal)[0]):
			sImmortal.append((pArray[cur],cur))

	# print(sImmortal)
	return sImmortal

def maxDaysToDeath(pArray,endIdx,startIdx):
	# For every plant to the right of the current plant in the decreasing order
	# it will take a day more for all plants to die in this block
	# @block : plants between two immortal plants
	pcidePrev = 0 # pesticide in previous plant
	nDays = 0
	# All occurrence of increasing pesticide towards the right will cause the 
	# plants to die in one day, so maintain a flag to spot increasing, decreasing
	# or monotonic progression

	trending_up = False
	trend_changed = False
	for cur in range(startIdx+1	, endIdx):
		# As long we are seeing decreaing arithmetic progression
		# keep on adding number of days
		trend_changed = False
		if (pArray[cur] > pArray[cur-1]):
			if trending_up == False:
				trend_changed = True
			trending_up = True
			# print(pArray[cur],pArray[cur-1])
		elif pArray[cur] == pArray[cur-1]:
			trend_changed = True
		else:
			if trending_up == True:
				trend_changed = True
			trending_up = False
		if trend_changed == True or trending_up == False:
			nDays += 1

	# print(startIdx,endIdx,nDays)
	return nDays

# Top Of Stack element
def TOS(stack):
	return (stack[len(stack)-1])

def POP(stack):

	return stack.pop()

if __name__ == '__main__':
	nPlants = sys.stdin.readline()
	# print(nPlants)
	paray = sys.stdin.readline()
	# print(paray)
	# print ("Array --^")
	# plantArray = [int(val) for val in paray.split()]
	plantArray = [int(val) for val in paray.split()]
	immortal = []
	maxDays = 0 
	immortal = stackImmortal(plantArray, immortal) # Create a stack of plants that will never die

	# print (immortal)
	maxDays = maxDaysToDeath(plantArray,len(plantArray)-1,TOS(immortal)[1])

	while(immortal != []): # while we have not covered all immortal plant blocks
		if (len(immortal) == 1):
			break

		daysToDeath = maxDaysToDeath(plantArray,POP(immortal)[1],TOS(immortal)[1])
		if maxDays < daysToDeath:
			maxDays = daysToDeath 

	print (maxDays+1)
