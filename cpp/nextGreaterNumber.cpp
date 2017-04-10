//============================================================================
// Name        : nextGreaterNumber.cpp
// Author      : ss
// Version     :
// Copyright   : Your copyright notice
// Description : Next Greater Number in C++, Ansi-style
//============================================================================

#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

int findNext(int data){
	int temp = data;
	int len = 0;
	int dataArr[10] = {0};
	int index = 0;
	int i = 0;

	// Extract the digits from data to dataArr array
	while(temp){
		dataArr[index] =  temp % 10;
		temp /= 10;
		len++;
		index++;
	}

	// Start from lowest index look for first pattern
	for (i = 0; i < len; ++i) {
		if (dataArr[i+1] < dataArr[i]){
			swap(&dataArr[i+1], &dataArr[i]);
			break;
		}
	}
	if(i == len-1){ // If digits are already in reverse sorted order then next number does not exist
		return data;
	}
	sort((int*)&dataArr,(int*)&dataArr[i]);
//	reverse((int*)&dataArr,(int*)&dataArr[i]);
	temp = 0;
	for (i = 0; i < len; ++i) {
		temp += pow(10,i)*dataArr[i];
//		cout << pow(10,i)*dataArr[i] << endl;

	}
	return temp;
}

int main() {
	cout << "!!! Next Greater Number  !!!" << endl; // prints !!! Next Greater Number  !!!
	int inputNumber = 119876543;
	cout << "Input Number = " << inputNumber<< endl;
	int op = findNext(inputNumber);
	if (op ==  inputNumber){
		cout << "Next number does not exist" << endl;
	}
	else
	{
		cout << "Next number is " << op << endl;
	}
	return 0;
}
