#include "WordLadder_127.h"

#include <queue>
#include <unordered_set>

int WordLadder_127::ladderLength(
    const string& beginWord,
    const string& endWord,
    const vector<string>& wordList) {

    unordered_set<string> words(wordList.begin(), wordList.end());

    if (!words.contains(endWord)) {
        return 0;
    }

    queue<string> nodes;
    nodes.push(beginWord);

    words.erase(beginWord);

    int length = 1;

    while (!nodes.empty()) {
        const size_t levelSize = nodes.size();

        for (size_t i = 0; i < levelSize; ++i) {
            string word = nodes.front();
            nodes.pop();

            if (word == endWord) {
                return length;
            }

            for (size_t pos = 0; pos < word.size(); ++pos) {
                const char original = word[pos];

                for (char c = 'a'; c <= 'z'; ++c) {
                    if (c == original) {
                        continue;
                    }

                    word[pos] = c;

                    const auto it = words.find(word);
                    if (it != words.end()) {
                        nodes.push(word);
                        words.erase(it);
                    }
                }

                word[pos] = original;
            }
        }

        ++length;
    }

    return 0;
}
