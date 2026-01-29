#include "ValidParentheses_20.h"
#include <stack>

char ValidParentheses_20::opening_for(char closing) const
{
    switch (closing) {
        case ')': return '(';
        case ']': return '[';
        case '}': return '{';
        default:  return '\0';
    }
}

/*
 * Algorithm: stack-based validation of bracket sequences (O(n) time, O(n) space).
 *
 * Idea:
 * - Push opening brackets onto a stack.
 * - For each closing bracket, the top of the stack must be its matching opening bracket.
 * - If at any point the stack is empty or the types don't match, the string is invalid.
 * - At the end, the stack must be empty (all openings were matched).
 */
bool ValidParentheses_20::isValid(const string& s) const
{
    stack<char> st;

    for (char ch : s) {
        // Push opening brackets onto the stack.
        if (ch == '(' || ch == '[' || ch == '{') {
            st.push(ch);
            continue;
        }

        // For a closing bracket, we must have a matching opening on the stack.
        const char need = opening_for(ch);
        if (need == '\0') return false;          // Defensive: rejects unexpected characters.
        if (st.empty() || st.top() != need) return false;

        st.pop();
    }

    // If the stack is empty, all brackets were matched correctly.
    return st.empty();
}
