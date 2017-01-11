//============================================================================
// Name        : llbbst.cpp
// Author      : ss
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class LLNode{
public:
	int data;
	LLNode * next;

	LLNode(){
		this->data = 0;
		this->next = NULL;
	}
	LLNode(int val){
		this->data = val;
		this->next = NULL;
	}
};

void addNode(LLNode ** root, int val){
	 LLNode * newNode = new LLNode(val);
	 *root->next = newNode;
	 root =  root->next;
}

class BSTNode{
public:
	int data;
	BSTNode * left;
	BSTNode * right;
	BSTNode(){
		this->data = 0;
		this->left = NULL;
		this->right = NULL;

	}
	BSTNode(int val){
		this->data = val;
		this->left = NULL;
		this->right = NULL;
	}
};

int countNodes(LLNode * root){
	int count = 0;
	LLNode *node = root;
	while (node != NULL){
		count++;
		node = node->next;
	}
	return count;
}


BSTNode * sortedLLToBBST(LLNode * root, int start, int end){
	if (start > end) return NULL;

	int mid = start + (end-start)/2;

	BSTNode *left = sortedLLToBBST(root, start, mid-1);
	BSTNode *parent = new BSTNode(root->data);
	BSTNode *right = sortedLLToBBST(root->next, mid, end);
	parent->left = left;
	parent->right = right;
	return parent;
}
int main() {
	cout << "!!! Sorted Linked list to Balanced Binary Search Tree !!!" << endl; // prints !!! Sorted Linked list to Balanced Binary Search Tree !!!

	LLNode * LList = new LLNode(1);
	addNode(&LList, 2);
	addNode(&LList, 3);
	addNode(&LList, 4);
	addNode(&LList, 5);
	addNode(&LList, 6);
	addNode(&LList, 7);
	addNode(&LList, 8);
	addNode(&LList, 9);
	addNode(&LList, 10);

	int numLLNodes = countNodes(LList);
	cout << numLLNodes << endl;


	return 0;
}
