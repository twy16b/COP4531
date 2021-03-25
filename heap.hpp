#ifndef HEAP_H
#define HEAP_H

#include <vector>

int Parent(int i) { return (i-1)/2; }
int Left(int i) { return 2*i + 1; }
int Right(int i) { return 2*i + 2; }

struct Heap {

	std::vector<double> array;
	int heapSize;

	Heap(std::vector<double> &A) { array = A; heapSize = 0; }

	int size() { return array.size(); }

	int operator[](int i) { return array[i]; }

};

void maxHeapify(Heap &A, int i) {
	int largest = 0;
	int l = Left(i);
	int r = Right(i);

	if (l < A.heapSize && A[l] > A[i]) {
		largest = l;
	}
	else largest = i;

	if (r < A.heapSize && A[r] > A[largest]) {
		largest = r;
	}

	if (largest != i) {
		std::swap(A.array[i], A.array[largest]);
		maxHeapify(A, largest);
	}
}

void buildMaxHeap(Heap &A) {
	A.heapSize = A.size();
	for(int i = A.size()/2; i >= 0; --i) {
		maxHeapify(A,i);
	}
}

void heapSort(Heap &A) {
	buildMaxHeap(A);
	for(int i = A.size()-1; i > 0; --i) {
		std::swap(A.array[0],A.array[i]);
		--A.heapSize;
		maxHeapify(A,0);
	}
}

#endif