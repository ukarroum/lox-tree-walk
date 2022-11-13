#include <iostream>
#include <fstream>
#include <string>

#include "Scanner.h"

using namespace std;

void report_error(int line, string msg)
{
	cerr << "Error " << msg << " in line " << line;
}

int main(int argc, char **argv)
{
	bool hadError = false;

	Scanner scanner;

	if(argc > 2)
	{
		cout << "Lox Interpreter" << endl;
		cout << "===============" << endl;

		cout << "Usage: " << endl;
		cout << "	lox [script]" << endl;

		return 64;
	}
	else if(argc == 1)
	{
		string row;

		cout << ">>> ";
		while(getline(cin, row))
		{
			scanner.scanTokens(row);
			hadError = false;
			cout << ">>> ";
		}
	}
	else if(argc == 2)
	{
		ifstream sourceFile(argv[1]);
		string row;
		
		while(getline(sourceFile, row))
			scanner.scanTokens(row);

		sourceFile.close();
	}

	if(hadError)
		return 65;

	return 0;
}
