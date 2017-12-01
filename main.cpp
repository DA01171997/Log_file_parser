//File: main.cpp
//Group Charlie's Members: Abhyuday Vatsavai, Duy Do, Hasibullah Ziai, Jason Lieu
//Course: CPSC 254 Tue Thr 6:00
//Start Date: 11/15/2017 -Duy Do
//Date last Modified: 11/16/2017 12:03AM -Duy Do 

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <iomanip>

#include "Line.cpp"
using std::cout;
using std::endl;
using std::string;
using std::istringstream;
using std::ifstream;
using std::reverse;
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
}
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
int hexToNumWord(int a) {
	int NumWord = a / 2;
	return NumWord;
}
int binaryToDecimal(string a) {
	int stringNum = a.length();
	int counter = 0;
	double total = 0;
	char * c;
	for (int i = (stringNum - 1); i > -1; i--) {
		c = &a[i];
		if (*c == '1') { total += (pow(2, counter) * 1); }
		counter++;
	}
	return (int)total;
}
long double getTime(string a) {
	char * c = &a[a.length() - 2];
	long double time;
	switch (*c) {
	case 'm':
		time = (atof((a.substr(0, a.length() - 2)).c_str())) * 0.001;
		return time;
	case 'u':
		time = (atof((a.substr(0, a.length() - 2)).c_str())) *0.000001;
		return time;
	case 'n':
		time = (atof((a.substr(0, a.length() - 2)).c_str())) *0.000000001;
		return time;
	}
}




