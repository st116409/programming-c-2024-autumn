#include <iostream>
#include <stack>
#include <queue>
#include <map>
#include <string>
#include <cctype>
#include "Convertor.h"

using namespace std;

int getPrecedence(char op) {
	map<char, int> precedence{
		{'+', 1} , {'-', 1}, {'/', 2}, {'*', 2}, {'^', 3}
	};
	return precedence[op];
}

bool isUnaryMinus(string& expr, int pos) {
	if (expr[pos] != '-') {
		return false;
	}
	if (pos == 0) {
		return true;
	}
	char token = expr[pos - 1];
	return (token == '+' || token == '-' || token == '*' || token == '/' || token == '^' || token == '(');
}

string preprocess(string expr) {
	string res;
	for (int i = 0; i < expr.length(); ++i) {
		char token = expr[i];
		if (isdigit(token) || token == '+' || token == '-' || token == '*' || token == '/' || token == '^' || token == '(' || token == ')' || token == '.') {
			res += (expr[i]);
		}
	}
	return res;
}

queue<string> infixToPostfix(string expression) {
	stack<char> operators;
	queue<string> output;
	
	for (int i = 0; i < expression.length(); ++i) {
		char token = expression[i];

		if (isdigit(token)) {
			string number;
			bool dot = false;
			while (i < expression.length() && (isdigit(expression[i]) || expression[i] == '.')) {
				if (expression[i] == '.' && !dot) {
					number += expression[i];
					dot = true;
				}
				else if (expression[i] != '.') {
					number += expression[i];
				}
				++i;

			}
			--i;
			output.push(number);
		}
		else if (isUnaryMinus(expression, i)) {
			string number;
			number = "-";
			++i;
			bool dot = false;
			while (i < expression.length() && (isdigit(expression[i]) || expression[i] == '.')) {
				if (expression[i] == '.' && !dot) {
					number += expression[i];
					dot = true;
				}
				else if (expression[i] != '.') {
					number += expression[i];
				}
				++i;

			}
			--i;
			output.push(number);
		}
		else if (token == '(') {
			operators.push(token);
		}
		else if (token == ')') {
			while (!operators.empty() && operators.top() != '(') {
				output.push(string(1, operators.top()));
				operators.pop();
			}
			operators.pop();
		}
		else if (token == '+' || token == '-' || token == '*' || token == '/' || token == '^') {
			while (!operators.empty() && operators.top() != '(' && getPrecedence(operators.top()) >= getPrecedence(token)) {
				output.push(string(1, operators.top()));
				operators.pop();
			}
			operators.push(token);
		}

	}

	while (!operators.empty()) {
		output.push(string(1, operators.top()));
		operators.pop();
	}

	return output;
}

double computePostfix(queue<string> postfix)
{
	stack<double> values;
	while (!postfix.empty()) {
		string token = postfix.front();
		postfix.pop();

		if (isdigit(token[0]) || token.length() > 1 && token[0] == '-') {
			values.push(stod(token));
		}
		else {
			double b = values.top();
			values.pop();
			double a = values.top();
			values.pop();

			if (token == "+") {
				values.push(a + b);
			} else if (token == "-") {
				values.push(a - b);
			}
			else if (token == "*") {
				values.push(a * b);
			}
			else if (token == "/") {
				values.push(a / b);
			}
			else if (token == "^") {
				values.push(pow(a,b));
			}
			
		}
	}

	return values.top();
}

