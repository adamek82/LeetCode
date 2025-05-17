#include "GroupAnagrams_49.h"

vector<vector<string>> GroupAnagrams_49::groupAnagrams_sorting(vector<string> &strs)
{
    unordered_map<string, vector<string>> anagramGroups;

    for (const string& s : strs) {
        string sortedStr = s;
        sort(sortedStr.begin(), sortedStr.end()); // Sort the string to create a key
        anagramGroups[sortedStr].push_back(s);
    }

    vector<vector<string>> result;
    result.reserve(anagramGroups.size());
    for (auto& [_, group] : anagramGroups) {
        result.push_back(move(group)); // Move to avoid unnecessary copies
    }

    return result;
}

vector<vector<string>> GroupAnagrams_49::groupAnagrams_counting(vector<string> &strs)
{
    unordered_map<string, vector<string>> anagrams;
    for (const string& s : strs) {
        string key(26, '0');
        for (char c : s) key[c - 'a']++;
        anagrams[key].push_back(s);
    }

    // Correct way to construct result
    vector<vector<string>> result;
    result.reserve(anagrams.size());
    for (auto& [key, group] : anagrams) {
        result.push_back(move(group)); // Move to avoid unnecessary copying
    }

    return result;
}
