#include "IsSubsequence_392.h"
#include <algorithm>
#include <cassert>

void IsSubsequence_392::preprocess_PosIndex(const string& t)
{
    t_ = t;

    for (auto& positions : pos_)
        positions.clear();

    for (size_t i = 0; i < t_.size(); ++i)
        pos_[t_[i] - 'a'].push_back(i);

    hasPosIndex_ = true;
}

void IsSubsequence_392::preprocess_NextTable(const string& t)
{
    t_ = t;
    const size_t n = t_.size();

    nextPos_.assign(n + 1, {});
    nextPos_[n].fill(n);

    for (size_t i = n; i-- > 0;) {
        nextPos_[i] = nextPos_[i + 1];
        nextPos_[i][col(t_[i])] = i;
    }

    hasNextTable_ = true;
}

bool IsSubsequence_392::isSubsequence_TwoPointer(const string& s, const string& t) const
{
    size_t i = 0;
    size_t j = 0;

    while (i < s.size() && j < t.size()) {
        if (s[i] == t[j])
            ++i;

        ++j;
    }

    return i == s.size();
}

bool IsSubsequence_392::isSubsequence_PosIndex(const string& s) const
{
    assert(hasPosIndex_ && "Call preprocess_PosIndex(t) before using this method.");

    size_t nextPosition = 0;

    for (char c : s) {
        const auto& positions = pos_[c - 'a'];
        const auto it = lower_bound(positions.begin(), positions.end(), nextPosition);

        if (it == positions.end())
            return false;

        nextPosition = *it + 1;
    }

    return true;
}

bool IsSubsequence_392::isSubsequence_NextTable(const string& s) const
{
    assert(hasNextTable_ && "Call preprocess_NextTable(t) before using this method.");

    size_t nextPosition = 0;

    for (char c : s) {
        const size_t position = nextPos_[nextPosition][col(c)];

        if (position == t_.size())
            return false;

        nextPosition = position + 1;
    }

    return true;
}
