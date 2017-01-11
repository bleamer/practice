#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

vector<long long> numList;
vector<long long> numSqList; // Vector to store square of numbers
vector<long long> SList; // Vector to possible values of S
vector<int> num7CntList; // Vector to store 7 count of numbers
vector<int> numSq7CntList; // Vector to 7 count of square of numbers
vector<int> num7SCntList; // Vector to 7 count of numbers in SList
char Digit[] = {0,1,2,7};

int count7(long long number){
	int count = 0;
	while(number > 0){
		if (number%10 == 7)
			count++;
		number /= 10;
	}
	return count;
}


void genNum(long long curNum, int numDigits){
	if(numDigits == 0){
		numList.push_back(curNum);
		numSqList.push_back(pow(curNum,2));
		num7CntList.push_back(count7(curNum));
		numSq7CntList.push_back(count7(pow(curNum,2)));
		if(!(curNum%10 == 7)){
			SList.push_back(curNum);
		}
	}
	else{
		for (int i = 0; i < sizeof(Digit)/sizeof(Digit[0]);i++){
			genNum(curNum*10+Digit[i], numDigits-1);
		}
	}
}



void searchNum(vector<long long> sqLst, vector<long long> Lst,
	vector<int> Lst7,vector<int> LstSq7,
	vector<long long> sLst){
	for(vector<long long>::size_type x = 0; x != numSqList.size(); ++x) {
		for(vector<long long>::size_type y = 0; y != numSqList.size(); ++y) {
			if(binary_search(sLst.begin(), sLst.end(), sqLst[x]+sqLst[y]))
			{
				// cout <<  count7(Lst[x] + Lst[y]) << ", " << Lst7[x]<< ", " <<  Lst7[y] << ", " << sqLst[x] << ", " << sqLst[y] << ", " <<  sqLst[x] + sqLst[y] << endl; 	
				if( ( count7(sqLst[x] + sqLst[y]) + LstSq7[x] + LstSq7[y] ) >= 13)
					cout << Lst[x] << ", " << Lst[y] << endl; 							
			}
		} 	
	}
}


int main(int argc, char const *argv[])
{
	int digitCount;
	cin >> digitCount;
	genNum(0,digitCount);
	searchNum(numSqList, numList,num7CntList,numSq7CntList,SList);
	// for(vector<long long>::size_type i = 0; i != numSqList.size(); ++i) {
	//     cout << numSqList[i] << endl;
	// }

	return 0;
}