#include <iostream>
using namespace std;



string dictionary[] = {"mobile","samsung","sam","sung","man","mango",
                       "icecream","and","go","i","like","ice","cream"};

int dicSize = sizeof(dictionary)/sizeof(dictionary[0]);


int dictionaryHas(string word){
	for(int i = 0; i<dicSize; i++){
		if(dictionary[i].compare(word) == 0)
			return true;
	}	
	return false;
}

bool wordBreak(string inp){
	if (!inp.size()){
 		return true;
 	}
	for (int i=0; i < inp.size(); i++){
		// look for first part of the string in the dictionary and search for remaining part to be in dict
		if(dictionaryHas(inp.substr(0,i)) && wordBreak(inp.substr(i+1, inp.size()-i)))
			return true;
	}
	return false;
}

int wordBreakDP(string inp){
	int len = inp.size();
	
	bool wb[len+1]; // store the results word i can be broken in sucessfully or not
	for(int i=0;i<len+1;i++){
		wb[i]=false;
	}
	for (int i=0; i < len+1; i++){
		if(wb[i]== false && dictionaryHas( inp.substr(0,i) ) ) // if we have not checked for len i, and dictionary has word 0,i subs
			wb[i] = true;
		// Now if the first part of the string exists
		// break remaining part of the string to check things can be broken further i+1,len
		if(wb[i]){
			if(i == len) // reached end of string, 0,i exists in dictionary, hence return true
				return true;
			for(int j = i+1; j < len+1; j++){
				
				// we have not checked this inp(0,j) substring earlier and dictionary has inp(i, j-1)
				// which means dict has inp(0,i) inp (i,j-1)
				if(wb[j] == false && dictionaryHas(inp.substr(i,j-1)))
					wb[j] = true;
				// reached the end something like inp(0,i) and inp (j,len)	
				if(j == len && wb[j] == true)
					return true;
			}
		}
	}
	return false;
	
}



int main() {
	// your code goes here
	
	wordBreak("ilikesamsung")? cout <<"Yes\n": cout << "No\n";
    wordBreak("iiiiiiii")? cout <<"Yes\n": cout << "No\n";
    wordBreak("")? cout <<"Yes\n": cout << "No\n";
    wordBreak("ilikelikeimangoiii")? cout <<"Yes\n": cout << "No\n";
    wordBreak("samsungandmango")? cout <<"Yes\n": cout << "No\n";
    wordBreak("samsungandmangok")? cout <<"Yes\n": cout << "No\n";

	cout << "------------------" << endl;
	wordBreak("ilikesamsung")? cout <<"Yes\n": cout << "No\n";
    wordBreak("iiiiiiii")? cout <<"Yes\n": cout << "No\n";
    wordBreak("")? cout <<"Yes\n": cout << "No\n";
    wordBreak("ilikelikeimangoiii")? cout <<"Yes\n": cout << "No\n";
    wordBreak("samsungandmango")? cout <<"Yes\n": cout << "No\n";
    wordBreak("samsungandmangok")? cout <<"Yes\n": cout << "No\n";
    return 0;
}
