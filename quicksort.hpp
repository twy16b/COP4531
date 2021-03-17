#ifndef QUICKSORT_H
#define QUICKSORT_H

#include <vector>

int partition(std::vector<int> &A, int p, int r) {

	int x = A[r];
	int i = p-1;

	for(int j = p; j <= r-1; ++j) {
		if(A[j] <= x) {
			++i;
			std::swap(A[i],A[j]);
		}
	}

	std::swap(A[i+1],A[r]);

	return i+1;

}

void quickSort(std::vector<int> &A, int p, int r) {

	if(p < r) {
		int q = partition(A,p,r);
		quickSort(A,p,q-1);
		quickSort(A,q+1,r);
	}

}

#endif