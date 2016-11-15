import sys
import json
# import yaml
from pprint import pprint
from argparse import Namespace
import yaml
from collections import namedtuple



OPERATORS = {'EQ','AND','NOT','OR','GT','LT'}

FILE = "data.json"
OPDAT_FILE = "opdat.json"

with open(FILE, 'r') as myfile:
    # data=json.load(myfile)
    
    data=json.load(myfile, object_hook=lambda d: namedtuple('X', d.keys())(*d.values()))

user = data.user
print(data)
# n = Namespace(**data)
print(user.age,user.name)
# print(n.user)

# x = json.load(data, object_hook=lambda d: namedtuple('X', d.keys())(*d.values()))
# print x.name, x.hometown.name, x.hometown.id

# with open(FILE).read().decode('utf-8') as dataFile:    
#     data = json.loads(dataFile.read())

# print (p.user.address)

'''with open(OPDAT_FILE) as dataFile:    
    opData = json.load(dataFile)
    # opData = yaml.safe_load(dataFile)
# userData = map(lambda x: x.decode('utf-8'), userData)





pprint(userData)
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
	# meth\odToCall = getattr(sys.modules[__name__],AND)
	
	# if first element is in the list of operators
	if any(expr[0] in s for s in OPERATORS):
		print expr[0]
		# Get the operator
		operand = getattr(sys.modules[__name__],str(expr[0]))
		print(operand,expr[1:])
	# print (methodToCall)
		# if the function is defined
		if hasattr(operand, '__call__'):
			result = operand(expr[1:])			#invoke the function with rest of arguments
	else:										# else it must have been a value
		print("found value",str(expr))
		operand = getattr(sys.modules[__name__],str(expr))		
		print ("operand --- "+operand)
		return operand

	print (result)
	return result                              # return result of operand

execute (opData)
'''