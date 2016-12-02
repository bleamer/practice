# The function genNum populates the list numList with all the numbers of size (0,numDigits]
# which can be constructed using the digits in the list Digits

Digits = [0,1,2,7]

numList = []
def genNum(curNum, numDigits):
	if numDigits == 0:
		numList.append(curNum)
	else:
		for digit in Digits:
			genNum(curNum*10+digit, numDigits-1)
