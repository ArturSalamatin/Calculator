#pragma once
#include "Token.h"

class token_test
{
	public:
	static void test1()
	{
		Token t;
		t.kind = '+';
		Token t2;
		t2.kind = '8';
		t2.value = 3.14;
	}
};