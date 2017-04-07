//============================================================================
// Name        : NutsNBolts.cpp
// Author      : ss
// Version     :
// Copyright   : Your copyright notice
// Description : Nuts and Bolts problem implementation
//============================================================================

#include <iostream>
using namespace std;

void swap(int *x, int *y){
	int temp = *x;
	*x = *y;
	*y = temp;
}

int partition (int arr[], int low, int high, int pivot){
	int i = low;
	for (int j = low; j < high; ++j) {
		if(arr[j] < pivot){
			swap(&arr[i], &arr[j]);
			i++;
		} else if(arr[j] == pivot){
			swap(&arr[high], &arr[j]);
			j--;
		}
	}
	swap(&arr[high],&arr[i]);
	return i;
}

void matchNutsNBoltsUtil(int nuts[], int bolts[], int low, int high){

	if (low < high){

		int pivot = partition(nuts, low, high, bolts[high]); // partition nuts array based on last value from "bolts"

		// Partition bolts on the partition returned from nuts
		partition(bolts, low, high, nuts[pivot]);

		// Recursively run this for both sides of pivot
		matchNutsNBoltsUtil(nuts, bolts, low, pivot-1);
		matchNutsNBoltsUtil(nuts, bolts, pivot+1, high);
	}
}

void matchNutsNBolts(int nuts[], int bolts[], int size){

	matchNutsNBoltsUtil(nuts, bolts, 0, size-1);

}

void printArr(int arr[], int size){
	for (int i = 0; i < size; ++i) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

int main() {
	cout << "!!! Nuts and Bolts  !!!" << endl; // prints !!! BST  !!!

	int nuts[] = {5,6,9,3,4,2,1,8};
	int bolts[] = {5,6,9,3,4,2,1,8};

	int size = sizeof(nuts)/sizeof(nuts[0]);

	cout << "unmatched nuts and bolts:" << endl;
	printArr(nuts, size);
	printArr(bolts, size);
	matchNutsNBolts(nuts, bolts, size);

	cout << "Matched nuts and bolts:" << endl;
	printArr(nuts, size);
	printArr(bolts, size);

	return 0;
}
