#pragma once
#include "TokenType.h"
#include <string>

using namespace std;

//This class is token. Contains type and value
class Token {
private:
	const string value;
	const TokenType type;

public:
	Token(TokenType type, string value) : type(type), value(value) {}

	//Returns type of token
	TokenType getType() {
		return type;
	}

	//Returns value of token
	string getValue() {
		return value;
	}
};