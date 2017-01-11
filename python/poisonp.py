import os
import sys

def killPlants(pArray):
	prevPlant = 0
	killedPlant =  False
	killerStack = []
	# print (len(pArray))
	for cur in range(len(pArray)-1):
		# print(killerStack, prevPlant, cur)
		if pArray[cur] > pArray[prevPlant]: # If current plant has more pesticide than previous one
			killerStack.append(cur)		# stack the index of current plant, to be killed later such that next plant can be compared to it
		prevPlant = cur
	while killerStack != []:	# While there are indices of more plants to be killed
		del pArray[killerStack.pop()]	# Get the index and remove from the plant array
		killedPlant = True

	# print(killedPlant)
	return killedPlant


if __name__ == '__main__':
	nPlants = sys.stdin.readline()
	# print(nPlants)
	paray = sys.stdin.readline()
	# print(paray)
	# print ("Array --^")
	# plantArray = [int(val) for val in paray.split()]
	plantArray = [int(val) for val in paray.split()]
	dayCount = 0 
	while killPlants(plantArray) == True:
		dayCount += 1
	dayCount += 1
	print (dayCount)
