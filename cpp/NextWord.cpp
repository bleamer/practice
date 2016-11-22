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

string NextWord(string &s){
	string rSorted = s;
	string retStr = string();
	cout << "NextWord : " << s << endl;
	sort(rSorted.begin(), rSorted.end(),greater<char>()); // Reverse sort
	if (rSorted == s){
		cout << "Already reverse sorted" << endl;
		retStr = rSorted;
//		Return empty string
	}
	else{
		cout << "Not sorted" << endl ;
		retStr = s.substr(1);
		if (retStr == NextWord(retStr)){
			// Passed string is same as returned string
			// No reversal happened
			rSorted = retStr;
			sort(rSorted.begin(), rSorted.end()); // sort
			cout << "rsorted == " << rSorted << endl;
			for (int i = 0; i < rSorted.length(); i++){
				if (s.at(0) < rSorted.at(i)){
					char temp = rSorted[i];
					rSorted[i] = s[0];
					s[0] = temp;
					sort(s.begin(), s.end()); // sort
					cout << "dadadada -- "<< s.at(0) << ", "<< rSorted.at(i) << endl;
					retStr = s;
					break;
				}
			}
		}
	}

	return retStr;
//	return s;
}

int main() {

	string inWord, outWord, processWord;
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	cout << "Please enter a string : ";
	cin >> inWord;
	processWord  = inWord;
//	cout << endl << inWord << endl;

	try {
		outWord = NextWord(processWord);
//		cout << endl << "The next word is : " << outWord;
	}
	catch (const std::exception &exc)
	{
	    // catch anything thrown within try block that derives from std::exception
	    std::cout << endl << exc.what();
    	cout << endl << "The given word is the last word in the dictionary";
		return 0;
	}
    if (outWord == inWord){
    	cout << endl << "The given word is the last word in the dictionary";
    }else{
    	cout << "The next word is: " << outWord << endl;
    }
	return 0;
}
