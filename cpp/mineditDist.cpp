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



int main(){
    cout << "Hello, World!" << endl;
    string str1, str2;
    cin >> str1;
    
    cin >> str2;
    
    
    str1 = "CAT";
    str2 = "LART";

    int lenS1 = str1.length();
    int lenS2 = str2.length();

    cout << editDistance (str1, str2,lenS1, lenS2);
    cout << str1 << endl;
    cout << str2 << endl;
    return 0;
}
