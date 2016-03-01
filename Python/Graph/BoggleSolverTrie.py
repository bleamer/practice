#!/usr/bin/python

''' This program implements boggle solver using Trie '''
''' The code is implements the solution suggested at
	http://stackoverflow.com/questions/746082/how-to-find-list-of-possible-words-from-a-letter-matrix-boggle-solver/746102#746102 '''


NUM_ALPHABETS = 26

# Trie node definition
class TrieNode:
	def __init__(self, parent, value):
		self.parent = parent
		self.children = [None] * NUM_ALPHABETS
		self.isWord = False
		# if the node has a parent then
		# assign the passed value
		if parent is not None:
			parent.children[ord(value)-97] = self


# Make trie out of given dictionary file
def MakeTrie(dictionaryFile):
	dict = open(dictionaryFile)
	root = TrieNode(None, '')		# Set the root node
	# Iterate over all word in the dictionary files
	for word in dict:						# For all words in dictionary file
		curNode = root
		for letter in word.lower():			# for each letter in the word
			if 97 <= ord(letter) < 123:		# sanity check for letter
				nextNode = curNode.children[ord(letter) - 97] # update the nextnode pointer with the current letter
				if nextNode is None:		# if no node exits
					nextNode = TrieNode(curNode, letter) # create new node
				curNode = nextNode 			# Update the node for next iteration
		curNode.isWord = True
	return root 					# Return after trie has been created for all 		


# Find legal from dict in the grid
# grid = list NxM dimensions
# dict = Trie generate from MakeTrie function
def BoggleWords(grid, dict):
	rows, cols = len(grid), len(grid[0])	# Get dimensions of grid
	queue = []
	foundLegalWords = []					# Place holder for legal words found in the dictionary
	# Search for all possibles starting points in the grids
	for col in range(cols):					# for all columns and rows
		for row in range(rows):
			char = grid[col][row]			# get a char / letter, which will be the last char
			node = dict.children[ord(char)-97] # get the node with char from this box | node carries info from dict
			if node is not None:			# if there is a node starting with this character
				queue.append((row, col, char, node)) # queue this element for using later

	while queue:							# while we have not considered all legal words from all grid boxes as starting points
		row, col, char, node = queue[0]		# Get the info about the next element in queue
		del queue[0]						# Pop this element

		# For all possible directions of movement, between current position and next box
		for dRow, dCol in ( (1,0), (1,-1), (0,-1), (-1,-1), (-1,0), (-1,1), (0,1), (1,1) ):
			# update the next box coordinates with respect to current box
			nextRow, nextCol = row + dRow, col + dCol
			if 0 <= nextCol < cols and 0 <= nextRow < rows:	# if we are within grid
				pWord = char + grid[nextCol][nextRow]		# append the letter from grid to our probable word
				tempNode = node.children[ord(grid[nextCol][nextRow])-97]
				if tempNode is not None:					# if 
					if tempNode.isWord:
						foundLegalWords.append(pWord)
					queue.append((nextRow,nextCol,pWord, tempNode)) 
	return foundLegalWords


if __name__ == '__main__':
	dictionary = MakeTrie('words')
	print ( BoggleWords(['acbd','efgh','hijk','lmno'], dictionary) )

