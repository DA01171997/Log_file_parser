#include <iostream>
#include <fstream>
using std::cout;
using std::endl;
int main() {
	std::ifstream inFile;
	std::ofstream outFile;
	try {
		inFile.open("test_data.log");							//open log file
		if (!inFile) {											//check if log file opened
			throw std::runtime_error("can't open inFile");
		}
	}
	catch (std::runtime_error &e) {								//exception catch for file open
		cout << e.what()<<endl;
	}
	inFile.close();
	return 0;
}