// Inorder traversal of binary search tree without queue/stacks

#include <iostream>
using namespace std;

typedef struct Node
{
	int data;
	Node *left;
	Node *right;
	Node *parent;
	bool visited;
}Node;

// Function to create new node
Node * NewNode(int key)
{
	Node * newNode = new Node;
	newNode->left = newNode->right = newNode->parent = NULL;
	newNode->data = key;
	return newNode;
}

// Function to insert new node in BST
Node * insert(Node * curNode, int data)
{
	// If starting a new tree, just return the first element
	if ( curNode == NULL )
		return NewNode(data);
	
	if (data < curNode->data )
	{
		curNode->left = insert(curNode->left, data);
		curNode->left->parent = curNode;
	}	
	else if (data > curNode->data )
	{
		curNode->right = insert(curNode->right, data);
		curNode->right->parent = curNode;
	}	
	return curNode; // return this because insert may have provide new node
}

// In order traversal
void inOrder(Node * root)
{
	bool visitedLeft = false;
	while(root != NULL)
	{
		if (!visitedLeft)
		{
			while(root->left != NULL)
				root = root->left;
			// reached left most leaf
		}
		// Print left most leaf
		cout << root->data << ", ";

		// Mark left visited as true
		visitedLeft = true;
	
		if (root->right != NULL)
		{
			visitedLeft = false;
			root = root->right;
		}
		else if (root->parent != NULL) 
		{		// right child does not exist	
			while (root->parent && root == root->parent->right)
			{
				root = root->parent;
			}
			if (root->parent == NULL)
				break;
			root= root->parent; 

		}
		else
			break;


	}	
}

int main(int argc, char ** argv)
{

    Node * root = NULL;
 
    root = insert(root, 24);
    root = insert(root, 27);
    root = insert(root, 29);
    root = insert(root, 34);
    root = insert(root, 14);
    root = insert(root, 4);
    root = insert(root, 10);
    root = insert(root, 22);
    root = insert(root, 13);
    root = insert(root, 3);
    root = insert(root, 2);
    root = insert(root, 6);
 
    cout << "Inorder traversal is \n";
    inOrder(root);
 
    return 0;
	
}
