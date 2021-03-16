#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <math.h>

void mergeSort(std::vector<int> &A, int p, int r);
void merge(std::vector<int> &A, int p, int q, int r);

int main (int argc, char* argv[]) {

	if(argc != 2) {
		printf("Wrong number of arguments\n");
		printf("usage: %s <input>\n", argv[0]);
		return 1;
	}

	std::fstream inputfile (argv[1], std::ios::in);
	if(!inputfile.is_open()) {
		printf("Could not open input file\n");
		return 1;
	}

	std::string readline;
	std::vector<int> Data;
	while(getline(inputfile, readline)) {
		Data.push_back(std::stoi(readline));
	}

	inputfile.close();

	std::cout << "Before sort:\t";
	for(int i = 0; i < Data.size(); ++i) {
		std::cout << Data[i] << ' ';
	}
	std::cout << std::endl;

	mergeSort(Data, 0, Data.size()-1);

	inputfile.open(argv[1], std::ios::out | std::ios::trunc);

	std::cout << "After sort:\t";
	for(int i = 0; i < Data.size(); ++i) {
		std::cout << Data[i] << ' ';
		inputfile << Data[i] << std::endl;
	}
	std::cout << std::endl;

	return 0;

}

void mergeSort(std::vector<int> &A, int p, int r) {

	if(p < r) {
		int q = (p+r)/2;
		mergeSort(A,p,q);
		mergeSort(A,q+1,r);
		merge(A,p,q,r);
	}

}

void merge(std::vector<int> &A, int p, int q, int r) {

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