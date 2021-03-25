#ifndef INSERTION_H
#define INSERTION_H

#include <vector>

void insertionSort(std::vector<double> &A) {

	int i, j;
	double key;
	for(j = 1; j < A.size(); ++j) {
		key = A[j];
		i = j - 1;
		while(i >= 0 && A[i] > key) {
			A[i+1] = A[i];
			--i;
		}
		A[i+1] = key;
	}
	
}

#endif