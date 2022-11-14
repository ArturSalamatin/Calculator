#include <exception>
#include <iostream>
#include "Token_stream.h"
#include "Token.h"


void Token_stream::putback(Token* t)
{
	if (full) std::exception("putback(): buffer is full");
	buffer = t;
	full = true;
}

Token* Token_stream::get()
{
	if (full)
	{
		full = false;
		return buffer;
	}

	char ch;
	std::cin >> ch;

	switch (ch)
	{
	case ';' :
	case 'q':
	case '(': case ')': case '+':
	case '-': case '*': case '/':
		return new Token{ ch }; // symbol represents itself
	case '.':
	case '0': case '1': case '2': case '3': case '4':
	case '5': case '6': case '7': case '8': case '9':
	{
		std::cin.putback(ch);
		double val;
		std::cin >> val;
		return new Token{ '8', val };
	}
	default:
		std::exception("Wrong token");
	}


}