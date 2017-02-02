//============================================================================
// Name        : ClosestDist.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cfloat>
#include <cmath>
#include <algorithm>
#include <limits>
#include <cstddef>
using namespace std;

typedef struct Point {
	int x;
	int y;
} Point;

int compareX(const void *a, const void *b) {
	Point *p1 = (Point *) a;
	Point *p2 = (Point *) b;
	return (p1->x - p2->x);
}

int compareY(const void *a, const void *b) {
	Point *p1 = (Point *) a;
	Point *p2 = (Point *) b;
	return (p1->y - p2->y);
}

float dist(Point p1, Point p2) {
	return sqrt((p1.x - p2.x) ^ 2 + (p1.x - p2.y) ^ 2);
}

float min(float a, float b) {
	// Improve later with epsilon
	return (a < b ? a : b);
}

// Find closest points in strip of having num elements, points sorted according
// to their y coordinates, the points must not be farther than
// distance maxDist, which would have been obtained after recursively
// searching for minimum x distance between pair of points
float stripClosest(Point strip[], int num, float maxDist) {
	float min = maxDist;

	// sort elements of array strip, having num element
	// using compareY as the comparator function
	qsort(strip, num, sizeof(Point), compareY);

	// For each successive pair of points, find the
	// the minimum distance
	for (int i = 0; i < num; i++) {
		for (int j = i + 1; (j < num) && (strip[j].y - strip[i].y < min); ++j) {
			if (dist(strip[i], strip[j]) < min) {
				min = dist(strip[i], strip[j]);
			}
		}
	}
	return min;
}

float bruteForce(Point P[], int n) {
	float min = FLT_MAX;
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			if (dist(P[i], P[j]) < min)
				min = dist(P[i], P[j]);
		}
	}
	return min;

}

// Recursively find closest points ,
// Px contain points sorted by x dist and Py contains
// points sorted by y dist
float ClosestDistUtil(Point P[], int n) {
	if (n < 3) {
		return bruteForce(P, n);
	}

	// Divide the given Point X array by two
	// find the middle point
	int mid = n / 2;
	Point midPoint = P[mid];

	// Imagine a line passing through the mid point and find
	// the distance between the smallest distance between first
	// left and the first right point

	// Recursively find the closest distance
	float dl = ClosestDistUtil(P, mid);
	float dr = ClosestDistUtil(P + mid, n - mid);

	// Minium of the two distances
	float d = min(dl, dr);

	// strip is an array of points closer than min dist
	Point strip[n];
	int j;
	for (int i = 0; i < n; ++i) {
		if (abs(P[i].x - midPoint.x) < d) {
			strip[j] = P[i];
			j++;
		}
	}
	// find closest point in the strip
	return min(d, stripClosest(strip, j, d));

}

float ClosestDist(Point points[], int n) {
	qsort(points, n, sizeof(Point), compareX);
	return ClosestDistUtil(points, n);
}

int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	Point P[] = { { 2, 3 }, { 12, 30 }, { 40, 50 }, { 5, 1 }, { 12, 10 },
			{ 3, 4 } };
	int n = sizeof(P) / sizeof(P[0]);
	cout << "The smallest distance is " << ClosestDist(P, n);
	return 0;
}
