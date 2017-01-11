import sys

# def splitFunc(nums,sum):
#	 # Series with odd sum cannot be split
#	 #print(nums, sum)
#	 if (len(nums) == 0):
#	 	return 0

#	 if (sum % 2 == 1):
#		 return 0
#	 halfsum = 0
#	 for idx in range(len(nums)-1):
#		 halfsum += nums[idx]
#		 if halfsum == sum/2:
#			 #print(idx, nums[idx+1:])
#			 return 1 + splitFunc(nums[idx+1:],halfsum)			 
#			 break
#	 return 0

def lSplitFunc(nums,sum):
	# Series with odd sum cannot be split
	# print(nums, sum)
	if (len(nums) == 0):
		return False, nums, sum

	if (sum % 2 == 1):
		return False, nums, sum
	halfsum = 0
	# print(len(nums)-1)
	for idx in range(len(nums)-1):
		halfsum += nums[idx]
		if halfsum == sum/2:
			#print(idx, nums[idx+1:])
			nums = nums[:idx]
			sum = halfsum
			return True, nums, sum			 
	return False, nums, sum

def rSplitFunc(nums,sum):
	# Series with odd sum cannot be split
	# print(nums, sum)
	if (len(nums) == 0):
		return False, nums, sum

	if (sum % 2 == 1):
		return False, nums, sum
	halfsum = 0
	# print(len(nums)-1)
	for idx in range(len(nums)-1):
		halfsum += nums[idx]
		if halfsum == sum/2:
			#print(idx, nums[idx+1:])
			nums = nums[idx+1:]
			sum = halfsum
			return True, nums, sum			 
	return False, nums, sum


def sumthemall(array):
	sum = 0
	for x in array:
		sum += int(x)
	return sum
		
		
	
if __name__ == '__main__':
	# sys.setrecursionlimit(10000)
	nInput =  int(sys.stdin.readline().strip())
	#print (nInput)
	for inp in range(nInput):
		lResults = 0
		retVal = True		
		length = int(sys.stdin.readline().strip())
		array  = [int(x) for x in sys.stdin.readline().split()]
		rArray =  array
		newSum = sumthemall(array)
		while retVal == True:
			retVal, array, newSum = lSplitFunc(array, newSum)
			if retVal == True: lResults += 1
			# print(lResults)
		rResults = 0
		retVal = True		
		array  = rArray
		newSum = sumthemall(array)
		while retVal == True:
			retVal, array, newSum = rSplitFunc(array, newSum)
			if retVal == True: rResults += 1
			# print(rResults)
		print(rResults if rResults > lResults else lResults)
		