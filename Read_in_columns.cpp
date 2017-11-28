using namespace std;
#include<iostream>
#include<fstream>
#include<string>
int main()
{
	int x, row, i;
	string a[200];
	string b[200];
	string c[200];//size of array more than number of entries in data file
	char choice = ' ';
	ifstream infile;
	infile.open("data.txt");//open the text file
	if (!infile)
	{
		cout << "Unable to open file";
		exit(1); // terminate with error
	}
	i = 0;

	while (!infile.eof())
	{
		//To make three arrays for each column (a for 1st column, b for 2nd....)
		infile >> a[i] >> b[i] >> c[i];
		i++;
	}
	cout << a[i-1] << " " << c[i-1] << endl;

	infile.close();
	system("Pause");
	return 0;

}