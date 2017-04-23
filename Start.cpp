//The main file 

#include <iostream>

#include "Lexer.h"

using namespace std;

int main() {
	const string code = "+-*/"; // Write here your code.
	Lexer l(code);
	vector<Token> result = l.tokenize();
	for (int d = 0; d < result.size(); d++)
		cout << result[d].getType() << " : " << result[d].getValue() << endl;
	return 0;
}