#include <sstream>
#include <unordered_map>

#include "Scanner.h"
#include "Token.h"

using enum TokenType;

vector<string> Scanner::scanTokens(const string & code)
{
	vector<Token> tokens;

	unordered_map<std::string, TokenType> reserved_keywords = {
		{"and", AND},
		{"class", CLASS},
		{"else", ELSE},
		{"false", FALSE},
		{"for", FOR},
		{"fun", FUN},
		{"if", IF},
		{"nil", NIL},
		{"or", OR},
		{"print", PRINT},
		{"return", RETURN},
		{"super", SUPER},
		{"this", THIS},
		{"true", TRUE},
		{"var", VAR},
		{"while", WHILE}
	};

	int line = 1;

	for(int i = 0; i < code.length(); i++)
	{
		switch(code[i])
		{
			case '(':
				tokens.emplace_back(LEFT_PAREN, "", line);
				break;
			case ')':
				tokens.emplace_back(RIGHT_PAREN, "", line);
				break;
			case '{':
				tokens.emplace_back(LEFT_BRACE, "", line);
				break;
			case '}':
				tokens.emplace_back(RIGHT_BRACE, "", line);
				break;
			case ',':
				tokens.emplace_back(COMMA, "", line);
				break;
			case '.':
				tokens.emplace_back(DOT, "", line);
				break;
			case '-':
				tokens.emplace_back(MINUS, "", line);
				break;
			case '+':
				tokens.emplace_back(PLUS, "", line);
				break;
			case ';':
				tokens.emplace_back(SEMICOLON, "", line);
				break;
			case '*':
				tokens.emplace_back(STAR, "", line);
				break;
			case '\n':
				line++;	
			case ' ':
			case '\t':
				break;
			case '!':
				tokens.emplace_back(code[i + 1] == '=' ? BANG_EQUAL : BANG);
				break;
			case '=':
				tokens.emplace_back(code[i + 1] == '=' ? EQUAL_EQUAL : EQUAL);
				break;
			case '<':
				tokens.emplace_back(code[i + 1] == '=' ? LESS_EQUAL : LESS);
				break;
			case '>':
				tokens.emplace_back(code[i + 1] == '=' ? GREATER_EQUAL : GREATER);
				break;
			case '/':
				if(code[i + 1] == '/')
					while(code[i] != '\n')
						i++;
				else
					tokens.emplace_back(SLASH, "", line);
				break;
			case '"':
				int beg = i;
				while(code[i] != '"')
				{
					if(code[i] == '\n')
						line++;
					i++;
				}
				tokens.emplace_back(STRING, code.substr(beg + 1, i - 1), line);
				break;
			default:
				if(code[i] >= '0' && code[i] <= '9')
				{
					int beg = i;
					while(code[i] >= '0' and code[i] <= '9')
					{
						if(code[i] == '\n')
							line++;
						i++;
					}
					if(code[i] == '.')
					{
						i++;

						while(code[i] >= '0' and code[i] <= '9')
						{
							if(code[i] == '\n')
								line++;
							i++;
						}
					}
					tokens.emplace_back(NUMBER, code.substr(beg + 1, i - 1), line);
				}
				else if(isalnum(code[i]) or code[i] == '_')
				{
					int beg = i;
					while(isalnum(code[i]) or code[i] == '_')
					{
						if(code[i] == '\n')
							line++;
						i++;
					}
					if(reserved_keywords.find(code.substr(beg + 1, i - 1)) != reserved_keywords.end())
						tokens.emplace_back(reserved_keywords[code.substr(beg + 1, i - 1)], "", line);
					else
						tokens.emplace_back(IDENTIFIER, code.substring(beg + 1, i - 1), line);
				}

				else	
					throw std::runtime_error("Unknown token at line");
		}

		i++;

	}
}
