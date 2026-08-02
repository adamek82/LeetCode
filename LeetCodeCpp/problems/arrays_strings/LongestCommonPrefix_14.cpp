#include "LongestCommonPrefix_14.h"
#include <algorithm>

string LongestCommonPrefix_14::longestCommonPrefix_Horizontal(const vector<string>& strs) const
{
    if (strs.empty())
        return "";

    const string& base = strs[0];
    size_t prefixLength = base.size();

    for (size_t i = 1; i < strs.size(); ++i) {
        const string& s = strs[i];
        const size_t limit = min(prefixLength, s.size());

        size_t j = 0;
        while (j < limit && base[j] == s[j])
            ++j;

        prefixLength = j;

        if (prefixLength == 0)
            return "";
    }

    return base.substr(0, prefixLength);
}

string LongestCommonPrefix_14::longestCommonPrefix_Vertical(const vector<string>& strs) const
{
    if (strs.empty())
        return "";

    const string& base = strs[0];

    for (size_t j = 0; j < base.size(); ++j) {
        const char c = base[j];

        for (size_t i = 1; i < strs.size(); ++i) {
            const string& s = strs[i];

            if (j >= s.size() || s[j] != c)
                return base.substr(0, j);
        }
    }

    return base;
}

string LongestCommonPrefix_14::longestCommonPrefix_Sort(const vector<string>& strs) const
{
    if (strs.empty())
        return "";

    vector<string> sorted = strs;
    sort(sorted.begin(), sorted.end());

    const string& first = sorted.front();
    const string& last = sorted.back();
    const size_t limit = min(first.size(), last.size());

    size_t prefixLength = 0;
    while (prefixLength < limit && first[prefixLength] == last[prefixLength]) {
        ++prefixLength;
    }

    return first.substr(0, prefixLength);
}
