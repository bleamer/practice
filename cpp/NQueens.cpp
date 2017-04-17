//============================================================================
// Name        : NQueens.cpp
// Author      : ss
// Version     :
// Copyright   : Your copyright notice
// Description : Solution to NQueens placement on a board of N x N board
//============================================================================

#include <cstring>
#include <iostream>

using namespace std;

bool isSafe(int ** board, int row, int col, int N){
	int i,j;

	for (i = 0; i < N; ++i) {
		if(board[row][i]){
			return false;
		}
	}

	for (i = row, j= col ; i >= 0 && j >= 0; --i, --j) {
		if(board[i][j]){
			return false;
		}
	}
	for (i = row, j= col ; j >= 0 && i < N; ++i, --j) {
		if(board[i][j]){
			return false;
		}
	}
	return true;
}
void PrintSolution(int ** board, int N){
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cout << board[i][j] << " ";
		}
		cout << endl;
	}
}

bool NQueenSolUtil(int **board, int col, int N) {
	if(col >= N){ // We are past checking the last column, so by now all queens have been placed
		return true;
	}

	for (int i = 0; i < N; ++i) {
		if(isSafe(board, i , col, N)){
			board[i][col] = 1;

			if(NQueenSolUtil(board, col+1, N)){ // Recursively try for all columns
				return true;
			}
			// We did not return, and thus did not have a solution at this point
			// Go back / backtrack
			board[i][col] = 0;
		}

	}
	return false;
}

bool NQueensSol(int N) {

	int **board = new int*[N];
	for (int i = 0; i < N; ++i) {
		board[i] = new int[N];
	}
//	int *board = new int[N*N];
//	memset(board, 0, N*N*sizeof(int) );
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			board[i][j] = 0;
		}
	}

	PrintSolution(board, N);
//
	if (!NQueenSolUtil(board, 0, N)){

		cout << "No Solutions found" << endl;
	}
	else{
		cout << "The solution is :" << endl;
	}
	PrintSolution(board, N);

	return true;
}


int main() {
	cout << "!!! NQueens  !!!" << endl; // prints !!! Topological sort  !!!

	int N = 4;

	NQueensSol(N);
	return 0;
}
