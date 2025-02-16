#include "ValidAnagram_242.h"

bool ValidAnagram_242::isAnagram(std::string s, std::string t)
{
    if (s.length() != t.length()) return false;

    std::vector<int> count(26, 0);
    for (char c : s) count[c - 'a']++;
    for (char c : t) count[c - 'a']--;

    for (int freq : count) {
        if (freq != 0) return false;
    }
    return true;
}