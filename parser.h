//File: parser.h
//Group Charlie's Members: Abhyuday Vatsavai, Duy Do, Hasibullah Ziai, Jason Lieu
//Course: CPSC 254 Tue Thr 6:00
//Start Date: 11/22/2017 -Duy Do
//Date last Modified: 11/22/2017 5:40PM -Duy Do 
//#pragma once
#include<string>
using std::string;
float getTime(string n){
switch(n.substr( n.length() - 2, 2)){
case "ms":
	float milliTime=static_cast<float>(n.substr(0,n.length()-2));
	float decTime = milliTime * 0.001;
	return decTime;

case "ns":
	float nanoTime=static_cast<float>(n.substr(0,n.length()-2));
	float decTime = nanoTime * 0.000001;
	return decTime;

case "us":
	float microTime=static_cast<float>(n.substr(0,n.length()-2));
	float decTime = microTime * 0.000000001;
	return decTime;

default:
}
)
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
//#pragma once
