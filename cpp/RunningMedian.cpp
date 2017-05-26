//============================================================================
// Name        : RunningMedian.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Median of running stream of numbers using heap
//============================================================================

#include <iostream>
using namespace std;

const int MAX_HEAP_SIZE = 128;

void Swap(int &a, int &b) {
	int temp = a;
	a = b;
	b = temp;
}

bool Greater(int a, int b) {
	return a > b;
}
bool Smaller(int a, int b) {
	return a < b;
}

int Avg(int a, int b) {
	return (a + b) / 2;
}

int Signum(int a, int b) {
	if (a == b)
		return 0;
	return (a < b) ? -1 : 1;
}

class Heap {
public:
	Heap(int *b, bool (*c)(int, int)) :
			data(b), compFunc(c) {
		heapSize = -1;
	}

	virtual ~Heap() {
		if (data) {
			delete[] data;
		}
	}

	virtual bool Insert(int e) = 0;
	virtual int GetTop() = 0;
	virtual int ExtractTop() = 0;
	virtual int GetCount() = 0;
protected:
	int left(int i) {
		return 2 * i + 1;
	}
	int right(int i) {
		return 2 * (i + 1);
	}
	int parent(int i) {
		if (i <= 0) {
			return -1;
		}
		return (i - 1) / 2;
	}

	int *data; // Pointer to heap array
	bool (*compFunc)(int, int); // Func pointer to Comparator function to decide compare two passed value

	int heapSize;

	int top(void) // returns top of heap data structure
			{
		int max = -1;
		if (heapSize >= 0) {
			max = data[0];
		}
		return max;
	}
	int count(void) { // Number of elements in heap
		return heapSize + 1;
	}

	void heapify(int i) {
		// run heapify from child to parent and move up towards the root
		int p = parent(i);

		if (p >= 0 && compFunc(data[i], data[p])) {
			Swap(data[i], data[p]);
			heapify(p);
		}
	}
	int deleteTop() {
		int del = -1;
		if (heapSize >= 0) {
			del = data[0]; // Mark the element to be deleted

			// Move the last element to top of heap
			// Move the top of heap to last element in the heap
			Swap(data[0], data[heapSize]);
			heapSize--; // Reduce the effective size of heap, ignoring the last element
			heapify(parent(heapSize + 1));
		}
		return del;
	}

	bool insertHelper(int key) {
		bool ret = false;
		if (heapSize < MAX_HEAP_SIZE) {
			ret = true;
			heapSize++;
			data[heapSize] = key;
		}
		return ret;
	}
};

class MaxHeap: public Heap {
public:
	MaxHeap() :
			Heap(new int[MAX_HEAP_SIZE], &Greater) {
	}
	~MaxHeap() {
	}
	;

	int GetTop() {
		return top();
	}
	int ExtractTop() {
		return deleteTop();
	}
	int GetCount() {
		return count();
	}

	bool Insert(int key) {
		return insertHelper(key);
	}

};

class MinHeap: public Heap {
public:
	// Call superclass constructor using initialization list
	MinHeap() :
			Heap(new int[MAX_HEAP_SIZE], &Smaller) {
	}
	~MinHeap() {
	}
	;
	int GetTop() {
		return top();
	}
	int ExtractTop() {
		return deleteTop();
	}
	int GetCount() {
		return count();
	}
	bool Insert(int key) {
		return insertHelper(key);
	}
};

int getMedian(int e, int &m, Heap &l, Heap &r) {
	int sig = Signum(l.GetCount(), r.GetCount());

	// if the counts for left and right heap are equal
	// then they are balanced

	switch (sig) {
	case 1: // lcount > rcount | l has more elements
	{
		if (e < m) // this element e fits in left heap
				{
			r.Insert(l.ExtractTop()); // Remove element from left heap and insert into right heap
			l.Insert(e); // insert new element to left heap
		}
		m = Avg(l.GetTop(), r.GetTop());
		break;
	}
	case 0: {
		// balanced heap
		if (e < m) { // if current element fits in left heap
			l.Insert(e);
			m = l.GetTop();
		} else { // element fits in right min heap
			r.Insert(e);
			m = r.GetTop();
		}
		break;
	}

	case -1: {
		if (e < m) // element fits in left max heap
				{
			l.Insert(e);
		} else {
			l.Insert(r.ExtractTop());
			r.Insert(e);
		}
		m = Avg(l.GetTop(), r.GetTop());
		break;
		}
	}
	return m;

}

void printMedian(int data[], int size) {
	int m = 0;
	Heap * left = new MaxHeap();
	Heap *right = new MinHeap();

	for (int i = 0; i < size; ++i) {
		m = getMedian(data[i], m, *left, *right);
		cout << m << endl;
	}

	delete left;
	delete right;
}

int main() {
	cout << "!!!Printing medians!!!" << endl; // prints !!!Hello World!!!

	int data[] = { 5, 15, 1, 3, 4, 52, 4, 33, 22, 4 };
	int size = sizeof(data) / sizeof(data[0]);

	printMedian(data, size);

	return 0;
}
