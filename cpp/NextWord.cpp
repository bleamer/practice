//============================================================================
// Name        : test.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <algorithm>    // std::sort
using namespace std;

string& NextWord(string &s){
	string rSorted = s;
	string retStr = string();
	cout << "NextWord : " << s << endl;
	sort(rSorted.begin(), rSorted.end(),greater<char>()); // Reverse sort
	if (rSorted == s){
		cout << "Already reverse sorted" << endl;
//		Return empty string
	}
	else{
		cout << "Not sorted" << endl ;
		retStr = s.substr(1);
		if (retStr == NextWord(retStr)){
			// Passed string is same as returned string
			// No reversal happened
			rSorted = retStr;
			sort(rSorted.begin(), rSorted.end(),greater<char>()); // Reverse sort
			
		}
	}

	return retStr;
//	return s;
}

int main() {

	string inWord, outWord;
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	cout << "Please enter a string : ";
	cin >> inWord;

//	cout << endl << inWord << endl;

	try {
		outWord = NextWord(inWord);
//		cout << endl << "The next word is : " << outWord;
	}
	catch (const std::exception &exc)
	{
	    // catch anything thrown within try block that derives from std::exception
	    std::cout << endl << exc.what();
		cout << endl << "The given word is the last word in the dictionary";
	}
	return 0;
}
