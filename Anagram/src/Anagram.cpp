//============================================================================
// Name        : Anagram.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cstdio>
using namespace std;

typedef struct {
	char *str;
	int index;
}Word;

typedef struct Duplicates{
	Word * array;
	int size;
}Duplicates;

Duplicates* createDuplicates(char * str[], int size){
	Duplicates* dup =  (Duplicates *) malloc (sizeof(Duplicates));
	dup->size = size;
	dup->array = (Word*)malloc(sizeof(Word));

	for (int i =0; i < size; ++i){
		dup->array[i].index = i;
		dup->array[i].str = (char*)malloc(strlen(str[i])+1);
		strcpy(dup->array[i].str, str[i]);
	}
	return dup;
}

int compareChar(const void *a, const void *b){
	return *(char*)a-*(char*)b;
}

int compareStr(const void *a, const void*b){
	Word * a1 = (Word*) a;
	Word * b1 = (Word*) b;
	return strcmp(a1->str, b1->str);
}

void printAnagrams(char* wordList[], int size){
	Duplicates* dups = createDuplicates(wordList, size);

	int i;
	for(i=0; i < size; ++i){
		qsort((void *)dups->array[i].str,
				(int)strlen(dups->array[i].str),sizeof(char), compareChar);
	}
    qsort(dups->array, size, sizeof(dups->array[0]), compareStr);

    for (i = 0; i < size; ++i) {
		printf("%s",wordList[dups->array[i].index]);
	}
}

int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
    char* wordArr[] = {"cat", "dog", "tac", "god", "act"};
    int size = sizeof(wordArr) / sizeof(wordArr[0]);
    printAnagrams(wordArr, size);

	return 0;
}
