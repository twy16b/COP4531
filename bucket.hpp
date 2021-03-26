#ifndef BUCKET_H
#define BUCKET_H

#include <iostream>
#include <vector>
#include <cmath>
#include "insertion.hpp"

void bucketSort(std::vector<double> &A) {

	int n = A.size();
	std::vector<std::vector<double> > B(n);
	for(int i = 0; i < B.size(); ++i) {
		B[i].clear();
	}

	for(int i = 0; i < n; ++i) {
		if(n*A[i] > n) {
			std::cout << "Sort failed. Value " << A[i] << " out of range. Must be between 0 and 1." << std::endl;
			return;
		}
		B[(int)(n*A[i])].push_back(A[i]);
	}

	for(int i = 0; i < B.size(); ++i) {
		insertionSort(B[i]);
	}

	A.clear();
	for(int i = 0; i < B.size(); ++i) {
		for(int j = 0; j < B[i].size(); ++j) {
			A.push_back(B[i][j]);
		}
	}

}

#endif