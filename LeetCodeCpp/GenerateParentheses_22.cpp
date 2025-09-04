#include "GenerateParentheses_22.h"

void GenerateParentheses_22::dfs(int openLeft, int closeLeft,
                                 string& cur, vector<string>& out) {
    if (openLeft == 0 && closeLeft == 0) {
        out.push_back(cur);
        return;
    }
    if (openLeft > 0) {
        cur.push_back('(');
        dfs(openLeft - 1, closeLeft, cur, out);
        cur.pop_back();
    }
    if (closeLeft > openLeft) { // only close if we have more ')' remaining than '('
        cur.push_back(')');
        dfs(openLeft, closeLeft - 1, cur, out);
        cur.pop_back();
    }
}

vector<string> GenerateParentheses_22::generateParenthesis(int n) {
    vector<string> out;
    string cur;
    cur.reserve(n * 2);
    dfs(n, n, cur, out);
    return out;
}
