#pragma once
#include <vector>
#include <string>
#include <array>
#include <string_view>
using namespace std;

class LetterCombinations_17 {
public:
    vector<string> letterCombinations(string digits);

private:
    // Keypad mapping indexed by digit - '0' (0/1 map to empty).
    // `inline` + `constexpr` keeps this a single definition across TUs (C++17+).
    inline static constexpr array<string_view, 10> KEYS{
        "", "", "abc", "def", "ghi",
        "jkl", "mno", "pqrs", "tuv", "wxyz"
    };

    static void dfs(const string& digits, int idx,
                    string& path, vector<string>& out);
};
