#pragma once

class Token;

class Token_stream
{
public:
	Token* get();
	void putback(Token* t);
private:
	bool full{ false };
	Token* buffer;
};

