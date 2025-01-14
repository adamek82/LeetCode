#pragma once
#include <vector>
#include <string>
#include <stack>
#include <cstdlib>
#include <stdexcept>

class EvaluateReversePolishNotation_150 {
public:
    int evalRPN(std::vector<std::string>& tokens);
private:
    bool isOperator(const std::string& token);
    int applyOperator(int a, int b, const std::string& op);
};