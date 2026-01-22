#pragma once
#include <vector>
#include <string>

using namespace std;

class EvaluateReversePolishNotation_150 {
public:
    int evalRPN(vector<string>& tokens);
private:
    bool isOperator(const string& token);
    int applyOperator(int a, int b, const string& op);
};