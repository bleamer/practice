//============================================================================
// Name        : ksmallest.cpp
// Author      : ss
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;


int swap(int *a, int *b){
	int temp = *a;
	*a= *b;
	*b = temp;
}


//void printArray(int arr[], int size){
////	int n = sizeof(arr)/sizeof(arr[0]);
//	for (int i = 0; i < size; i++){
//		cout << arr[i] << ", ";
//	}
//	cout << endl;
//}

// Assume pivot is the right most element
// and swap numbers if they are less that or greater than that
int partition(int arr[], int l, int r){
	int x = arr[r], i = l;
	for(int j = l; j <= r-1 ; j++){
		if (arr[j] <= x){
			swap(&arr[i], &arr[j]);
			i++;
		}
	}
//	printArray(array, r);
	swap(&arr[i], &arr[r]);
//	printArray(array, r);
	return i ;
}

int ksmallest(int arr[], int l , int r, int k)
{
	// if k is smaller than the number of elements in the array
	if (k > 0&& k <= r-l+1){
		// Partition the element around the last element and get
		// position of pivot element in sorted array
		int pos = partition(arr, l, r);

		// if position of pivot element is same as k
		// return its value
		if (pos-l == k-1)
			return arr[k-1];

		// if position of the pivot is greater than k, search more to the left
		// pivot element is lesser than kth smallest element
		if (pos-l > k-1){
			return ksmallest(arr, l, pos-1, k);
		}
		else{ // position of pivot is lesser than k / pivot element is larger than kth smallest element
			return ksmallest(arr, pos+1, r, k-pos+l-1);
		}
	}
}
int main() {
	int array[] = {1, 12, 3, 5, 7, 4, 19, 26, 14};
	int n = sizeof(array)/sizeof(array[0]);
//	partition(array, 0,n-1);
	int k = 2;
	cout << "In the array : " << endl;
//	printArray(array, n);
	cout << k << " smallest element is " << ksmallest(array, 0, n-1, k) << endl;
	return 0;
}
