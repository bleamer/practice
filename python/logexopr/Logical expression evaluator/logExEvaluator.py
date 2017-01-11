
''' 
	@synopsis - Entry point for Logical Expression Evaluator
	@author - Saurabh S.
'''

import sys
import json
# from pprint import pprint
from argparse import Namespace
from collections import namedtuple
import six


OPERATORS = {'EQ','AND','NOT','OR','GT','LT'}			# List of all supported operators

USER_DAT_FILE = "data.json"								# Filename for User data
OPDAT_FILE = "opdat.json"								# Filename for operation data

# Read the user data file and create named tuples allow Dot operation on python dictionary
# instead of python dictionary based access
with open(USER_DAT_FILE, 'r') as myfile:
    data=json.load(myfile, object_hook=lambda d: namedtuple('X', d.keys())(*d.values()))

# Create user object for direct reference for the data read from user data json file
user = data[0].user



# Read the operation data from file
with open(OPDAT_FILE) as dataFile:    
    opData = json.load(dataFile)


# Equals operator
# Currently assumes the arguments passed are only a list of 2
def EQ(vals):

	if len(vals) is not 2:
		print("Invalid arguments for Equals operator")
		return False

	# Recursively try to evaluate passed arguments
	val1 = execute(vals[0])
	val2 = execute(vals[1])

	# To ensure arithemetic comparison, convert strings objects to integers
	if isinstance(val1, six.string_types) and val1.isdigit(): val1 = int(val1)
	if isinstance(val2, six.string_types) and val2.isdigit(): val2 = int(val2)
	return val1 == val2

# Logical AND operator
# Currently assumes the arguments passed are is list of 2 elements
def AND(vals):
	# print("AND: ",execute(vals[0]),execute(vals[1]))
	# execute(vals[1])
	# return val1 and val2
	if len(vals) is not 2:
		print("Invalid arguments for AND operator")
		return False

	# Recursively try to evaluate passed arguments
	val1 = execute(vals[0])
	val2 = execute(vals[1])

	# To ensure arithemetic comparison, convert strings objects to integers
	if isinstance(val1, six.string_types) and val1.isdigit(): val1 = int(val1)
	if isinstance(val2, six.string_types) and val2.isdigit(): val2 = int(val2)

	return val1 and val2

# OR operator
# Currently assumes the arguments passed are is list of 2 elements
def OR (vals):
	# return val1 or val2
	if len(vals) is not 2:
		print("Invalid arguments for OR operator")
		return False

	# Recursively try to evaluate passed arguments
	val1 = execute(vals[0])
	val2 = execute(vals[1])

	# To ensure arithemetic comparison, convert strings objects to integers
	if isinstance(val1, six.string_types) and val1.isdigit(): val1 = int(val1)
	if isinstance(val2, six.string_types) and val2.isdigit(): val2 = int(val2)

	return val1 or val2

# NOT operator
# Currently assumes the arguments passed are is list of 1 element
def NOT (vals):
	if len(vals) is not 1:
		print("Invalid arguments for NOT operator")
		return False
	# Recursively try to evaluate passed arguments
	val1 = execute(vals[0])

	# To ensure arithemetic comparison, convert strings objects to integers
	if isinstance(val1, six.string_types) and val1.isdigit(): val1 = int(val1)

	return not val1

# Greater Than operator
# Currently assumes the arguments passed are is list of 2 elements
def GT(vals):

	if len(vals) is not 2:
		print("Invalid arguments for Greater Than operator")
		return False

	# Recursively try to evaluate passed arguments
	val1 = execute(vals[0])
	val2 = execute(vals[1])

	# To ensure arithemetic comparison, convert strings objects to integers
	if isinstance(val1, six.string_types) and val1.isdigit(): val1 = int(val1)
	if isinstance(val2, six.string_types) and val2.isdigit(): val2 = int(val2)

	return val1 > val2

# Less Than operator
# Currently assumes the arguments passed are is list of 2 elements
def LT(vals):
	if len(vals) is not 2:
		print("Invalid arguments for Less Than operator")
		return False

	# Recursively try to evaluate passed arguments
	val1 = execute(vals[0])
	val2 = execute(vals[1])

	# To ensure arithemetic comparison, convert strings objects to integers
	if isinstance(val1, six.string_types) and val1.isdigit(): val1 = int(val1)
	if isinstance(val2, six.string_types) and val2.isdigit(): val2 = int(val2)

	return val1 < val2


# Parser function to evaluate an expression.
# expr - Expression to evaluate
def execute(expr):
	result = None
	operation =  expr

	# If passed expression is a single element, add it to an empty list
	if type(operation) is not list: 
		operation = [str(expr)]

	# if first element is in the list of operators
	if any(operation[0] in s for s in OPERATORS):
		# Use reflection to invoke the related expression
		operand = getattr(sys.modules[__name__],str(operation[0]))
		if hasattr(operand, '__call__'):
			result = operand(operation[1:])		# invoke the function with rest of arguments
	else:										# else it is a list of argument
		try:
			operand = eval(operation[0])		# Check if argument can be evaluated, E.g. user.age
		except:
			operand = operation[0]				# If evaluation fails, then treat it as raw value
		return operand
	return result                               # return result of operand





if __name__ == '__main__':
	print(execute (opData))
