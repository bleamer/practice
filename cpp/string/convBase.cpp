// Write a function to convert bases of the number 
// B1 - B2 | assume 2<= B1, B2 <= 16

#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

string convertBase(const string &input, const int &b1, const int &b2)
{
	bool negativeNum = (input.front() == '-');
	int x  = 0;

	for (int i = (negativeNum ? 1 : 0) ; i < input.size(); i++)
	{
		x *= b1;
		x += isdigit(input[i]) ?   input[i]-'0'  :  tolower(input[i])-'a'+10;
	}

	string answer;
	while(x)
	{
		int r = x % b2;		// remainder
		answer.push_back(r >= 10 ? 'A'+r-10 : '0' + r); // handle for hexadecimal numbers
		x = x / b2;  
	}
	if (answer.empty())
	{
		answer.push_back('0');
	}
	if (negativeNum)
	{
		answer.push_back('-');
	}
	reverse(answer.begin(), answer.end());
	return answer;
}

int main(int argc, char const *argv[])
{
	string inp = "ABCD";
	cout << "Converting " << inp << ", base 16 to base 10 gives " << convertBase(inp, 16, 10) << endl;
	return 0;
}