#include "Combinations_77.h"

#include <algorithm>
#include <utility>

void Combinations_77::generatePickNext(
    int n,
    int k,
    int start,
    vector<int>& current,
    vector<vector<int>>& result)
{
    if (static_cast<int>(current.size()) == k) {
        result.push_back(current);
        return;
    }

    const int remaining = k - static_cast<int>(current.size());
    const int lastCandidate = n - remaining + 1;

    for (int value = start; value <= lastCandidate; ++value) {
        current.push_back(value);
        generatePickNext(n, k, value + 1, current, result);
        current.pop_back();
    }
}

vector<vector<int>> Combinations_77::combinePickNext(int n, int k)
{
    vector<vector<int>> result;
    vector<int> current;
    current.reserve(k);

    generatePickNext(n, k, 1, current, result);

    return result;
}

void Combinations_77::generateTakeSkip(
    int value,
    int k,
    vector<int>& current,
    vector<vector<int>>& result)
{
    if (static_cast<int>(current.size()) == k) {
        vector<int> combination(current.rbegin(), current.rend());
        result.push_back(move(combination));
        return;
    }

    const int remaining = k - static_cast<int>(current.size());

    if (value > remaining) {
        generateTakeSkip(value - 1, k, current, result);
    }

    current.push_back(value);
    generateTakeSkip(value - 1, k, current, result);
    current.pop_back();
}

vector<vector<int>> Combinations_77::combineTakeSkip(int n, int k)
{
    vector<vector<int>> result;
    vector<int> current;
    current.reserve(k);

    generateTakeSkip(n, k, current, result);

    return result;
}
