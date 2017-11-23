//File: parser.h
//Group Charlie's Members: Abhyuday Vatsavai, Duy Do, Hasibullah Ziai, Jason Lieu
//Course: CPSC 254 Tue Thr 6:00
//Start Date: 11/22/2017 -Duy Do
//Date last Modified: 11/22/2017 5:40PM -Duy Do 
//#pragma once
#include<string>
using std::string;

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
