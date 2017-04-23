#pragma once
#include "Token.h"
#include <vector>

using namespace std;

//This class let you parse string to vector of tokens
class Lexer {
private:
	const int size;
	const string input;
	const string OPERATOR_CHARS = "+-*/";
	const TokenType OPERATOR_TOKENS[4] = {
		PLUS, MINUS,
		STAR, SLASH
	};
	vector<Token> result;
	int pos = 0;

	//Register tokens with data
	void addToken(TokenType type, string value) {
		Token t(type, value);
		result.push_back(t);
	}

	//Register tokens without data (Like operators)
	void addToken(TokenType type) {
		addToken(type, "");
	}

	//This method returns a char at some position
	char get(int relativePosition) {
		int position = pos + relativePosition;
		if (position >= size) return '\0';
		return input[position];
	}

	//This method returns a char at next position
	char next() {
		pos++;
		return get(0);
	}

	//Tokenize string to operator(+, -, *, /, ...)
	void tokenizeOperator() {
		char current = get(0);
		addToken(OPERATOR_TOKENS[OPERATOR_CHARS.find(current)]);
		pos++;
	}

public:
	Lexer(string input) : input(input), size(input.size()) {}

	//This method tokenize string to vector of tokens
	vector<Token> tokenize() {
		char current;
		while ((current = get(0)) != '\0') {
			if (OPERATOR_CHARS.find(current) != -1) tokenizeOperator();
			else pos++;	//Whitespaces
		}
		return result;
	}
};