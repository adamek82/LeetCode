#include "GroupAnagrams_49.h"
#include <unordered_map>
#include <algorithm>
#include <utility>  // for std::move

/*
 * Hash-map + sorting based grouping of anagrams.
 *
 * For each string:
 * - Make a copy and sort its characters; the sorted string becomes a canonical
 *   key for its anagram group (all anagrams share the same sorted form).
 * - Insert the original string into an unordered_map under this key.
 * At the end, move each map value (vector of strings) into the result vector.
 *
 * Time complexity:
 * Let n be the number of strings and k the maximum string length.
 * For each string we copy O(k) characters and sort them in O(k log k),
 * so the total time is O(n * k log k) overall. Hash-map operations are
 * O(1) on average and do not change the asymptotic bound.
 */
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

/*
 * Hash-map + fixed-size character-count key grouping of anagrams.
 *
 * For each string:
 * - Build a 26-character key where each position stores the count of a letter
 *   ('a'..'z'); anagrams with the same letter counts share the same key.
 * - Use this key as the unordered_map key and append the original string to
 *   the corresponding group.
 * Finally, move all groups from the map into the result vector.
 *
 * Time complexity:
 * For each of n strings of maximum length k we:
 * - Initialize a 26-character key in O(26) = O(1),
 * - Scan the string once and update counts in O(k).
 * Thus the total running time is O(n * k), assuming the alphabet size (26)
 * is constant. Hash-map operations are O(1) on average.
 */
vector<vector<string>> GroupAnagrams_49::groupAnagrams_counting(vector<string> &strs)
{
    unordered_map<string, vector<string>> anagramGroups;
    for (const string& s : strs) {
        /*
         * We store 26 letter counts directly in a std::string used as the hash key.
         * Using '\0' as the initial value is safe under the problem constraints:
         * each word length <= 100, so each counter stays in [0..100], which fits in 7 bits.
         * This avoids relying on ASCII (e.g. starting from '0') and, more importantly,
         * prevents signed-char overflow: if `char` is signed on a given platform and we
         * increment past 127 (e.g. with '0' + 100 == 148), that would be Undefined Behavior.
         */
        string key(26, '\0');
        for (char c : s) key[c - 'a']++;
        anagramGroups[key].push_back(s);
    }

    // Correct way to construct result
    vector<vector<string>> result;
    result.reserve(anagramGroups.size());
    for (auto& [_, group] : anagramGroups) {
        result.push_back(move(group)); // Move to avoid unnecessary copying
    }

    return result;
}
