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

    /*
     * Iterate frequencies from high to low using size_t (the type returned by buckets.size()).
     * The idiom `for (size_t f = buckets.size(); f-- > 1; )` walks f = size-1 ... 1 without
     * ever going negative (important for unsigned), avoids size_t->int narrowing warnings,
     * and naturally skips bucket[0] which is unused for "frequency 0".
     */
    for (size_t f = buckets.size(); f-- > 1; ) {   // f: size-1 ... 1
        if (!buckets[f].empty()) {
            result += buckets[f];
        }
    }

    return result;
}
