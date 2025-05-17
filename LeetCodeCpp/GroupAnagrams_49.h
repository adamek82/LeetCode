#pragma once
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

class GroupAnagrams_49 {
public:
    vector<vector<string>> groupAnagrams_sorting(vector<string>& strs);
    vector<vector<string>> groupAnagrams_counting(vector<string>& strs);
};
