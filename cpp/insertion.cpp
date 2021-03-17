#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "insertion.hpp"

void insertionSort(std::vector<int>&);

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

	insertionSort(Data);

	inputfile.open("output.txt", std::ios::out | std::ios::trunc);

	std::cout << "After sort:\t";
	for(int i = 0; i < Data.size(); ++i) {
		std::cout << Data[i] << ' ';
		inputfile << Data[i] << std::endl;
	}
	std::cout << std::endl;

	return 0;

}