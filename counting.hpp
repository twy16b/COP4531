#ifndef COUNTING_H
#define COUNTING_H

#include <vector>

void countingSort(std::vector<int> &A, std::vector<int> &B, int k) {

	std::vector<int> C (k+1,0);

	for(int j = 0; j < A.size(); ++j) {
		++C[A[j]];
	}

	for(int i = 1; i < k+1; ++i) {
		C[i] += C[i-1];
	}

	for(int j = A.size()-1; j >= 0; --j) {
		B[C[A[j]]-1] = A[j];
		--C[A[j]];
	}

}

#endif