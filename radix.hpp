#ifndef RADIX_H
#define RADIX_H

#include <iostream>
#include <vector>
#include <cmath>

int getDigit(int num, int place) {
	return (int) (num / pow(10,place-1)) % 10;
}

void radixSort(std::vector<double> &A, int d) {

	int x, i, j, key;
	for(x = 1; x <= d; ++x) {
		for(j = 1; j < A.size(); ++j) {
			key = A[j];
			i = j - 1;
			while(i >= 0 && getDigit(A[i],x) > getDigit(key,x)) {
				A[i+1] = A[i];
				--i;
			}
			A[i+1] = key;
		}
	}

}

#endif