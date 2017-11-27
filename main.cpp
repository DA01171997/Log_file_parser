//File: main.cpp
//Group Charlie's Members: Abhyuday Vatsavai, Duy Do, Hasibullah Ziai, Jason Lieu
//Course: CPSC 254 Tue Thr 6:00
//Start Date: 11/15/2017 -Duy Do
//Date last Modified: 11/16/2017 12:03AM -Duy Do 

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "Line.cpp"
#include "parser.h"
using std::cout;
using std::endl;
using std::string;
using std::istringstream;
int hexTodecimal(string);
string hexTobinary(string);
int main() {
	std::ifstream inFile;
	std::ofstream outFile;
	char * cTemp;
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
		if (command == "40000810")
		{

			Line CommandLine = Line(command, ReadWrite, data);
			cout << "Line " << lineCount << ": " << CommandLine.getReadWrite() << " S-to-D command: " << hexTodecimal(CommandLine.getData()) / 2 << " words" << endl;
			int WordCount = 0;
			while (WordCount < hexTodecimal(CommandLine.getData()) / 2)			//doesn't work yet b/c need to convert data hex to base10 and divide by 2
			{
				getline(inFile, line);
				lineCount++;
				istringstream isss(line);
				isss >> useless >> alsoUseless >> time >> uselessToo >> veryUseless >> superUseless >> command >> data >> stillUseless >> ReadWrite;
				Line SubLine = Line(command, ReadWrite, data);
				string DataBinary = hexTobinary(SubLine.getData());
				for (int subLineWord = 0; subLineWord < 2; subLineWord++) {
					cout << "Line " << lineCount << ": word " << WordCount << ": ";
					string HalfBinary = "";
					if (subLineWord == 0) {
						for (int i = 0; i < 16; i++) {
							cTemp = &DataBinary[i];
							HalfBinary += (*cTemp);
						}
					}
					if (subLineWord == 1) {
						for (int i = 16; i < 32; i++) {
							cTemp = &DataBinary[i];
							HalfBinary += (*cTemp);
						}
					}

					//HEX TO BINARY
					//if(subLineWord == 0)
					//LOOK THROUGH FIRST 8 BITS
					//PRINT ACCORDING TO CHART
					//else
					//LOOK THROUGH LAST 8 BITS
					//PRINT ACCORDING TO CHART

					//if (WordCount == 0) {
					//cout << "Line " << lineCount << ": word" << WordCount << ": Rec_Ctrl = ";
					//if ( /*bit 14-13 is 00) { cout << 0 << endl; }
					//if ( /*bit 14-13 is 10) { cout << 2 << endl; }
					//if ( /*bit 14-13 is 11) { cout << 3 << endl; }
					//}*/


					cout << endl;
					WordCount++;
				}
			}
			cout << endl;
		}
		if (command == "40000C18")
		{

			Line CommandLine = Line(command, ReadWrite, data);
			cout << "Line " << lineCount << ": " << CommandLine.getReadWrite() << " D-to-S command: " << hexTodecimal(CommandLine.getData()) / 2 << " words" << endl;
			int WordCount = (hexTodecimal(CommandLine.getData()) / 2) - 1;
			while (WordCount > 0)			//doesn't work yet b/c need to convert data hex to base10 and divide by 2
			{
				getline(inFile, line);
				lineCount++;
				istringstream isss(line);
				isss >> useless >> alsoUseless >> time >> uselessToo >> veryUseless >> superUseless >> command >> data >> stillUseless >> ReadWrite;
				Line SubLine = Line(command, ReadWrite, data);
				string DataBinary = hexTobinary(SubLine.getData());
				for (int subLineWord = 0; subLineWord < 2; subLineWord++) {
					cout << "Line " << lineCount << ": word " << WordCount << ": ";
					string HalfBinary = "";
					if (subLineWord == 0) {
						for (int i = 0; i < 16; i++) {
							cTemp = &DataBinary[i];
							HalfBinary += (*cTemp);
						}
					}
					if (subLineWord == 1) {
						for (int i = 16; i < 32; i++) {
							cTemp = &DataBinary[i];
							HalfBinary += (*cTemp); 
						}
					}
					/*
					if (subLineWord == 0) { /* first half of DataBinary is put into HalfBinary* }
					if (subLineWord == 1) {/*second half of DataBinary is put into HalfBinary* }

					//HEX TO BINARY
					//if(subLineWord == 0)
					//LOOK THROUGH FIRST 8 BITS
					//PRINT ACCORDING TO CHART
					//else
					//LOOK THROUGH LAST 8 BITS
					//PRINT ACCORDING TO CHART

					if (WordCount == 0) {
					cout << "Line " << lineCount << ": word" << WordCount << ": Rec_Ctrl = ";
					if ( /*bit 14-13 is 00) { cout << 0 << endl; }
					if ( /*bit 14-13 is 10) { cout << 2 << endl; }
					if ( /*bit 14-13 is 11) { cout << 3 << endl; }
					}*/



					cout << endl;
					WordCount--;
				}
			}
			cout << endl;
		}
	}
	inFile.close();

	system("pause");
	return 0;
}