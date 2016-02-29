# This program demonstrates printing in level order
# using queue implementation

# Node 
class Node:
	#constructor
	def __init__(self, key):
		self.data = key
		self.left = None
		self.right = None

# Function to print level order

def printLevelOrder(root):
	# Base Case
	if root is None:
		return

	# Create a queue for traversal
	queue = []

	# Enqueue root element
	queue.append(root)

	while len(queue) > 0:
		# Print first element of the queue and 
		# and pop it from the queue
		print queue[0].data,
		node = queue.pop(0)

		# Enqueue popped element's left child
		if node.left is not None:
			queue.append(node.left)

		# Enqueue popped element's right child
		if node.right is not None:
			queue.append(node.right)






if __name__ == '__main__':
	root = Node(1)
	root.left = Node(2)
	root.right = Node(3)
	root.left.left = Node(4)
	root.left.right = Node(5)

	print "Print level order tree"
	printLevelOrder(root)