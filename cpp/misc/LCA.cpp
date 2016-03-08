// Least common ancestor

#include <iostream>

using namespace std;

struct Node 
{

	Node * left;
	Node * right;
	Node * parent;
	int value;
};



Node * newNode(int value)
{
	Node *temp = new Node;
	temp->value = value;
	temp->parent = temp->left = temp->right = NULL;
	return temp;
}

Node * insertNode(Node * node, int value)
{
	if(node == NULL)
		return newNode(value);

	if (value < node->value)
	{
		node->left = insertNode(node->left, value);
		node->left->parent = node;
	}

	if (value > node->value)
	{
		node->right = insertNode(node->right, value);
		node->right->parent = node;
	}
	return node;
}

int height(Node * node)
{
	int height = -1;
	while(node != NULL)
	{
		++height;
		node = node->parent;
	}
	return height;
}

// Find the least common ancestor node
Node * LCA(Node * node1, Node* node2)
{
	Node* n1 = node1;
	Node* n2 = node2;
	int h1 = height(n1);
	int h2 = height(n2);
	int diff = h1 - h2;

	// If node1 is lower than node2
	if(diff < 0)
	{
		Node *temp = n1;
		n1 = n2;
		n2 = temp;
	}
	// keep moving up till height difference has been nullified
	while (diff--)
	{
		n1 = n1->parent;
	}
	// Now the height n1 and n2 point to nodes at same height

	while (n1 && n2)
	{
		n1 = n1->parent;
		n2 = n2->parent;
		if (n1 == n2)
		{
			cout << "Found common ancestor";
			return n1;
		}

	}
	return NULL;
}
int main(void)
{
	Node * root = NULL;

	root = insertNode(root, 20);
	root = insertNode(root, 8);
	root = insertNode(root, 22);
	root = insertNode(root, 4);
	root = insertNode(root, 12);
	root = insertNode(root, 10);
	root = insertNode(root, 14);

	Node *n1 = root->left->right->left;
	Node *n2 = root->left;

	Node *lca = LCA(n1, n2);
	cout << endl << "LCA of " <<  n1->value << " and " << n2->value <<" is "  << lca->value << endl ;

	return 0;
}