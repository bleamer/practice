import sys

def checkNice(nums):
	nice = []
	for i in range(len(nums)-1):
		print (nice, i, nums[i])
		if (nums[i] <= i-1 and nums[i] >= 0) or nums[i] == -1:
			nice.append((nums[i],i))
			print (nice)
		else:
			nice = []

	for k in range (1,len(nums)-1):
		m = [x for x in range(0, len(nums)-1, k)]
		print(k, m)




if __name__ == '__main__':
	# sys.setrecursionlimit(10000)
	nInput = int(sys.stdin.readline().strip())
	nArray = [int(x) for x in sys.stdin.readline().split()]
	# print(nInput)
	# print(nArray)
	checkNice(nArray)