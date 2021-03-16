#include <iostream>
#include <fstream>
#include <string>
#include <vector>

void countingSort(std::vector<int> &A, std::vector<int> &B, int k);

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

	std::cout << "Before sort:" << std::endl;
	for(int i = 0; i < Data.size(); ++i) {
		std::cout << Data[i] << ' ';
	}
	std::cout << std::endl;

	std::vector<int> B (Data.size(),0);
	int k = 0;
	for(int i = 0; i < Data.size(); ++i) {
		if(Data[i] > k) k = Data[i];
	}
	countingSort(Data, B, k);

	inputfile.open(argv[1], std::ios::out | std::ios::trunc);

	std::cout << "After sort:" << std::endl;
	for(int i = 0; i < Data.size(); ++i) {
		std::cout << B[i] << ' ';
		inputfile << B[i] << std::endl;
	}
	std::cout << std::endl;

	return 0;

}

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