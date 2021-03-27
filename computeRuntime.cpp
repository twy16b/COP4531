#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <chrono>
#include <random>
#include "insertion.hpp"
#include "merge.hpp"
#include "heap.hpp"
#include "quicksort.hpp"
#include "counting.hpp"
#include "radix.hpp"
#include "bucket.hpp"

#define MINVALUE 0
#define MAXVALUE 65536

int main () {

	std::vector<double> sample;
	int sampleSizes[11] = {10,50,100,500,1000,5000,10000,50000,100000,500000,1000000};
	std::chrono::_V2::system_clock::time_point startTime, endTime;

	printf("Insertion,");
	for(int i = 0; i < 8; ++i) {
		for(int j = 0; j < sampleSizes[i]; ++j) {
			sample.push_back((std::rand() + MINVALUE) % MAXVALUE);
		}

		startTime = std::chrono::high_resolution_clock::now();
		insertionSort(sample);
		endTime = std::chrono::high_resolution_clock::now();

		printf("%.3f",std::chrono::duration<double,std::milli>(endTime - startTime).count());
		if(i < 7) std::cout << ',';

		sample.clear();
	}
	std::cout << std::endl;

	printf("Merge,");
	for(int i = 0; i < 11; ++i) {
		for(int j = 0; j < sampleSizes[i]; ++j) {
			sample.push_back((std::rand() + MINVALUE) % MAXVALUE);
		}

		startTime = std::chrono::high_resolution_clock::now();
		mergeSort(sample,0,sample.size()-1);
		endTime = std::chrono::high_resolution_clock::now();

		printf("%.3f",std::chrono::duration<double,std::milli>(endTime - startTime).count());
		if(i < 10) std::cout << ',';

		sample.clear();
	}
	std::cout << std::endl;

	printf("Heap,");
	for(int i = 0; i < 11; ++i) {
		for(int j = 0; j < sampleSizes[i]; ++j) {
			sample.push_back((std::rand() + MINVALUE) % MAXVALUE);
		}

		Heap H = sample;
		startTime = std::chrono::high_resolution_clock::now();
		heapSort(H);
		endTime = std::chrono::high_resolution_clock::now();
		sample = H.array;

		printf("%.3f",std::chrono::duration<double,std::milli>(endTime - startTime).count());
		if(i < 10) std::cout << ',';

		sample.clear();
	}
	std::cout << std::endl;

	printf("QuickSort,");
	for(int i = 0; i < 9; ++i) {
		for(int j = 0; j < sampleSizes[i]; ++j) {
			sample.push_back((std::rand() + MINVALUE) % MAXVALUE);
		}

		startTime = std::chrono::high_resolution_clock::now();
		quickSort(sample,0,sample.size()-1);
		endTime = std::chrono::high_resolution_clock::now();

		printf("%.3f",std::chrono::duration<double,std::milli>(endTime - startTime).count());
		if(i < 8) std::cout << ',';

		sample.clear();
	}
	std::cout << std::endl;

	printf("Counting,");
	for(int i = 0; i < 11; ++i) {
		for(int j = 0; j < sampleSizes[i]; ++j) {
			sample.push_back((std::rand() + MINVALUE) % MAXVALUE);
		}

		std::vector<double> B(sample.size());
		int k = 0;
		for(int i = 0; i < sample.size(); ++i) 
		{
			if(sample[i] > k) k = sample[i];
		}
		startTime = std::chrono::high_resolution_clock::now();
		countingSort(sample,B,k);
		endTime = std::chrono::high_resolution_clock::now();
		sample = B;

		printf("%.3f",std::chrono::duration<double,std::milli>(endTime - startTime).count());
		if(i < 10) std::cout << ',';

		sample.clear();
	}
	std::cout << std::endl;

	printf("Radix,");
	for(int i = 0; i < 6; ++i) {
		for(int j = 0; j < sampleSizes[i]; ++j) {
			sample.push_back((std::rand() + MINVALUE) % MAXVALUE);
		}

		int digits = 0, d = 0;
		for(int i = 0; i < sample.size(); ++i) {
			digits = log10(sample[i])+1;
			if(digits > d) d = digits;
		}
		startTime = std::chrono::high_resolution_clock::now();
		radixSort(sample,d);
		endTime = std::chrono::high_resolution_clock::now();

		printf("%.3f",std::chrono::duration<double,std::milli>(endTime - startTime).count());
		if(i < 5) std::cout << ',';

		sample.clear();
	}
	std::cout << std::endl;

	printf("Bucket,");
	std::default_random_engine randEng;
	std::uniform_real_distribution<double> range(0.0, 0.9999);
	for(int i = 0; i < 11; ++i) {
		for(int j = 0; j < sampleSizes[i]; ++j) {
			sample.push_back(range(randEng));
		}

		startTime = std::chrono::high_resolution_clock::now();
		bucketSort(sample);
		endTime = std::chrono::high_resolution_clock::now();

		printf("%.3f",std::chrono::duration<double,std::milli>(endTime - startTime).count());
		if(i < 10) std::cout << ',';

		sample.clear();
	}
	std::cout << std::endl;

}