#pragma once
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>

class GroupAnagrams_49 {
public:
    std::vector<std::vector<std::string>> groupAnagrams_sorting(std::vector<std::string>& strs);
    std::vector<std::vector<std::string>> groupAnagrams_counting(std::vector<std::string>& strs);
};
