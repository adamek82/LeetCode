#include "ValidParentheses_20.h"

bool ValidParentheses_20::isValid(std::string s)
{
    std::stack<char> stack;
    for (char ch : s) {
        // Push opening brackets onto the stack
        if (ch == '(' || ch == '[' || ch == '{') {
            stack.push(ch);
        } else {
            // If stack is empty, there's no corresponding opening bracket
            if (stack.empty()) return false;

            // Check if the top of the stack matches the current closing bracket
            char top = stack.top();
            if ((ch == ')' && top == '(') ||
                (ch == ']' && top == '[') ||
                (ch == '}' && top == '{')) {
                stack.pop();
            } else {
                return false;
            }
        }
    }

    // If the stack is empty, all brackets were matched correctly
    return stack.empty();
}