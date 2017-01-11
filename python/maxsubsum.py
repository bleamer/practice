import os
import sys




if __name__ == '__main__':
	testCount = sys.stdin.readline()
	# print(testCount)

	for idx in range(0,int(testCount)):
		maxSum = -sys.maxsize

		line = sys.stdin.readline()
		line = line.split()
		nCount, mod = int(line[0]), int(line[1])
		# print(nCount, mod)
		inArray = sys.stdin.readline().split()
		modArray = [int(val)%mod for val in inArray]
		# modArray = [int(val) for val in inArray]
		# print (thelist)
		# modArray = [val%mod for val in thelist]
		# print(modArray)

		# To store maxsum of mods of number from startIdx to the last element
		preCalcMod = [-sys.maxsize for x in range(len(modArray))]
		maxMod = 0
		for idx in range(len(modArray)):
			maxMod = (modArray[idx] + maxMod) % mod
			preCalcMod[idx] = mantxMod
		# print(preCalcSum)
		# print (max(preCalcSum))

		temp = 0
		for startIdx in range(len(modArray)):
			for idx in range(startIdx-1,0,-1):
				temp = max( temp, (preCalcMod[startIdx]-preCalcMod[idx]+mod)%mod) 
			temp = max(temp, preCalcMod[startIdx])

		print(temp)

	# 	startIdx = 0
	# 	endIdx = 0
	# 	maxStart, maxEnd, runSum = 0, 0, 0
	# 	for startIdx in range(0, len(modArray)):
	# 		runSum = 0
	# 		# if we still do not the max sum from this element to the last element
	# 		if preCalcSum[startIdx] == -sys.maxsize:
	# 			for idx in range(len(modArray)-1,startIdx,-1):
	# 				runSum += modArray[idx]
	# 				runSum %= mod
	# 				if runSum > maxSum:
	# 					maxSum = runSum
	# 				preCalcSum[idx] = maxSum
	# 				# print(idx,runSum, maxSum)
	# 				# print (preCalcSum)
	# #				if runSum >= mod-1:
	# #					maxSum = mod-1
	# #					break
	# 				# print (startIdx, endIdx, runSum, maxSum)
	# 		if preCalcSum[startIdx] >  maxSum:
	# 			maxSum = preCalcSum[startIdx]





						
		# print (maxSum)
