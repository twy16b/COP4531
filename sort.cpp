#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>
#include "insertion.hpp"
#include "merge.hpp"
#include "heap.hpp"
#include "quicksort.hpp"
#include "counting.hpp"
#include "radix.hpp"
#include "bucket.hpp"

int main (int argc, char* argv[]) {

	std::string inputfilename;
	std::string outputfilename;
	int sortType;
	std::fstream filestream;
	std::string readline;
	std::vector<int> Array;

	if(argc != 4) {
		printf("Invalid arguments\n");
		printf("usage: %s <input> <output> <sort>\n", argv[0]);
		printf("Sorts:\n");
		printf("1. Insertion\n");
		printf("2. Merge\n");
		printf("3. Heap\n");
		printf("4. Quicksort\n");
		printf("5. Counting\n");
		printf("6. Radix\n");
		printf("7. Bucket\n");
		return 1;
	}

	inputfilename = argv[1];
	outputfilename = argv[2];
	sortType = std::stoi(argv[3]);

	filestream.open(inputfilename, std::ios::in);
	if(!filestream.is_open()) {
		printf("Could not open input file\n");
		return 1;
	}
	
	while(getline(filestream, readline)) {
		Array.push_back(std::stoi(readline));
	}

	filestream.close();

	switch(sortType) {
		case 1:
		{
			insertionSort(Array);
			break;
		}
		case 2:
		{
			mergeSort(Array, 0, Array.size()-1);
			break;
		}
		case 3:
		{
			Heap A (Array);
			heapSort(A);
			Array = A.array;
			break;
		}
		case 4:
		{
			quickSort(Array, 0, Array.size()-1);
			break;
		}
		case 5:
		{
			std::vector<int> B (Array.size(),0);
			int k = 0;
			for(int i = 0; i < Array.size(); ++i) 
			{
				if(Array[i] > k) k = Array[i];
			}
			countingSort(Array, B, k);
			Array = B;
			break;
		}
		case 6:
		{
			int digits = 0, d = 0;
			for(int i = 0; i < Array.size(); ++i) {
				digits = log10(Array[i])+1;
				if(digits > d) d = digits;
			}
			radixSort(Array, d);
			break;
		}
		case 7:
		{

			break;
		}
		default:
		{
			printf("Sort type invalid\n");
			return 1;
		}

	}

	filestream.open(outputfilename, std::ios::out | std::ios::trunc);

	for(int i = 0; i < Array.size(); ++i) {
		filestream << Array[i] << std::endl;
	}

	filestream.close();

	return 0;

}