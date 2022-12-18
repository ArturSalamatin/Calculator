#include <exception>
#include <cmath>

#include "misc_func.h"
#include "Token.h"

Token_stream ts;

double expression()
{
	double left = term();
	Token* t = ts.get();
	while (true)
	{
		switch (t->kind)
		{
		case '+':
			left += term();
			t = ts.get();
			break;
		case '-':
			left -= term();
			t = ts.get();
			break;
		default:
			ts.putback(t);
			return left;
		}
	}
}

double primary()
{
	Token* t = ts.get();
	switch (t->kind)
	{
	case '(':
	{
		double d = expression();
		t = ts.get();
		if (t->kind != ')')
			throw std::exception("Symbol ')' is required");
		return d;
	}
	case '8':
		return t->value;
	case '-':
		return -primary();
	case '+':
		return primary();
	default:
		throw std::exception("Primary expression is required");
	}
}

double term()
{
	double left = primary();
	Token* t = ts.get();
	while (true)
	{
		switch (t->kind)
		{
		case '*':
			left *= primary();
			t = ts.get();
			break;
		case '/':
		{
			double d = primary();
			if (d == 0)
				throw std::exception("Division by zero occured");
			left /= d;
			t = ts.get();
			break;
		}
		case '%':
		{
			double d = primary();
			if (d == 0.0) throw std::exception("%: division by zero");
			left = std::fmod(left, d);
			t = ts.get();
		}
		default:
			ts.putback(t);
			return left;
		}
	}
}