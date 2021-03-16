#include <iostream>
#include <fstream>
#include <string>
#include <vector>

void quickSort(std::vector<int> &A, int p, int r);
int partition(std::vector<int> &A, int p, int r);

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

	quickSort(Data, 0, Data.size()-1);

	inputfile.open(argv[1], std::ios::out | std::ios::trunc);

	std::cout << "After sort:" << std::endl;
	for(int i = 0; i < Data.size(); ++i) {
		std::cout << Data[i] << ' ';
		inputfile << Data[i] << std::endl;
	}
	std::cout << std::endl;

	return 0;

}

void quickSort(std::vector<int> &A, int p, int r) {

	if(p < r) {
		int q = partition(A,p,r);
		quickSort(A,p,q-1);
		quickSort(A,q+1,r);
	}

}

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