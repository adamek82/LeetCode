#pragma once
#include <string>

using namespace std;

class ValidParentheses_20 {
private:
    // Returns the expected opening bracket for a given closing bracket,
    // or '\0' if the character is not a recognized closing bracket.
    char opening_for(char closing) const;

public:
    // Checks if the input string has properly nested and matched brackets.
    bool isValid(const string& s) const;
};
