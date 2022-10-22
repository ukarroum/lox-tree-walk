#include <iostream>

using namespace std;

int main(int argc, char **argv)
{
	if(argc > 2)
	{
		cout << "Lox Interpreter" << endl;
		cout << "===============" << endl;

		cout << "Usage: " << endl;
		cout << "	lox [script]" << endl;

		return 64;
	}

	return 0;
}
