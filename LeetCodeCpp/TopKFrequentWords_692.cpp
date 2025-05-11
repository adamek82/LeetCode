#include "TopKFrequentWords_692.h"

std::vector<std::string> TopKFrequentWords_692::topKFrequent(std::vector<std::string> &words, int k)
{
    // Count the frequency of each word.
    std::unordered_map<std::string, int> freq;
    for (const std::string &word : words) {
        freq[word]++;
    }
    
    // Custom comparator for the min-heap.
    // The candidate is considered "worse" if it has a lower frequency,
    // or if frequencies are equal and its word is lexicographically larger.
    auto cmp = [](const std::pair<std::string, int>& a, const std::pair<std::string, int>& b) {
        if (a.second == b.second)
            return a.first < b.first; // for equal frequencies, word with lower lexical order is "better"
        return a.second > b.second;   // lower frequency is "worse"
    };
    
    // Use a min-heap of size k.
    std::priority_queue<std::pair<std::string, int>, std::vector<std::pair<std::string, int>>, decltype(cmp)> minHeap(cmp);
    
    // Push each word-frequency pair into the heap.
    for (auto &entry : freq) {
        minHeap.push(entry);
        if ((int)minHeap.size() > k) {
            minHeap.pop();
        }
    }
    
    // Gather results from the heap.
    std::vector<std::string> result;
    while (!minHeap.empty()) {
        result.push_back(minHeap.top().first);
        minHeap.pop();
    }
    
    // The words are extracted from the min-heap with the worst candidate first,
    // so we reverse the result to have highest frequency (and lexicographical order) first.
    std::reverse(result.begin(), result.end());
    return result;
}