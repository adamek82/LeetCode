#pragma once
#include <string>
#include <vector>
using namespace std;

class LongestCommonPrefix_14 {
public:
    string longestCommonPrefix_Linear(const vector<string>& strs) const;
    string longestCommonPrefix_Sort(const vector<string>& strs) const;
    string longestCommonPrefix_Vertical(const vector<string>& strs) const;
};
