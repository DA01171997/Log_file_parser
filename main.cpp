//File: main.cpp
//Group Charlie's Members: Abhyuday Vatsavai, Duy Do, Hasibullah Ziai, Jason Lieu
//Course: CPSC 254 Tue Thr 6:00
//Start Date: 11/15/2017 -Duy Do
//Date last Modified: 11/22/2017 5:40PM -Duy Do 

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "parser.h"
#include "Line.cpp"
using std::cout;
using std::endl;
using std::string;
using std::istringstream;

int main() {
	std::ifstream inFile;
	std::ofstream outFile;
	try {
		inFile.open("test_data.log");							//open log file
		if (!inFile) {									//check if log file opened
			throw std::runtime_error("can't open inFile");
		}
	}
	catch (std::runtime_error &e) {								//exception catch for file open
		cout << e.what() << endl;
	}

	string line;
	int lineCount = 1;			//current line
	getline(inFile, line);		//skip first line
	while (!inFile.eof())
	{
		lineCount++;
		getline(inFile, line);
		istringstream iss(line);
		string useless, alsoUseless, time, uselessToo, veryUseless, superUseless, command, data, stillUseless, ReadWrite;
		if (!(iss >> useless >> alsoUseless >> time >> uselessToo >> veryUseless >> superUseless >> command >> data >> stillUseless >> ReadWrite)) { break; }
		if (command == "40000810" || command == "40000C18")
		{

			Line CommandLine = Line(command, ReadWrite, data);
			cout << "Line " << lineCount << ": " << CommandLine.getReadWrite() << " " << CommandLine.getCommand() << ": " << CommandLine.getWordCount() << " words" << endl;
			int WordCount = 0;
			while (WordCount < CommandLine.getWordCount())			//doesn't work yet b/c need to convert data hex to base10 and divide by 2
			{
				getline(inFile, line);
				if (!(iss >> useless >> alsoUseless >> time >> uselessToo >> veryUseless >> superUseless >> command >> data >> stillUseless >> ReadWrite)) { break; }
				Line SubLine = Line(command, ReadWrite, data);
				for (int subLineWord = 0; subLineWord < 2; subLineWord++) {
					cout << "Line " << lineCount << ": word" << WordCount << ": ";
					//HEX TO BINARY
					//if(subLineWord == 0)
					//LOOK THROUGH FIRST 8 BITS
					//PRINT ACCORDING TO CHART
					//else
					//LOOK THROUGH LAST 8 BITS
					//PRINT ACCORDING TO CHART
				}
			}
			cout << endl;
		}
	}
	inFile.close();
	system("pause");

	}
	return 0;
}
