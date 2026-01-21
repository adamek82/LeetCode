#pragma once
#include <vector>
#include <string>
using namespace std;

class GenerateParentheses_22 {
public:
    vector<string> generateParenthesis(int n);

private:
    static void dfs(int openLeft, int closeLeft,
                    string& cur, vector<string>& out);
};
