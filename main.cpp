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
			cout << "Line " << lineCount << ": " << CommandLine.getReadWrite() << " " << CommandLine.getCommand() << ": " << hexTodecimal(CommandLine.getData()) / 2 << " words" << endl;
			int WordCount = 0;
			while (WordCount < hexTodecimal(CommandLine.getData()) / 2)			//doesn't work yet b/c need to convert data hex to base10 and divide by 2
			{
				getline(inFile, line);
				lineCount++;
				iss >> useless >> alsoUseless >> time >> uselessToo >> veryUseless >> superUseless >> command >> data >> stillUseless >> ReadWrite;
				Line SubLine = Line(command, ReadWrite, data);
				string DataBinary = hexTobinary(SubLine.getData());
				for (int subLineWord = 0; subLineWord < 2; subLineWord++) {
					cout << "Line " << lineCount << ": word" << WordCount << ": ";
					string HalfBinary;
					if (subLineWord == 0) { /* first half of DataBinary is put into HalfBinary*/ }
					if (subLineWord == 1) {/*second half of DataBinary is put into HalfBinary*/ }

					//HEX TO BINARY
					//if(subLineWord == 0)
					//LOOK THROUGH FIRST 8 BITS
					//PRINT ACCORDING TO CHART
					//else
					//LOOK THROUGH LAST 8 BITS
					//PRINT ACCORDING TO CHART

					if (WordCount == 0) {
						cout << "Line " << lineCount << ": word" << WordCount << ": Rec_Ctrl = ";
						if ( /*bit 14-13 is 00*/) { cout << 0 << endl; }
						if ( /*bit 14-13 is 10*/) { cout << 2 << endl; }
						if ( /*bit 14-13 is 11*/) { cout << 3 << endl; }
					}



					cout << endl;
					WordCount++;
				}
			}
			cout << endl;
		}
	}
	inFile.close();
	system("pause");
	return 0;
}
/*
int hexTodecimal(string a) {
int stringNum = a.length();
int counter = 0;
double total = 0;
char * c;
for (int i = (stringNum - 1); i > -1; i--) {
c = &a[i];
switch (*c) {
case '0': total += (pow(16, counter) * 0);
break;
case '1': total += (pow(16, counter) * 1);
break;
case '2': total += (pow(16, counter) * 2);
break;
case '3': total += (pow(16, counter) * 3);
break;
case '4': total += (pow(16, counter) * 4);
break;
case '5': total += (pow(16, counter) * 5);
break;
case '6': total += (pow(16, counter) * 6);
break;
case '7': total += (pow(16, counter) * 7);
break;
case '8': total += (pow(16, counter) * 8);
break;
case '9': total += (pow(16, counter) * 9);
break;
case 'A': total += (pow(16, counter) * 10);
break;
case 'B': total += (pow(16, counter) * 11);
break;
case 'C': total += (pow(16, counter) * 12);
break;
case 'D': total += (pow(16, counter) * 13);
break;
case 'E': total += (pow(16, counter) * 14);
break;
case 'F': total += (pow(16, counter) * 15);
break;
}
counter++;
}
return (int)total;
}
string hexTobinary(string a) {				// function that take a hex string and returns a binary string
string temp = "";
char * c;
for (int i = 0; i < a.length(); i++) {
c = &a[i];
switch (*c) {
case '0': temp.append("0000");
break;
case '1': temp.append("0001");
break;
case '2': temp.append("0010");
break;
case '3': temp.append("0011");
break;
case '4': temp.append("0100");
break;
case '5': temp.append("0101");
break;
case '6': temp.append("0110");
break;
case '7': temp.append("0111");
break;
case '8': temp.append("1000");
break;
case '9': temp.append("1001");
break;
case 'A': temp.append("1010");
break;
case 'B': temp.append("1011");
break;
case 'C': temp.append("1100");
break;
case 'D': temp.append("1101");
break;
case 'E': temp.append("1110");
break;
case 'F': temp.append("1111");
break;
}
}
return temp;
}*/