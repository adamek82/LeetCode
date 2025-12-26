#include "TopKFrequentWords_692.h"

vector<string> TopKFrequentWords_692::topKFrequent(vector<string> &words, int k)
{
    // Count the frequency of each word.
    unordered_map<string, int> freq;
    for (const string &word : words) {
        freq[word]++;
    }

    // Custom comparator for the min-heap.
    // The candidate is considered "worse" if it has a lower frequency,
    // or if frequencies are equal and its word is lexicographically larger.
    auto cmp = [](const pair<string, int>& a, const pair<string, int>& b) {
        if (a.second == b.second)
            return a.first < b.first; // for equal frequencies, word with lower lexical order is "better"
        return a.second > b.second;   // lower frequency is "worse"
    };

    // Use a min-heap of size k.
    priority_queue<pair<string, int>, vector<pair<string, int>>, decltype(cmp)> minHeap(cmp);

    // Push each word-frequency pair into the heap.
    for (auto &entry : freq) {
        minHeap.push(entry);
        if (static_cast<int>(minHeap.size()) > k) {
            minHeap.pop();
        }
    }

    // Gather results from the heap.
    vector<string> result;
    while (!minHeap.empty()) {
        result.push_back(minHeap.top().first);
        minHeap.pop();
    }

    // The words are extracted from the min-heap with the worst candidate first,
    // so we reverse the result to have highest frequency (and lexicographical order) first.
    reverse(result.begin(), result.end());
    return result;
}