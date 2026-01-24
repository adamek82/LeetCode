#include "SortCharactersByFrequency_451.h"
#include <vector>
#include <unordered_map>

string SortCharactersByFrequency_451::frequencySort(string s)
{
    // 1. Count frequencies
    unordered_map<char,int> freq;
    for (char c : s) {
        ++freq[c];
    }

    // 2. Bucket characters by frequency
    //    buckets[i] will contain all chars that appear exactly i times,
    //    as a string with each char repeated i times.
    vector<string> buckets(s.size() + 1);
    for (auto& [ch, count] : freq) {
        // append 'count' copies of ch into buckets[count]
        buckets[count].append(count, ch);
    }

    // 3. Build result by scanning buckets from high to low frequency
    string result;
    result.reserve(s.size());
    for (int f = buckets.size() - 1; f > 0; --f) {
        if (!buckets[f].empty()) {
            result += buckets[f];
        }
    }

    return result;
}
