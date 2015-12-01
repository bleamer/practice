# The program tries to determine the order in which multiple
# a chain of matrices be mulliplied to have minimum number of
# multiplications



# DP approach to reduce number of count calculations

import sys

def MatrixChainOrder(p, n):
	# Not using element 0
	# m is the array used to remember the number of 
	# calculation required for i,j multiplication
	m = [[0 for x in range(n)] for x in range(n) ] 

	# m[i,j] implies the number of calculations that need to 
	# be done for multiplying  A[i]A[i+1]...A[j] = A[i..j] where
	# dimension of A[i] = p[i-1] X p[i]

	# number of multiplicationr required when multiplying 1 matrix
	for x in range(1, n):
		m[x][x] = 0

	# If Len is the length of chain of matrices
	for Len in range(2,n):
		for i in range(1, n-Len+1):
			j = i+Len-1
			m[i][j]=sys.maxint
			for k in range(i,j):

				cost =  m[i][k] + m[k+1][j]+p[i-1]*p[k]*p[j]
				if cost < m[i][j]:
					m[i][j] = cost # get mthe min cost [i...j]
	return m[1][n-1] # return the minimum cost to multiply [1...n-1]


if __name__ == '__main__':
	givenMatrices = [1,4,2,5]
	size =  len (givenMatrices)
	print ('minimum number of calculation required = '+ str(MatrixChainOrder(givenMatrices,size)) ) 