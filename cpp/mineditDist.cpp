#include <iostream>
#include <string>
using namespace std;

int min(int a, int b)
{
    return (a<b ? a:b);
}

int min(int a, int b, int c)
{
    return min(a, min(b,c));
    
}

int editDistance(string s1, string s2, int lenS1, int lenS2){
    
    if (lenS1 < 1)
        return lenS2;
    if (lenS2 < 1)
        return lenS1;
    if (s1[lenS1-1] == s2 [lenS2-1])
        return editDistance(s1, s2, lenS1-1, lenS2-1);
    else
        return 1+ min ( editDistance(s1, s2, lenS1, lenS2-1), // insert something in s1
                        editDistance(s1, s2, lenS1-1, lenS2), // remove something from s1
                        editDistance(s1, s2, lenS1-1, lenS2-1)// replace something from s2
                    );
    
}

int editDistOpt(string s1, string s2, int ls1, int ls2){

	int edits[ls1+1][ls2+1];
	
	for (int i = 0; i <= ls1; i++)
	{
		for (int j=0; j <= ls2 ; j++){
			if (i == 0) // if we have s1 of len 0, then to convert to s2 we need to have j edits
				edits[i][j] = j;
			else if (j == 0)
				edits[i][j] = i;
			
			else if (s1[i-1] == s2[j-1]) // last chars match, no edit needed for this step
				edits[i][j] = edits[i-1][j-1];
			else 
				edits[i][j] = 1+min(	edits[i][j-1], // insert a char into s1 to make it upto current s2
									edits[i-1][j], // remove something from s1 to make it upto s2
									edits[i-1][j-1]); // replace something current char from s1
		} 
			
			
			
		
	}
	return edits[ls1][ls2];
}

int main(){
    cout << "Hello, World!" << endl;
    string str1, str2;
    cin >> str1;
    
    cin >> str2;
    
    
    str1 = "CATDDDDA";
    str2 = "LART";

    int lenS1 = str1.length();
    int lenS2 = str2.length();
    

    cout << editDistance (str1, str2,lenS1, lenS2)  << endl;
    cout << editDistOpt (str1, str2,lenS1, lenS2)  << endl;
    cout << str1 << endl;
    cout << str2 << endl;
    return 0;
}
