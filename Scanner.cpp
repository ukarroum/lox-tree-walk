#include <sstream>

#include "Scanner.h"

vector<string>::Scanner scanTokens(const string & code)
{
	stringstream ss(code);
	string token;
	vector<Token> tokens;

	int line = 1;

	for(int i = 0; i < code.length(); i++)
	{
		switch(code[i])
		{
			case '(':
				tokens.emplace_back(LEFT_PAREN, "", 0);
				break;
			case ')':
				tokens.emplace_back(RIGHT_PARENT, "", 0);
				break;
			case '{':
				tokens.emplace_back(LEFT_BRACE, "", 0);
				break;
			case '}':
				tokens.emplace_back(RIGHT_BRACE, "", 0);
				break;
			case ',':
				tokens.emplace_back(COMMA, "", 0);
				break;
			case '.':
				tokens.emplace_back(DOT, "", 0);
				break;
			case '-':
				tokens.emplace_back(MINUS, "", 0);
				break;
			case '+':
				tokens.emplace_back(PLUS, "", 0);
				break;
			case ';':
				tokens.emplace_back(SEMICOLON, "", 0);
				break;
			case '*':
				tokens.emplace_back(START, "", 0);
				break;
			case '\n':
				line++;	
			case ' ':
			case '\t':
				break;
			default:
				throw std::runtime_error("Unknown token at line");
		}

		i++;

	}
}
