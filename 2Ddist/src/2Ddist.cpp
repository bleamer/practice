//============================================================================
// Name        : 2Ddist.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <climits>
using namespace std;


const int R = 3;
const int C = 3;

int min(int a, int b, int c){
	if ( a < b and a < c)
		return a;
	else if(b < c) // either a > b or a > c
		return b;
	else
		return c;
}

int leastCost(int costMat[R][C], int dRow, int dCol){

//	for (int i )
//
	if(dRow > R || dCol > C)
		return INT_MAX;

	int tcMat[R+1][C+1];
	for (int i = 0; i < R+1; ++i) {
		for (int j = 0; j < C+1; ++j) {
			tcMat[i][j] = INT_MAX;
		}
	}


	tcMat[0][0] = costMat[0][0];
	for (int i = 1; i < dCol+1; ++i) {
		tcMat[0][i] = tcMat[0][i-1] + costMat[0][i];
	}
	for (int i = 1; i < dRow+1; ++i) {
		tcMat[i][0] = tcMat[i-1][0] + costMat[i][0];
	}
	for (int r = 1; r < dRow+1; ++r) {
		for (int c = 1; c < dCol+1; ++c) {
			tcMat[r][c] = min(	tcMat[r-1][c-1] + costMat[r][c],
								tcMat[r][c-1] + costMat[r][c],
								tcMat[r-1][c] + costMat[r][c]
							);
		}
	}

	return tcMat[dRow][dCol];
}

int main() {
	int costMat[R][C] = { { 1, 2, 3 },
						  { 4, 8, 2 },
						  { 1, 5, 3 } };


	cout << leastCost(costMat, 2, 2) << endl;
//	cout << "min (1,2,3) - "<< min (1,2,3) << endl;
//	cout << "min (2,1,3) - "<< min (2,1,3) << endl;
//	cout << "min (1,3,2) - "<< min (1,3,2) << endl;
//	cout << "min (3,2,1) - "<< min (3,2,1) << endl;
//	cout << "min (2,3,1) - "<< min (2,3,1) << endl;
//	cout << "min (3,1,2) - "<< min (3,1,2) << endl;
	return 0;
}
