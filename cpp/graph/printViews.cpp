//============================================================================
// Name        : trrghtview.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <queue>
using namespace std;

struct Node {
	Node * lChild;
	Node * rChild;
	int data;
	Node(int val) {
		this->lChild = NULL;
		this->rChild = NULL;
		data = val;
	}
};

int getTreeHeight(Node * root){
	if (!root)
		return 0;
	return (1 + max(getTreeHeight(root->lChild),getTreeHeight(root->rChild)));
}

void PrintBottomView(Node * root) {
	if (!root)
		return;
	if (root->lChild)
		PrintBottomView(root->lChild);
	cout << root->data << " ";
	if (root->rChild)
		PrintBottomView(root->rChild);
}

// Does level order traversal and prints the tree level wise
void PrintTree(Node * root) {
	queue<Node *> q;

	Node * poppedNode = NULL;
	q.push(root);
	while ((poppedNode = q.front())) {
		q.pop();
		if (poppedNode) {
			cout << poppedNode->data << " ";
			if (poppedNode->lChild)
				q.push(poppedNode->lChild);
			if (poppedNode->rChild)
				q.push(poppedNode->rChild);
		}
	}
}



void printLevel(Node * root, int level){
	// If root node is null or the given level is more than
	// height of the tree, Do nothing
	if (!root || level > getTreeHeight(root)){
		return;
	}
	if (level == 1){
		cout << root->data << " ";
	}
	else if(level > 1){
		printLevel(root->lChild, level-1);
		printLevel(root->rChild, level-1);
	}
}

void printLevelOrder(Node * root){
	int ht  =  getTreeHeight(root);
	for (int i = 0; i <= ht; i++){
		printLevel(root, i);
		cout << endl;
	}
}

int max(int a, int b){
	return (a > b ? a : b);
}

void printRightViewLevel(Node *root, int level){
	int ht = getTreeHeight(root);
	if (!root || level > getTreeHeight(root)){
		return;
	}
	if (level == 1){
		cout << root->data << endl;
	}
	else if (level > 1){


	}
}


int main() {
	cout << "!!! Hello World !!!" << endl; // prints !!! Hello World !!!
	Node * root = new Node(1);
	root->lChild = new Node(2);
	root->rChild = new Node(3);
	root->lChild->lChild = new Node(4);
	root->lChild->rChild = new Node(5);
	root->rChild->lChild = new Node(6);
	root->rChild->rChild = new Node(7);
	root->lChild->lChild->rChild = new Node(10);
	root->lChild->rChild->rChild = new Node(14);

	cout << "Height = "<< getTreeHeight(root) << endl;
	PrintTree(root);
	cout << endl;
	PrintBottomView(root);
	cout << "Printing level order" << endl;
	printLevelOrder(root);

	cout << "Printing Right view" << endl;
	printRightView(root);
	return 0;
}
