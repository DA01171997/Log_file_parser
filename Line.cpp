#include <string>
using std::string;
class Line
{
private:
	string command;
	string readWrite;
	string data;
public:
	Line(string command, string readWrite, string data)
	{
		this->command = command;
		this->readWrite = readWrite;
		this->data = data;
	}
	string getCommand()
	{
		if (command == "40000810") { return "S-to-D"; }
		else return "D-to-S";
	}
	string getReadWrite()
	{
		if (readWrite == "Rd") { return "Read"; }
		else return "Write";

	}
	int getWordCount()
	{
		//Turn data into base10
		//divide by 2
		return 0;	//temp. Should return data/2
	}
	string getData()
	{
		return data;
	}
};