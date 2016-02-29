# This program demonstrates printing in level order

# Node 
class Node:
	#constructor
	def __init__(self, key):
		self.data = key
		self.left = None
		self.right = None


def height(node):
	if node is None:
		return 0

	else:
		#compute the height of subtree recursively
		lheight = height(node.left)
		rheight = height(node.right)

		# Determine the larger one
		# +1 for accounting the current level
		if lheight > rheight:
			return lheight + 1
		else:
			return rheight + 1


# print all the elements at the given level
# count leafs as level 1, and higher up the order
def printLevel(root, level):
	if root is None:
		return;

	# if we a
	if level == 1:
		print "%d" %(root.data),
	elif level > 1:
		printLevel(root.left, level-1)
		printLevel(root.right, level-1)

# Print all levels
def printAllLevel(root):
	h = height(root)
	for x in xrange(1,h+1):
		printLevel(root, x)
		print

if __name__ == '__main__':
	root = Node(1)
	root.left = Node(2)
	root.right = Node(3)
	root.left.left = Node(4)
	root.left.right = Node(5)

	print "Print level order tree"
	printAllLevel(root)

	 