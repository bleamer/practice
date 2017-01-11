


def printLevel(size, row):
	rowFill = []
	if row < size:
		rowFill.append(range(size,row,-1))
		rowFill.append([row for x in range(row)])
		rowFill.append(range(row,size+1))
	return rowFill

def printLevelInc(size, row):
	rowFill = []
	if row < size:
		rowFill += range(size,size-row,-1)
		rowFill += [size-row for x in range(2*(size-row)-1)]
		rowFill += range(size-row+1,size+1)
	elif row > size:
		rowFill += range(size,row-size,-1)
		rowFill += [row-size for x in range(2*(row-size)-1)]
		rowFill += range(row-size+1,size+1)


	return rowFill	
def prettyprint(A):
	retArray = []
	for x in range(2*A+1):
		if x is not A and x is not (A-1):
			retArray.append(printLevelInc(A,x))

def main():
	prettyprint(10)

if __name__ == '__main__':
	main()