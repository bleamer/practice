
// The file implements solution to the following problem
// Two pairs (a, b) and (c, d) are said to be symmetric 
// if c is equal to b and a is equal to d. For example 
// (10, 20) and (20, 10) are symmetric. Given an 
// array of pairs find all symmetric pairs in it. 

#include <iostream>
#include <map>
#include <vector>


using namespace std;

#define SIZEOFARRAY  5

class SymmetricPairs {
public:
	static void findSymPairs (int arr[SIZEOFARRAY][2]);
};

void SymmetricPairs::findSymPairs(int arr[SIZEOFARRAY][2])
{
	map<int,int> hm ;							// Create a hash map
	map<int, int>::iterator itr;				// make a iterator to look for returned values in hash map
	int sizeOfArray = SIZEOFARRAY;

	for(int i = 0; i < SIZEOFARRAY;i++ )
	{
		// Get first and second elements of this pair
		int first = arr[i][0];
		int second = arr[i][1];

		// In the previous set of inserted values try to find the second value,
		// which will now be first element in a
		itr = hm.find(second);
		// If value is found itr will not be equat to end
		// check if the hash value of this pair is equal to first value of original array pair 
		if (itr != hm.end() && itr->second == first)
		{
			cout << "Found symmetric element " << second << ", " << first << endl;

		}	
		else // value not found or if found it is not symmetric to any pair
		{
			hm.insert( pair<int, int >(first, second) ) ; // insert as another pair
		}

	}
}

int main(int argc, char ** argv)
{
	int arr[SIZEOFARRAY][2];
    arr[0][0] = 11; arr[0][1] = 20;
    arr[1][0] = 30; arr[1][1] = 40;
    arr[2][0] = 5;  arr[2][1] = 10;
    arr[3][0] = 40;  arr[3][1] = 30;
    arr[4][0] = 10;  arr[4][1] = 5;
    SymmetricPairs Obj;
    Obj.findSymPairs(arr);
}