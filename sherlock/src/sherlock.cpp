#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int max(int a, int b){
	return (a>b?a:b);
}
int min(int a, int b){
	return (a<b?a:b);
}

int main() {
	/* Enter your code here. Read input from STDIN. Print output to STDOUT */
	int T, N;
	vector<int> B;
	cin >> T;
	for(int j = 0 ; j < T ; j++){
		cin >> N;
		int inVal;
		for (int i = 0; i<N; i++){
			cin >> inVal;
			B.push_back(inVal);
		}
		vector<int> Max(B.size()+1,0);
		vector<int> Min(B.size()+1,0);


		vector<int> A = B;
		long int S = 0;
		for (uint i = 1;i < B.size(); ++i){

			//			Min[i] = Max[i-1] + 1;
			Max[0] = B[0];
			Min[0] = 1;



			Max[i] = Max[i-1] + B[i];
			 if ( (S + abs(B[i] - B[i-1]))  > (S + abs(1 - B[i-1])))
			 {
				 S += abs(B[i] - B[i-1]);
			 }else{
				 S += abs(1 - B[i-1]);
			 }

		}
		cout << S << endl;
//		for (uint i = 0;i < A.size(); ++i){
//			cout << A[i] << " ";
//		}
//		cout << endl;

//		for (uint i = 1;i < A.size(); ++i){
//			S += abs(A[i] - A[i-1]);
//		}
		cout << S << endl ;
	}

	return 0;
}
