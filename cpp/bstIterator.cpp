//============================================================================
// Name        : bstIterator.cpp
// Author      : ss
// Version     :
// Copyright   : Your copyright notice
// Description : BST iterator in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stack>
#include <cstdlib>
using namespace std;

typedef struct Node{
	Node *left, *right;
	int data;
}Node ;


Node* newNode(int data){
	Node* temp = (Node*)malloc(sizeof(Node));
	temp->data =  data;
	temp->left = temp->right = NULL;
	return temp;
}

class BSTIterator{

private:
	void pushAll(Node *root){
		Node* temp = root;
		while(temp){
			bstStack.push(temp);
			temp = temp->left;
		}
	}
public:
	stack<Node *> bstStack;

	BSTIterator(Node *root){
		pushAll(root);
	}
	bool hasNext(){
		return !bstStack.empty();
	}
	int next(){
		Node* temp =  bstStack.top();
		bstStack.pop();
		pushAll(temp->right);
		return temp->data;

	}
};

int main() {
	cout << "!!! BST ITerator  !!!" << endl; // prints !!! BST ITerator  !!!

    Node* root         = newNode(4);
    root->left        = newNode(2);
    root->right       = newNode(6);
    root->left->left  = newNode(1);
    root->left->right = newNode(3);
    root->right->left  = newNode(5);
    root->right->right = newNode(7);

  BSTIterator it(root);
  while (it.hasNext()){
	  cout << it.next() << " ";
  }
	return 0;
}
