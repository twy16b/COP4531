#ifndef MERGE_H
#define MERGE_H

#include <vector>
#include <math.h>

void merge(std::vector<double> &A, int p, int q, int r) {

	int i, j, k;
	int n1 = q - p + 1;
	int n2 = r - q;
	int* L = new int[n1+1];
	int* R = new int[n2+1];

	for(i = 0; i < n1; ++i) {
		L[i] = A[p+i];
	}
	for(j = 0; j < n2; ++j) {
		R[j] = A[q+j+1];
	}

	L[n1] = (int) INFINITY;
	R[n2] = (int) INFINITY;
	i = 0;
	j = 0;

	for(k = p; k < r+1; ++k) {
		if(L[i] <= R[j]) {
			A[k] = L[i];
			++i;
		}
		else {
			A[k] = R[j];
			++j;
		}
	}

	delete(L);
	delete(R);

}

void mergeSort(std::vector<double> &A, int p, int r) {

	if(p < r) {
		int q = (p+r)/2;
		mergeSort(A,p,q);
		mergeSort(A,q+1,r);
		merge(A,p,q,r);
	}

}

#endif