#include "GroupAnagrams_49.h"

std::vector<std::vector<std::string>> GroupAnagrams_49::groupAnagrams_sorting(std::vector<std::string> &strs)
{
    std::unordered_map<std::string, std::vector<std::string>> anagramGroups;

    for (const std::string& s : strs) {
        std::string sortedStr = s;
        std::sort(sortedStr.begin(), sortedStr.end()); // Sort the string to create a key
        anagramGroups[sortedStr].push_back(s);
    }

    std::vector<std::vector<std::string>> result;
    result.reserve(anagramGroups.size());
    for (auto& [_, group] : anagramGroups) {
        result.push_back(move(group)); // Move to avoid unnecessary copies
    }

    return result;
}

std::vector<std::vector<std::string>> GroupAnagrams_49::groupAnagrams_counting(std::vector<std::string> &strs)
{
    std::unordered_map<std::string, std::vector<std::string>> anagrams;
    for (const std::string& s : strs) {
        std::string key(26, '0');
        for (char c : s) key[c - 'a']++;
        anagrams[key].push_back(s);
    }

    // Correct way to construct result
    std::vector<std::vector<std::string>> result;
    result.reserve(anagrams.size());
    for (auto& [key, group] : anagrams) {
        result.push_back(move(group)); // Move to avoid unnecessary copying
    }

    return result;
}
