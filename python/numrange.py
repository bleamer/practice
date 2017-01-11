

def numrange(A, B, C):
	start = 0
	count = 0
	end = 0
	runSum = 0
	for x in xrange(len(A)):
		runSum = A[x]
		for y in xrange(x,len(A)):
			runSum += A[y]
			if runSum >= B: 
				end = y
				break
		while runSum >= B and runSum <= C:
			count += 1
			end += 1
			runSum += A[end]


		print(A[start:x+1], runSum, count)
	return count

def main():
	print(numrange([80, 97, 78, 45, 23, 38, 38, 93, 83, 16, 91, 69, 18, 82, 60, 50, 61, 70, 15, 6, 52, 90],99,269))



if __name__ == '__main__':
	main()