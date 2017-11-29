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

using std::ifstream;

int main() {
	ifstream inFile;
	ifstream Backup;						//used to get data from next line
	std::ofstream outFile;
	char * cTemp;

	float StoDRead;
	float StoDWrite;
	float DtoSRead;
	float DtoSWrite;
	long int StoDReadData;
	long int StoDWriteData;
	long int DtoSReadData;
	long int DtoSWriteData;

	try {
		inFile.open("test_data.log");							//open log file
		if (!inFile) {									//check if log file opened
			throw std::runtime_error("can't open inFile");
		}
	}
	catch (std::runtime_error &e) {								//exception catch for file open
		cout << e.what() << endl;
	}


	try {
		Backup.open("test_data.log");							//open log file
		if (!Backup) {									//check if log file opened
			throw std::runtime_error("can't open inFile");
		}
	}
	catch (std::runtime_error &e) {								//exception catch for file open
		cout << e.what() << endl;
	}
	string line;
	string nextLine;
	int lineCount = 1;			//current line
	getline(inFile, line);		//skip first line
	getline(Backup, nextLine);
	getline(Backup, nextLine);

	while (!inFile.eof())
	{
		bool reversed = false;
		lineCount++;
		getline(inFile, line);
		getline(Backup, nextLine);

		istringstream iss(line);
		string useless, alsoUseless, time, uselessToo, veryUseless, superUseless, command, data, stillUseless, ReadWrite;
		if (!(iss >> useless >> alsoUseless >> time >> uselessToo >> veryUseless >> superUseless >> command >> data >> stillUseless >> ReadWrite)) { break; }


		istringstream issss(nextLine);
		string a, b, nextTime, c, d, e, nextCommand;
		issss >> a >> b >> nextTime >> c >> d >> e >> nextCommand;

		if (command == "40000C18" || command == "40000810") {
			if (nextCommand != "40000818" && nextCommand != "40000C20") {
				reversed = true;
			}
			else reversed = false;
			if (!reversed)
			{
				Line CommandLine = Line(command, ReadWrite, data);
				cout << "Line " << lineCount << ": " << CommandLine.getReadWrite() << " " << CommandLine.getCommand() << ": " << hexTodecimal(CommandLine.getData()) / 2 << " words" << endl;
				int WordCount = 0;
				while (WordCount < hexTodecimal(CommandLine.getData()) / 2)			//doesn't work yet b/c need to convert data hex to base10 and divide by 2
				{
					getline(inFile, line);
					getline(Backup, nextLine);
					lineCount++;
					istringstream isss(line);
					isss >> useless >> alsoUseless >> time >> uselessToo >> veryUseless >> superUseless >> command >> data >> stillUseless >> ReadWrite;
					Line SubLine = Line(command, ReadWrite, data);
					string DataBinary = hexTobinary(SubLine.getData());
					for (int subLineWord = 0; subLineWord < 2; subLineWord++) {
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
						reverse(HalfBinary.begin(), HalfBinary.end());
						//		cout << endl << HalfBinary << "              " << binaryToDecimal(HalfBinary.substr(13, 2))<<endl;
						switch (WordCount) {
						case 0:
							cout << "Line " << lineCount << ": word " << WordCount << ": Rec_ctrl = ";
							if (binaryToDecimal(HalfBinary.substr(13, 2)) == 0) { cout << "0 (no recording)" << endl; }
							else if (binaryToDecimal(HalfBinary.substr(13, 2)) == 2) { cout << "2 (no processing)" << endl; }
							else if (binaryToDecimal(HalfBinary.substr(13, 2)) == 3) { cout << "3 (processing & recording)" << endl; }
							break;
						case 1:
							cout << "Line " << lineCount << ": word " << WordCount << ": Cmd_Type = ";
							if (binaryToDecimal(HalfBinary.substr(13, 3)) == 4) { cout << "4 (Type A)" << endl; }
							else if (binaryToDecimal(HalfBinary.substr(13, 3)) == 5) { cout << "5 (Type B)" << endl; }
							else if (binaryToDecimal(HalfBinary.substr(13, 3)) == 6) { cout << "6 (Type C)" << endl; }
							else cout << "1 (unknown)" << endl;
							break;
						case 4:
							cout << "Line " << lineCount << ": word " << WordCount << ": Rec_Raw = ";
							if (binaryToDecimal(HalfBinary.substr(0, 1)) == 0) { cout << "0 (disable)" << endl; }
							else if (binaryToDecimal(HalfBinary.substr(0, 1)) == 1) { cout << "1 (enable)" << endl; }
							break;
						case 5:
							cout << "Line " << lineCount << ": word " << WordCount << ": Cmd_ID = " << binaryToDecimal(HalfBinary.substr(0, 7)) << endl;
							break;
						case 10:
							cout << "Line " << lineCount << ": word " << WordCount << ": Num_Responses = " << binaryToDecimal(HalfBinary.substr(11, 5)) << endl;
							break;
						case 15:
							cout << "Line " << lineCount << ": word " << WordCount << ": Reset_Enabled = ";
							if (binaryToDecimal(HalfBinary.substr(2, 1)) == 0) { cout << "0 (disable)" << endl; }
							else if (binaryToDecimal(HalfBinary.substr(2, 1)) == 1) { cout << "1 (enable)" << endl; }
							break;
						case 22:
							cout << "Line " << lineCount << ": word " << WordCount << ": Direction = ";
							if (binaryToDecimal(HalfBinary.substr(3, 1)) == 0) { cout << "0 (Right)" << endl; }
							else if (binaryToDecimal(HalfBinary.substr(3, 1)) == 1) { cout << "1 (Left)" << endl; }
							break;
						case 32:
							cout << "Line " << lineCount << ": word " << WordCount << ": Num_Samples = " << binaryToDecimal(HalfBinary.substr(0, 15)) << endl;
							break;
						case 37:
							cout << "Line " << lineCount << ": word " << WordCount << ": Parity = ";
							if (binaryToDecimal(HalfBinary.substr(15, 1)) == 0) { cout << "0 (even)" << endl; }
							else if (binaryToDecimal(HalfBinary.substr(15, 1)) == 1) { cout << "1 (odd)" << endl; }
							break;
						case 38:
							cout << "Line " << lineCount << ": word " << WordCount << ": Test = ";
							if (binaryToDecimal(HalfBinary.substr(14, 1)) == 0) { cout << "0 (disable)" << endl; }
							else if (binaryToDecimal(HalfBinary.substr(14, 1)) == 0) { cout << "1 (enable)" << endl; }
							break;
						case 40:
							cout << "Line " << lineCount << ": word " << WordCount << ": Ctrl_Enable = ";
							if (binaryToDecimal(HalfBinary.substr(7, 1)) == 0) { cout << "0 (disable)" << endl; }
							else if (binaryToDecimal(HalfBinary.substr(7, 1)) == 0) { cout << "0 (disable)" << endl; }
							break;
						case 41:
							cout << "Line " << lineCount << ": word " << WordCount << ": Code = " << binaryToDecimal(HalfBinary.substr(8, 7)) << endl;
							break;
						}
						WordCount++;
					}
				}
				cout << endl;
			}
			if (reversed)

			{

				Line CommandLine = Line(command, ReadWrite, data);
				cout << "Line " << lineCount << ": " << CommandLine.getReadWrite() << " " << CommandLine.getCommand() << ": " << hexTodecimal(CommandLine.getData()) / 2 << " words" << endl;

				int WordCount = (hexTodecimal(CommandLine.getData()) / 2) - 1;
				while (WordCount > 0)
				{
					getline(inFile, line);
					getline(Backup, nextLine);

					lineCount++;
					istringstream isss(line);
					isss >> useless >> alsoUseless >> time >> uselessToo >> veryUseless >> superUseless >> command >> data >> stillUseless >> ReadWrite;
					Line SubLine = Line(command, ReadWrite, data);
					string DataBinary = hexTobinary(SubLine.getData());
					for (int subLineWord = 0; subLineWord < 2; subLineWord++) {
						string HalfBinary = "";

						if (subLineWord == 1) {

							for (int i = 0; i < 16; i++) {
								cTemp = &DataBinary[i];
								HalfBinary += (*cTemp);
							}
						}

						if (subLineWord == 0) {

							for (int i = 16; i < 32; i++) {
								cTemp = &DataBinary[i];
								HalfBinary += (*cTemp);
							}
						}
						reverse(HalfBinary.begin(), HalfBinary.end());

						switch (WordCount) {
						case 0:
							cout << "Line " << lineCount << ": word " << WordCount << ": Rec_ctrl = ";
							if (binaryToDecimal(HalfBinary.substr(13, 2)) == 0) { cout << "0 (no recording)" << endl; }
							else if (binaryToDecimal(HalfBinary.substr(13, 2)) == 2) { cout << "2 (no processing)" << endl; }
							else if (binaryToDecimal(HalfBinary.substr(13, 2)) == 3) { cout << "3 (processing & recording)" << endl; }
							break;
						case 1:
							cout << "Line " << lineCount << ": word " << WordCount << ": Cmd_Type = ";
							if (binaryToDecimal(HalfBinary.substr(13, 3)) == 4) { cout << "4 (Type A)" << endl; }
							else if (binaryToDecimal(HalfBinary.substr(13, 3)) == 5) { cout << "5 (Type B)" << endl; }
							else if (binaryToDecimal(HalfBinary.substr(13, 3)) == 6) { cout << "6 (Type C)" << endl; }
							else cout << "1 (unknown)" << endl;
							break;
						case 4:
							cout << "Line " << lineCount << ": word " << WordCount << ": Rec_Raw = ";
							if (binaryToDecimal(HalfBinary.substr(0, 1)) == 0) { cout << "0 (disable)" << endl; }
							else if (binaryToDecimal(HalfBinary.substr(0, 1)) == 1) { cout << "1 (enable)" << endl; }
							break;
						case 5:
							cout << "Line " << lineCount << ": word " << WordCount << ": Cmd_ID = " << binaryToDecimal(HalfBinary.substr(0, 7)) << endl;
							break;
						case 10:
							cout << "Line " << lineCount << ": word " << WordCount << ": Num_Responses = " << binaryToDecimal(HalfBinary.substr(11, 5)) << endl;
							break;
						case 15:
							cout << "Line " << lineCount << ": word " << WordCount << ": Reset_Enabled = ";
							if (binaryToDecimal(HalfBinary.substr(2, 1)) == 0) { cout << "0 (disable)" << endl; }
							else if (binaryToDecimal(HalfBinary.substr(2, 1)) == 1) { cout << "1 (enable)" << endl; }
							break;
						case 22:
							cout << "Line " << lineCount << ": word " << WordCount << ": Direction = ";
							if (binaryToDecimal(HalfBinary.substr(3, 1)) == 0) { cout << "0 (Right)" << endl; }
							else if (binaryToDecimal(HalfBinary.substr(3, 1)) == 1) { cout << "1 (Left)" << endl; }
							break;
						case 32:
							cout << "Line " << lineCount << ": word " << WordCount << ": Num_Samples = " << binaryToDecimal(HalfBinary.substr(0, 15)) << endl;
							break;
						case 37:
							cout << "Line " << lineCount << ": word " << WordCount << ": Parity = ";
							if (binaryToDecimal(HalfBinary.substr(15, 1)) == 0) { cout << "0 (even)" << endl; }
							else if (binaryToDecimal(HalfBinary.substr(15, 1)) == 1) { cout << "1 (odd)" << endl; }
							break;
						case 38:
							cout << "Line " << lineCount << ": word " << WordCount << ": Test = ";
							if (binaryToDecimal(HalfBinary.substr(14, 1)) == 0) { cout << "0 (disable)" << endl; }
							else if (binaryToDecimal(HalfBinary.substr(14, 1)) == 0) { cout << "1 (enable)" << endl; }
							break;
						case 40:
							cout << "Line " << lineCount << ": word " << WordCount << ": Ctrl_Enable = ";
							if (binaryToDecimal(HalfBinary.substr(7, 1)) == 0) { cout << "0 (disable)" << endl; }
							else if (binaryToDecimal(HalfBinary.substr(7, 1)) == 0) { cout << "0 (disable)" << endl; }
							break;
						case 41:
							cout << "Line " << lineCount << ": word " << WordCount << ": Code = " << binaryToDecimal(HalfBinary.substr(8, 7)) << endl;
							break;
						}

						WordCount--;

					}
				if( CommandLine.getReadWrite() == "Read"){
				StoDRead += getTime(time);
				StoDReadData += 4;				//increments 4 bytes, can be changed for 32 bits
				}else if(CommandLine.getReadWrite() == "Write"){
				StoDWrite += getTime(time);
				StoDWriteData += 4;				//increments 4 bytes, can be changed for 32 bits

					}
				}
				cout << endl;
			}

				if(CommandLine.getReadWrite() == "Read"){
					DtoSRead += getTime(time);
					DtoSReadData += 4;		//increments 4 bytes, can be changed for 32 bits
				}else if(CommandLine.getReadWrite() == "Write"){
					DtoSWrite += getTime(time);
					DtoSWriteData += 4;              //increments 4 bytes, can be changed for 32 bits
				}
				cout << endl;
			}


		}



	}
	inFile.close();

	Backup.close();

	system("pause");
	return 0;
}