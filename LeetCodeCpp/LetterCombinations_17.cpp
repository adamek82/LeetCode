#include "LetterCombinations_17.h"

/*
 * Backtracking:
 *   - If we've placed letters for all digits, push the built string.
 *   - Otherwise, iterate all letters for the current digit and recurse.
 */
void LetterCombinations_17::dfs(const string& digits, int idx,
                                string& path, vector<string>& out) {
    if (idx == (int)digits.size()) {
        out.push_back(path);
        return;
    }

    const string_view letters = KEYS[digits[idx] - '0'];

    for (char ch : letters) {
        path.push_back(ch);
        dfs(digits, idx + 1, path, out);
        path.pop_back();
    }
}

vector<string> LetterCombinations_17::letterCombinations(string digits) {
    if (digits.empty()) return {};

    vector<string> out;
    string path;
    path.reserve(digits.size());
    dfs(digits, 0, path, out);

    return out;
}
