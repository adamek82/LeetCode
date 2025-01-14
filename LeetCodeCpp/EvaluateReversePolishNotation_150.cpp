#include "EvaluateReversePolishNotation_150.h"

int EvaluateReversePolishNotation_150::evalRPN(std::vector<std::string> &tokens)
{
    std::stack<int> stk;

    for (const std::string& token : tokens) {
        if (isOperator(token)) {
            if (stk.size() < 2) {
                throw std::invalid_argument("Insufficient operands for the operator");
            }
            int b = stk.top();
            stk.pop();
            int a = stk.top();
            stk.pop();
            stk.push(applyOperator(a, b, token));
        } else {
            stk.push(stoi(token));
        }
    }

    if (stk.size() != 1) {
        throw std::invalid_argument("Invalid RPN expression");
    }

    return stk.top();
}

bool EvaluateReversePolishNotation_150::isOperator(const std::string &token)
{
    return token == "+" || token == "-" || token == "*" || token == "/";
}

int EvaluateReversePolishNotation_150::applyOperator(int a, int b, const std::string &op)
{
    if (op == "+") return a + b;
    if (op == "-") return a - b;
    if (op == "*") return a * b;
    if (op == "/") return a / b; // Division truncates toward zero by default for integers
    throw std::invalid_argument("Unknown operator");
}
