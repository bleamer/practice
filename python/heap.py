class Node:
    def __init__(self, value):
		self.value = value
		self.left = None
		self.right = None



def swap(heap, x, y):
	heap[x],heap[y] = heap[y],heap[x]


def getLeftChildAtIndex(heap,index):
	if 2*index > len(heap):
		return null
	return heap[2*index]
def getLeftChildIndex(index):
	return 2*index

def getRightChildAtIndex(heap,index):
	if (2*index + 1) > len(heap):
		return null
	return heap[2*index+1]
def getLeftChildIndex(index):
	return 2*index+1


def minHeapifyUtil(heap,index):
	if len(heap) <=0:
		return

	thisnode = heap[index]

	l = getLeftChildAtIndex(heap, index)
	if l != null and thisnode > l:
		swap(heap, index, getLeftChildIndex(index))
	
	r = getRightChildAtIndex(heap, index)
	if r != null and thisnode > r:
		swap(heap, index, getRightChildIndex(index))

def minHeapify(heap):
	# Run heapify on all elements
	for x in range(len(heap)):
		minHeapify(heap,x)
		
def insert(heap,val):
	heap = 


if __name__ == '__main__':
