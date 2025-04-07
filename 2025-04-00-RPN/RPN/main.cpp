#include <iostream>
#include <string>
#include <queue>
#include "Convertor.h"

using namespace std;

void printPostfix(queue<string> postfix) {
	while (!postfix.empty()) {
		cout << postfix.front() << " ";
		postfix.pop();
	}
}

int main(int argc, char* argv[]) {
	bool exit = false;
	while (!exit) {
		cout << "#Enter an infix expression:" << "\n";
		string expr;
		getline(cin, expr);
		system("cls");

		if (expr[0] == '0') {
			exit = true;
		}
		else {
			expr = preprocess(expr);
			queue<string> postfix = infixToPostfix(expr);
			cout << "Postfix notation:\n";
			printPostfix(postfix);
			cout << "\n"<< "Evaluation:\n" << computePostfix(postfix) << "\n";
		}
	}

	


	return EXIT_SUCCESS;
}