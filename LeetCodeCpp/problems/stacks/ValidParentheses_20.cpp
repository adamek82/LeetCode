#include "ValidParentheses_20.h"

#include <stack>

bool ValidParentheses_20::isValid(const string& s) const
{
    stack<char> expectedClosings;

    for (const char ch : s) {
        switch (ch) {
            case '(':
                expectedClosings.push(')');
                break;

            case '[':
                expectedClosings.push(']');
                break;

            case '{':
                expectedClosings.push('}');
                break;

            default:
                if (expectedClosings.empty() ||
                    expectedClosings.top() != ch) {
                    return false;
                }

                expectedClosings.pop();
        }
    }

    return expectedClosings.empty();
}
