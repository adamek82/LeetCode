#include "ZigzagConversion_6.h"
#include <algorithm>
#include <vector>

string ZigzagConversion_6::convertRowWise(const string& s, int numRows)
{
    if (numRows == 1 || s.size() <= static_cast<size_t>(numRows))
        return s;

    vector<string> rows(numRows);

    int row = 0;
    int direction = 1;

    for (char ch : s) {
        rows[row] += ch;

        if (row == 0)
            direction = 1;
        else if (row == numRows - 1)
            direction = -1;

        row += direction;
    }

    string result;
    result.reserve(s.size());

    for (const auto& currentRow : rows)
        result += currentRow;

    return result;
}

string ZigzagConversion_6::convertJumpPattern(const string& s, int numRows)
{
    if (numRows == 1 || s.size() <= static_cast<size_t>(numRows))
        return s;

    const size_t cycleLength =
        static_cast<size_t>(2 * (numRows - 1));

    string result;
    result.reserve(s.size());

    for (int row = 0; row < numRows; ++row) {
        const size_t rowIndex = static_cast<size_t>(row);

        for (size_t cycleStart = 0;
             cycleStart + rowIndex < s.size();
             cycleStart += cycleLength) {
            result += s[cycleStart + rowIndex];

            const size_t diagonalIndex =
                cycleStart + cycleLength - rowIndex;

            if (row != 0 &&
                row != numRows - 1 &&
                diagonalIndex < s.size()) {
                result += s[diagonalIndex];
            }
        }
    }

    return result;
}
