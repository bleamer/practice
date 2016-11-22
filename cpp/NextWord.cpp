//============================================================================
// Name        : test.cpp
// Author      : Saurabh
// Version     :
// Copyright   : Your copyright notice
// Description : Program to find the next permutation of a given string
//============================================================================

#include <iostream>
#include <algorithm>    // std::sort
using namespace std;


// Swap two characters
void swap(char *a, char *b){
	*a ^= *b;
	*b ^= *a;
	*a ^= *b;
}

// Reverse a section of string identified between leftIndex and RightIndex
void reverseString(string &s, int lIdx, int rIdx){
	while(lIdx < rIdx){
		swap(&s[lIdx++], &s[rIdx--]);
	}
}

// Get element to be replaced's index
int getRepIndex(string &s, int left, int right, int key){
	int index = -1;
	while (left <= right){
		int mid =  left +(right-left)/2;
		if (s[mid] <= key)	// given key greater than mid value, search left half, because we will find higher values in left, of reverse sorted string
		{
			right = mid-1;
		}					// given key lesser than mid value, search right half.
		else{
			left = mid+1;
			if (index = -1 || s[index] == s[mid])
				index = mid;
		}
	}
	return index;
}

bool NextWord(string &s){

	int len = s.length();
	int idx = len-2;
	// If the given string is reverse sorted, then there exists no next word
	while (idx >= 0){
		if (s[idx+1] > s[idx]){
			break;
		}
		--idx;
	}
	// If index is less than zero then we have traversed the whole string and it is
	// in reverse sorted order
	if (idx < 0){
		return false;
	}
	else	// String is not fully reverse sorted
	{
		// Get the index of character where the string is not reverse sorted
		int index = getRepIndex(s, idx+1, len-1, s[idx]);
		// Swap the first unsorted element, with the one just greater than itself
		swap(&s[idx],&s[index]);
		// Reverse sort the string
		reverseString(s, idx+1, len-1);
		return true;
	}
}

int main() {

	string inWord, outWord, processWord;
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	cout << "Please enter a string : ";
	cin >> inWord;
	processWord  = inWord;
//	cout << endl << inWord << endl;

	if(NextWord(inWord)){
		cout << "Nex word is: " << inWord;
	}
	else{
		cout << "No next word found";
	}
	return 0;
}
