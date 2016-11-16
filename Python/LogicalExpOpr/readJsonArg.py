import sys
import json
# import yaml
from pprint import pprint
from argparse import Namespace
import yaml
from collections import namedtuple
import six


OPERATORS = {'EQ','AND','NOT','OR','GT','LT'}

FILE = "data.json"
OPDAT_FILE = "opdat.json"

with open(FILE, 'r') as myfile:
    # data=json.load(myfile)
    
    data=json.load(myfile, object_hook=lambda d: namedtuple('X', d.keys())(*d.values()))

user = data[0].user
# print(user.age)
# n = Namespace(**data)
# # print(data.user.age,data.user.name)
# # print(n.user)

# x = json.load(data, object_hook=lambda d: namedtuple('X', d.keys())(*d.values()))
# # print x.name, x.hometown.name, x.hometown.id

# with open(FILE).read().decode('utf-8') as dataFile:    
#     data = json.loads(dataFile.read())

# # print (p.user.address)



with open(OPDAT_FILE) as dataFile:    
    opData = json.load(dataFile)
    # opData = yaml.safe_load(dataFile)
# userData = map(lambda x: x.decode('utf-8'), userData)
# pprint(userData)
# pprint(opData)
# pprint(userData)
def EQ(vals):
	# print("EQ: ",str(val1),str(val2))
	# print("EQ: ",str(vals[0]),str(vals[1]))
	# print(execute(vals[1]))
	# execute(vals[1])
	val1 = execute(vals[0])
	val2 = execute(vals[1])
	if isinstance(val1, six.string_types) and val1.isdigit(): val1 = int(val1)
	if isinstance(val2, six.string_types) and val2.isdigit(): val2 = int(val2)
	# print("EQ: ",val1, val2, val1 == val2)
	return val1 == val2
	# return execute(val1) == execute(val2)
def AND(vals):
	# print("AND: ",execute(vals[0]),execute(vals[1]))
	# execute(vals[1])
	# return val1 and val2
	val1 = execute(vals[0])
	val2 = execute(vals[1])
	if isinstance(val1, six.string_types) and val1.isdigit(): val1 = int(val1)
	if isinstance(val2, six.string_types) and val2.isdigit(): val2 = int(val2)
	return val1 and val2
def OR (vals):
	# return val1 or val2
	val1 = execute(vals[0])
	val2 = execute(vals[1])
	if isinstance(val1, six.string_types) and val1.isdigit(): val1 = int(val1)
	if isinstance(val2, six.string_types) and val2.isdigit(): val2 = int(val2)
	return val1 or val2
def NOT (vals):
	# return not val
	val1 = execute(vals[0])
	if isinstance(val1, six.string_types) and val1.isdigit(): val1 = int(val1)

	# print(execute(val1))
	return not val1
def GT(vals):
	# print("GT: ",str(vals[0]),str(vals[1]))
	# print("GT: ",execute(vals[0]),execute(vals[1]), execute(vals[0]) > execute(vals[1]))
	val1 = execute(vals[0])
	val2 = execute(vals[1])
	if isinstance(val1, six.string_types) and val1.isdigit(): val1 = int(val1)
	if isinstance(val2, six.string_types) and val2.isdigit(): val2 = int(val2)
	return val1 > val2

def LT(vals):
	# print("GT: ",str(vals[0]),str(vals[1]))
	# print("GT: ",execute(vals[0]),execute(vals[1]), execute(vals[0]) > execute(vals[1]))
	val1 = execute(vals[0])
	val2 = execute(vals[1])
	if isinstance(val1, six.string_types) and val1.isdigit(): val1 = int(val1)
	if isinstance(val2, six.string_types) and val2.isdigit(): val2 = int(val2)
	return val1 < val2

def execute(expr):
	result = None
	# print(expr)
	# print(type(expr))
	# meth\odToCall = getattr(sys.modules[__name__],AND)
	operation =  expr
	if type(operation) is not list: 
		operation = [str(expr)]
	# print(operation)
	# print(type(operation))

	# if first element is in the list of operators
	if any(operation[0] in s for s in OPERATORS):
		# print operation[0]
		# Get the operator
		operand = getattr(sys.modules[__name__],str(operation[0]))
		# print(operand,operation[1:])
	# # print (methodToCall)
		# if the function is defined
		if hasattr(operand, '__call__'):
			result = operand(operation[1:])			#invoke the function with rest of arguments
	else:										# else it must have been a value
		# print("found value",type(operation))
		# operand = getattr(sys.modules[__name__],expr)		
		try:
			operand = eval(operation[0])
		except:
			operand = operation[0]
		# print ("operand --- "+str(operand))
		return operand
	# print (result)
	return result                              # return result of operand
# print(
print(execute (opData))
