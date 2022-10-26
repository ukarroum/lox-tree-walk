#include <string>

using namespace std;

enum class TokenType
{
	LEFT_PAREN, RIGHT_PAREN, LEFT_BRACE, RIGHT_BRACE,
	COMMA, DOT, MINUS, PLUS, SEMICOLON, SLASH, STAR,

	BANG, BANG_EQUAL,
	EQUAL, EQUAL_EQUAL,
	GREATER, GREATER_EQUAL,
	LESS, LESS_EQUAL,

	IDENTIFIER, STRING, NUMBER,

	AND, CLASS, ELSE, FALSE, FUN, FOR, IF, NUL, OR,
	PRINT, RETURN, SUPER, THIS, TRUE, VAR, WHILE

	EOF
};

class Token
{
public:
	Token(TokenType type, string lexeme, int line): m_type(type), m_lexeme(lexeme), m_line(line) {};

private:
	TokenType m_type;
	string m_lexeme;
	int m_line;
};
		
