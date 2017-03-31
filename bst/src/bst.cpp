//============================================================================
// Name        : bst.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;

struct Node {
	Node* right, *left;
	int data;
};

Node* newNode(int data) {
	Node* temp = new Node();
	temp->data = data;
	temp->left = temp->right = NULL;
	return temp;
}

void inOrderTraversal(Node* root) {
	if (root) {
		inOrderTraversal(root->left);
		cout << root->data << " ";
		inOrderTraversal(root->right);
	}
}

Node * insertBSTNode(Node* root, int data) {
	if (!root) {
		root = newNode(data);
		return root;
	}
	if (data < root->data) {
		root->left = insertBSTNode(root->left, data);
	} else if (data > root->data) {
		root->right = insertBSTNode(root->right, data);
	}
	return root;
}

Node * deleteBSTNode(Node* root, int key) {
	if(!root)
		return root;
	if (key < root->data) {
		deleteBSTNode(root->left, key);
	} else if (key > root->data) {
		deleteBSTNode(root->right, key);
	}
	if (root->data == key) {
		if (!root->left) {  // if left child does not exist
			Node *temp = root->right;
			delete root;
			return temp;
		} else if (!root->right) { // if right child does not exist
			Node *temp = root->left;
			delete root;
			return temp;
		} else { // else both children exist
			Node* temp = root->right;
			while (temp->left) {
				temp = temp->left;
			}
			root->data = temp->data;
			root->right = deleteBSTNode(root->right, temp->data);
		}

	}
	return root;
}

int main() {
	cout << "!!! BST !!!" << endl; // prints !!! BST !!!
    Node* root = newNode(50);
    root = insertBSTNode(root, 30);
    root = insertBSTNode(root, 20);
    root = insertBSTNode(root, 40);
    root = insertBSTNode(root, 70);
    root = insertBSTNode(root, 60);
    root = insertBSTNode(root, 80);

    printf("Inorder traversal of the given tree \n");
    inOrderTraversal(root);

    printf("\nDelete 20\n");
    root = deleteBSTNode(root, 20);
    printf("Inorder traversal of the modified tree \n");
    inOrderTraversal(root);

    printf("\nDelete 30\n");
    root = deleteBSTNode(root, 30);
    printf("Inorder traversal of the modified tree \n");
    inOrderTraversal(root);

    printf("\nDelete 50\n");
    root = deleteBSTNode(root, 50);
    printf("Inorder traversal of the modified tree \n");
    inOrderTraversal(root);
	return 0;
}
