#include <iostream>
#include <fstream>
#include <string>

int main (int argc, char* argv[]) {

	if(argc != 2) {
		printf("Wrong number of arguments\n");
		printf("usage: %s <input-csv>\n", argv[0]);
		return 1;
	}

	std::ifstream inputfile (argv[1]);
	if(!inputfile.is_open()) {
		printf("Could not open input file\n");
		return 1;
	}

	std::string readline;
	while(getline(inputfile, readline)) {
		std::cout << readline << std::endl;
	}

	inputfile.close();

	return 0;

}