//============================================================================
// Name        : remote.cpp
// Author      : ss
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cstdlib>
using namespace std;

unsigned int channel = 99;

void refreshChannelDisplay(){
	cout << "\x1b[A";
	cout << "\x1b[A";
	cout << "\x1b[A";
	cout << endl << "Channel : " << channel << endl;
}

int main() {
//	cout << "!!! Hello World !!!" << endl; // prints !!! Hello World !!!

	refreshChannelDisplay();
	system("clear");
	char inVal;
	while(1){
		switch(inVal){
		case '+':
			channel++;
			refreshChannelDisplay();
			break;
		case '-':
			channel--;
			refreshChannelDisplay();
			break;
		default:
			cout << "\x1b[A";
			cout << "\x1b[A";
			refreshChannelDisplay();
		}
		cout << "next operation : ";
		cin >> inVal;
//		cout << endl;

	}
	return 0;

}
