Digits = [0,1,2,7]

numList = []
def genNum(curNum, numDigits):
	if numDigits == 0:
		numList.append(curNum)
		print(curNum**2)
	else:
		for digit in Digits:
			genNum(curNum*10+digit, numDigits-1)



def count7(number):
	count = 0
	while number > 0:
		if (number%10 == 7):
			count +=1
		number /= 10
	return count

def searchNum(numList):
	for X in numList:
		for Y in numList:
			for S in numList:
				if S == (pow(X,2) + pow(Y,2)) and (count7(S) +count7(X) +count7(Y) == 13):
					print (S,X,Y)

digitCount = int(input())
genNum(0,digitCount)
print(searchNum(numList))