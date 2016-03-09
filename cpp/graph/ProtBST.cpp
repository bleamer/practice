
// Check if a given array can represent Preorder Traversal of Binary Search Tree
// Given an array of numbers, return true if given array can represent preorder traversal of a Binary Search Tree, else return false. Expected time complexity is O(n).

#include <iostream>
#include <stack>
#include <climits>
using namespace std;

int pre[]= {40, 30, 35, 80, 100};

struct Node {
	Node * right, *left;
	int value;
};

// pre : array containing elements to be check for preorder
// n : no. of elements
bool isBSTProt(int pre[], int n)
{
	// empty stack of int
	stack<int> s;

	int root = INT_MIN;
	for (int i = 0; i < n; ++i)
	{
		// if we find a node who is on the right side
		// smaller than the root, return false
		if(pre[i] < root)
			return false;

		// if pre[i] is in the right subtree of stack top
		// keep removing items smaller than pre[i] because they
		// can fit in the left of pre[i] and
		// make the last item as root

		while (!s.empty() && s.top() < pre[i])
		{
			root = s.top();
			s.pop();
		}

		// stack is either empty or top of stack is smaller than root
		s.push(pre[i]);
	}

}


int main(void)
{
	isBSTProt( pre, sizeof(pre)/sizeof(pre[0]) ) ? cout << "Yay!\n" : cout << "Noo\n";
	return 0;
}