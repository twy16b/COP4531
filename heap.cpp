#include <iostream>
#include <fstream>
#include <string>
#include <vector>

struct Heap {
	std::vector<int> array;
	int heapSize;

	Heap(std::vector<int> &A) { array = A; heapSize = 0; }

	int size() { return array.size(); }

	int operator[](int i) { return array[i]; }

};

void heapSort(Heap &A);
void buildMaxHeap(Heap &A);
void maxHeapify(Heap &A, int i);
int Parent(int i) { return (i-1)/2; }
int Left(int i) { return 2*i + 1; }
int Right(int i) { return 2*i + 2; }

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

	Heap A(Data);
	heapSort(A);

	inputfile.open(argv[1], std::ios::out | std::ios::trunc);

	std::cout << "After sort:\t";
	for(int i = 0; i < A.size(); ++i) {
		std::cout << A[i] << ' ';
		inputfile << A[i] << std::endl;
	}
	std::cout << std::endl;

	return 0;

}

void heapSort(Heap &A) {
	buildMaxHeap(A);
	for(int i = A.size()-1; i > 0; --i) {
		std::swap(A.array[0],A.array[i]);
		--A.heapSize;
		maxHeapify(A,0);
	}
}

void buildMaxHeap(Heap &A) {
	A.heapSize = A.size();
	for(int i = A.size()/2; i >= 0; --i) {
		maxHeapify(A,i);
	}
}

void maxHeapify(Heap &A, int i) {
	int largest = 0;
	int l = Left(i);
	int r = Right(i);

	if (l < A.heapSize && A[l] > A[i]) {
		largest = l;
	}
	else largest = i;

	if (r < A.heapSize && A[r] > A[largest]) {
		largest = r;
	}

	if (largest != i) {
		std::swap(A.array[i], A.array[largest]);
		maxHeapify(A, largest);
	}
}