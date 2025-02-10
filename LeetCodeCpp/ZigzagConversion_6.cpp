#include "ZigzagConversion_6.h"

std::string ZigzagConversion_6::convert_rowWise(std::string s, int numRows)
{
    if (numRows == 1 || s.length() <= numRows) return s;
        
    std::vector<std::string> rows(std::min(numRows, int(s.length())));
    int currRow = 0;
    bool goingDown = false;
    
    for (char c : s) {
        rows[currRow] += c;
        if (currRow == 0 || currRow == numRows - 1) goingDown = !goingDown;
        currRow += goingDown ? 1 : -1;
    }
    
    std::string result;
    for (std::string &row : rows) {
        result += row;
    }
    
    return result;
}

/*
 * Zigzag Conversion Explanation:
 *
 * Given a string and a number of rows, the characters are arranged in a zigzag pattern
 * and then read row by row. The key observation is that characters repeat in a cycle
 * of length d = (numRows - 1) * 2. Each row follows a specific index pattern.
 *
 * Example for numRows = 6:
 *
 * T         Z         I
 * H       G A       S O
 * I     I   G     R   N
 * S   Z     C   E     T
 * I A       O V       E T
 * S         N         S
 *
 * Cycle length: d = (numRows - 1) * 2 = 10
 * Characters appear at specific indices:
 *
 * Row 0:  0 10 20             (step: 10 10 10)
 * Row 1:  1 9 11 19 21        (step: 8 2 8 2)
 * Row 2:  2 8 12 18 22        (step: 6 4 6 4)
 * Row 3:  3 7 13 17 23        (step: 4 6 4 6)
 * Row 4:  4 6 14 16 24 26     (step: 2 8 2 8 2)
 * Row 5:  5 15 25             (step: 10 10 10)
 *
 * The alternation between step sizes ensures correct zigzag traversal:
 * - The first and last row use a fixed step of d.
 * - Middle rows alternate between two step sizes: d - 2*i and 2*i.
 * - Switching occurs only when the step size is not initially equal to d.
 */

std::string ZigzagConversion_6::convert_jumpPattern(std::string s, int numRows) {
    if (numRows == 1) return s;
    int N = s.size(), d = (numRows - 1) * 2;
    std::string ans;
    for (int i = 0; i < numRows; ++i) {
        int w = 2 * i;
        for (int j = i; j < N;) {
            ans += s[j];
            w = d - w ? d - w : d;
            j += w;
        }
    }
    return ans;
}
