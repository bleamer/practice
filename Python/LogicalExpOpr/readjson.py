import sys
import json
import yaml
from pprint import pprint

FILE = "data.json"
OPDAT_FILE = "opdat.json"

with open(FILE) as dataFile:    
    userData = json.load(dataFile)

with open(OPDAT_FILE) as dataFile:    
    opData = json.load(dataFile)
    # opData = yaml.safe_load(dataFile)
# userData = map(lambda x: x.decode('utf-8'), userData)


# pprint(userData)
# pprint(opData)
# pprint(userData)




def EQ(val1, val2):
	print("EQ: ",str(val1),str(val2))
	return val1 == val2
	# return execute(val1) == execute(val2)


def AND(vals):
	print("AND: ",str(vals))
	execute(vals[1])
	# return val1 and val2
	# return execute(val1) and execute(val2)

def OR (vals):
	return val1 or val2
	# return execute(val1) or execute(val2)

def NOT (val):
	return not val
	# return not execute(val)

def GT(vals):
	print("GT: ",str(vals[0]),str(vals[1]))
	return execute(vals[0]) > execute(vals[1])


def execute(expr):
	result = None
	# print(expr)
	print(expr[0])
	# methodToCall = getattr(sys.modules[__name__],AND)
	operand = None
	try:
		operand = getattr(sys.modules[__name__],str(expr[0]))
	except AttributeError:
		print ("hulalalahula----->    "+str(expr))
	else:
		pass
	finally:
		print ("finally Finally!")
	print(operand,expr[1:])
	# print (methodToCall)
	if hasattr(operand, '__call__'):
		result = operand(expr[1:])
	else:
		print("found value",str(operand))
		return operand

	print (result)


execute (opData)
