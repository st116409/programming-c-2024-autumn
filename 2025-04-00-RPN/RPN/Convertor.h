#pragma once
#include <queue>

using namespace std;

int getPrecedence(char op);
queue<string> infixToPostfix(string expression);
double computePostfix(queue<string> postfix);
bool isUnaryMinus(const string& expr, int pos);
string preprocess(string expr);