int main() {
	ifstream inFile;
	ifstream Backup;						//used to get data from next line
	std::ofstream outFile;
	char * cTemp;
	long double SDReadTime = 0;
	long double SDWriteTime = 0;
	long double DSReadTime = 0;
	long double DSWriteTime = 0;
	long double SDReadData = 0;
	long double SDWriteData = 0;
	long double DSReadData = 0;
	long double DSWriteData = 0;



	try {
		inFile.open("test_data.log");							//open log file
		outFile.open("result.txt");
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

			if (command == "40000810") {
				if (ReadWrite == "Rd") {
					SDReadTime += getTime(nextTime);
					SDReadData += (hexTodecimal(data)/2) *16;
					SDReadData += 32;
					//cout << "SDREAD : " <<SDReadData << endl;
				}
				else if (ReadWrite == "Wr") {
					SDWriteTime += getTime(nextTime);
					SDWriteData += (hexTodecimal(data)/2) *16;
					SDWriteData += 32;
					//cout << "SDWrite : "<<SDWriteData << endl;
				}
			}
			if (command == "40000C18") {
				if (ReadWrite == "Rd") {
					DSReadTime += getTime(nextTime);
					DSReadData += (hexTodecimal(data)/2) *16;
					DSReadData += 32;
					//cout << "DSRead : "<< DSReadData << endl;
				}
				else if (ReadWrite == "Wr") {
					DSWriteTime += getTime(nextTime);
					DSWriteData += (hexTodecimal(data)/2) *16;
					DSWriteData += 32;
					//cout << "DSWrite : " <<DSWriteData << endl;

				}
			}



			if (!reversed)
			{
				Line CommandLine = Line(command, ReadWrite, data);
				outFile << "Line " << lineCount << ": " << CommandLine.getReadWrite() << " " << CommandLine.getCommand() << ": " << hexTodecimal(CommandLine.getData()) / 2 << " words" << endl;
				int WordCount = 0;

				

				while (WordCount < hexTodecimal(CommandLine.getData()) / 2)
				{

					
					

					getline(inFile, line);
					getline(Backup, nextLine);

					istringstream isssss(nextLine);
					string aa, bb, nextSubTime;
					isssss >> aa >> bb >> nextSubTime;

					if (CommandLine.getCommand() == "S-to-D") {
						if (CommandLine.getReadWrite() == "Read") {
							SDReadTime += getTime(nextSubTime);
							//SDReadData += 4;
						}
						else {
							SDWriteTime += getTime(nextSubTime);
							//SDWriteData += 4;
						}
					}
					if (CommandLine.getCommand() == "D-to-S") {
						if (CommandLine.getReadWrite() == "Read") {
							DSReadTime += getTime(nextSubTime);
							//DSReadData += 4;
						}
						else {
							DSWriteTime += getTime(nextSubTime);
							//DSWriteData += 4;

						}
					}
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
						switch (WordCount) {
						case 0:
							outFile << "Line " << lineCount << ": word " << WordCount << ": Rec_ctrl = ";
							if (binaryToDecimal(HalfBinary.substr(13, 2)) == 0) { outFile << "0 (no recording)" << endl; }
							else if (binaryToDecimal(HalfBinary.substr(13, 2)) == 2) { outFile << "2 (no processing)" << endl; }
							else if (binaryToDecimal(HalfBinary.substr(13, 2)) == 3) { outFile << "3 (processing & recording)" << endl; }
							else outFile << binaryToDecimal(HalfBinary.substr(13, 2))<<" (unknown)" << endl;
							break;
						case 1:
							outFile << "Line " << lineCount << ": word " << WordCount << ": Cmd_Type = ";
							if (binaryToDecimal(HalfBinary.substr(13, 3)) == 4) { outFile << "4 (Type A)" << endl; }
							else if (binaryToDecimal(HalfBinary.substr(13, 3)) == 5) { outFile << "5 (Type B)" << endl; }
							else if (binaryToDecimal(HalfBinary.substr(13, 3)) == 6) { outFile << "6 (Type C)" << endl; }
							else outFile << binaryToDecimal(HalfBinary.substr(13, 3)) << " (unknown)" << endl;
							break;
						case 4:
							outFile << "Line " << lineCount << ": word " << WordCount << ": Rec_Raw = ";
							if (binaryToDecimal(HalfBinary.substr(0, 1)) == 0) { outFile << "0 (disable)" << endl; }
							else if (binaryToDecimal(HalfBinary.substr(0, 1)) == 1) { outFile << "1 (enable)" << endl; }
							else outFile << binaryToDecimal(HalfBinary.substr(0, 1)) << " (unknown)" << endl;

							break;
						case 5:
							outFile << "Line " << lineCount << ": word " << WordCount << ": Cmd_ID = " << binaryToDecimal(HalfBinary.substr(0, 7)) << endl;
							break;
						case 10:
							outFile << "Line " << lineCount << ": word " << WordCount << ": Num_Responses = " << binaryToDecimal(HalfBinary.substr(11, 5)) << endl;
							break;
						case 15:
							outFile << "Line " << lineCount << ": word " << WordCount << ": Reset_Enabled = ";
							if (binaryToDecimal(HalfBinary.substr(2, 1)) == 0) { outFile << "0 (disable)" << endl; }
							else if (binaryToDecimal(HalfBinary.substr(2, 1)) == 1) { outFile << "1 (enable)" << endl; }
							else outFile << binaryToDecimal(HalfBinary.substr(2, 1)) << " (unknown)" << endl;
							break;
						case 22:
							outFile << "Line " << lineCount << ": word " << WordCount << ": Direction = ";
							if (binaryToDecimal(HalfBinary.substr(3, 1)) == 0) { outFile << "0 (Right)" << endl; }
							else if (binaryToDecimal(HalfBinary.substr(3, 1)) == 1) { outFile << "1 (Left)" << endl; }
							else outFile << binaryToDecimal(HalfBinary.substr(3, 1)) << " (unknown)" << endl;
							break;
						case 32:
							outFile << "Line " << lineCount << ": word " << WordCount << ": Num_Samples = " << binaryToDecimal(HalfBinary.substr(0, 15)) << endl;
							break;
						case 37:
							outFile << "Line " << lineCount << ": word " << WordCount << ": Parity = ";
							if (binaryToDecimal(HalfBinary.substr(15, 1)) == 0) { outFile << "0 (even)" << endl; }
							else if (binaryToDecimal(HalfBinary.substr(15, 1)) == 1) { outFile << "1 (odd)" << endl; }
							else outFile << binaryToDecimal(HalfBinary.substr(15, 1)) << " (unknown)" << endl;
							break;
						case 38:
							outFile << "Line " << lineCount << ": word " << WordCount << ": Test = ";
							if (binaryToDecimal(HalfBinary.substr(14, 1)) == 0) { outFile << "0 (disable)" << endl; }
							else if (binaryToDecimal(HalfBinary.substr(14, 1)) == 0) { outFile << "1 (enable)" << endl; }
							else outFile << binaryToDecimal(HalfBinary.substr(14, 1)) << " (unknown)" << endl;
							break;
						case 40:
							outFile << "Line " << lineCount << ": word " << WordCount << ": Ctrl_Enable = ";
							if (binaryToDecimal(HalfBinary.substr(7, 1)) == 0) { outFile << "0 (disable)" << endl; }
							else if (binaryToDecimal(HalfBinary.substr(7, 1)) == 0) { outFile << "0 (disable)" << endl; }
							else outFile << binaryToDecimal(HalfBinary.substr(7, 1)) << " (unknown)" << endl;
							break;
						case 41:
							outFile << "Line " << lineCount << ": word " << WordCount << ": Code = " << binaryToDecimal(HalfBinary.substr(8, 7)) << endl;
							break;
						}
						WordCount++;
					}
				}
				outFile << endl;
			}
			if (reversed)
			{

				Line CommandLine = Line(command, ReadWrite, data);
				outFile << "Line " << lineCount << ": " << CommandLine.getReadWrite() << " " << CommandLine.getCommand() << ": " << hexTodecimal(CommandLine.getData()) / 2 << " words" << endl;
				int WordCount = (hexTodecimal(CommandLine.getData()) / 2) - 1;
				while (WordCount > 0)
				{
					
					


					getline(inFile, line);
					getline(Backup, nextLine);
					istringstream isssss(nextLine);
					string aa, bb, nextSubTime;
					isssss >> aa >> bb >> nextSubTime;

					if (CommandLine.getCommand() == "S-to-D") {
						if (CommandLine.getReadWrite() == "Read") {
							SDReadTime += getTime(nextSubTime);
							//SDReadData += 4;
						}
						else {
							SDWriteTime += getTime(nextSubTime);
							//SDWriteData += 4;
						}
					}
					if (CommandLine.getCommand() == "D-to-S") {
						if (CommandLine.getReadWrite() == "Read") {
							DSReadTime += getTime(nextSubTime);
							//	DSReadData += 4;
						}
						else {
							DSWriteTime += getTime(nextSubTime);
							//DSWriteData += 4;

						}
					}

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
							outFile << "Line " << lineCount << ": word " << WordCount << ": Rec_ctrl = ";
							if (binaryToDecimal(HalfBinary.substr(13, 2)) == 0) { outFile << "0 (no recording)" << endl; }
							else if (binaryToDecimal(HalfBinary.substr(13, 2)) == 2) { outFile << "2 (no processing)" << endl; }
							else if (binaryToDecimal(HalfBinary.substr(13, 2)) == 3) { outFile << "3 (processing & recording)" << endl; }
							else outFile << binaryToDecimal(HalfBinary.substr(13, 2)) << " (unknown)" << endl;
							break;
						case 1:
							outFile << "Line " << lineCount << ": word " << WordCount << ": Cmd_Type = ";
							if (binaryToDecimal(HalfBinary.substr(13, 3)) == 4) { outFile << "4 (Type A)" << endl; }
							else if (binaryToDecimal(HalfBinary.substr(13, 3)) == 5) { outFile << "5 (Type B)" << endl; }
							else if (binaryToDecimal(HalfBinary.substr(13, 3)) == 6) { outFile << "6 (Type C)" << endl; }
							else outFile << binaryToDecimal(HalfBinary.substr(13, 3)) << " (unknown)" << endl;
							break;
						case 4:
							outFile << "Line " << lineCount << ": word " << WordCount << ": Rec_Raw = ";
							if (binaryToDecimal(HalfBinary.substr(0, 1)) == 0) { outFile << "0 (disable)" << endl; }
							else if (binaryToDecimal(HalfBinary.substr(0, 1)) == 1) { outFile << "1 (enable)" << endl; }
							else outFile << binaryToDecimal(HalfBinary.substr(0, 1)) << " (unknown)" << endl;

							break;
						case 5:
							outFile << "Line " << lineCount << ": word " << WordCount << ": Cmd_ID = " << binaryToDecimal(HalfBinary.substr(0, 7)) << endl;
							break;
						case 10:
							outFile << "Line " << lineCount << ": word " << WordCount << ": Num_Responses = " << binaryToDecimal(HalfBinary.substr(11, 5)) << endl;
							break;
						case 15:
							outFile << "Line " << lineCount << ": word " << WordCount << ": Reset_Enabled = ";
							if (binaryToDecimal(HalfBinary.substr(2, 1)) == 0) { outFile << "0 (disable)" << endl; }
							else if (binaryToDecimal(HalfBinary.substr(2, 1)) == 1) { outFile << "1 (enable)" << endl; }
							else outFile << binaryToDecimal(HalfBinary.substr(2, 1)) << " (unknown)" << endl;
							break;
						case 22:
							outFile << "Line " << lineCount << ": word " << WordCount << ": Direction = ";
							if (binaryToDecimal(HalfBinary.substr(3, 1)) == 0) { outFile << "0 (Right)" << endl; }
							else if (binaryToDecimal(HalfBinary.substr(3, 1)) == 1) { outFile << "1 (Left)" << endl; }
							else outFile << binaryToDecimal(HalfBinary.substr(3, 1)) << " (unknown)" << endl;
							break;
						case 32:
							outFile << "Line " << lineCount << ": word " << WordCount << ": Num_Samples = " << binaryToDecimal(HalfBinary.substr(0, 15)) << endl;
							break;
						case 37:
							outFile << "Line " << lineCount << ": word " << WordCount << ": Parity = ";
							if (binaryToDecimal(HalfBinary.substr(15, 1)) == 0) { outFile << "0 (even)" << endl; }
							else if (binaryToDecimal(HalfBinary.substr(15, 1)) == 1) { outFile << "1 (odd)" << endl; }
							else outFile << binaryToDecimal(HalfBinary.substr(15, 1)) << " (unknown)" << endl;
							break;
						case 38:
							outFile << "Line " << lineCount << ": word " << WordCount << ": Test = ";
							if (binaryToDecimal(HalfBinary.substr(14, 1)) == 0) { outFile << "0 (disable)" << endl; }
							else if (binaryToDecimal(HalfBinary.substr(14, 1)) == 0) { outFile << "1 (enable)" << endl; }
							else outFile << binaryToDecimal(HalfBinary.substr(14, 1)) << " (unknown)" << endl;
							break;
						case 40:
							outFile << "Line " << lineCount << ": word " << WordCount << ": Ctrl_Enable = ";
							if (binaryToDecimal(HalfBinary.substr(7, 1)) == 0) { outFile << "0 (disable)" << endl; }
							else if (binaryToDecimal(HalfBinary.substr(7, 1)) == 0) { outFile << "0 (disable)" << endl; }
							else outFile << binaryToDecimal(HalfBinary.substr(7, 1)) << " (unknown)" << endl;
							break;
						case 41:
							outFile << "Line " << lineCount << ": word " << WordCount << ": Code = " << binaryToDecimal(HalfBinary.substr(8, 7)) << endl;
							break;
						}
						WordCount--;
					}
				}
				outFile << endl;
			}
		}
	}
	cout << "SDRBit : " << SDReadData<<"   SDRTime : " << SDReadTime << endl;
	cout << "DSRBit : " << DSReadData << "   DSRTime : " << DSReadTime << endl;
	cout << "SDWBit : " << SDWriteData<<"   SDWTime : " << SDWriteTime << endl;
	cout << "DSWBit : " << DSWriteData<<"   DSWTime : " << DSWriteTime << endl;

	cout << std::fixed << std::setprecision(2)<< ((SDReadData / 1000000) / SDReadTime) << endl;
	//cout << SDReadData << "        " << SDReadTime << endl;

	cout << std::fixed << std::setprecision(2)<<(DSReadData / 1000000)/DSReadTime << endl;
	//cout << DSReadData << "        " << DSReadTime << endl;

	cout << std::fixed << std::setprecision(2)<<(SDWriteData /1000000) /SDWriteTime<< endl;
	//cout << SDWriteData << "        " << SDWriteTime << endl;

	cout << std::fixed << std::setprecision(2)<<(DSWriteData / 1000000)/ DSWriteTime<< endl;
	//cout << DSWriteData << "        " << DSWriteTime << endl;

	inFile.close();
	Backup.close();
	outFile.close();
	system("pause");
	return 0;
}
