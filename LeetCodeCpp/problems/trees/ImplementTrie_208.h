#pragma once

#include <initializer_list>
#include <string>
#include <vector>

#include "common/TrieNode.h"

using namespace std;

class Trie {
public:
    Trie();
    Trie(const vector<string>& list);
    Trie(const initializer_list<string>& list);
    ~Trie();

    Trie(const Trie&) = delete;
    Trie& operator=(const Trie&) = delete;

    void insert(const string& word);

    bool search(const string& word) const;
    bool startsWith(const string& prefix) const;

    TrieNode* getRoot() const;

private:
    TrieNode* root;

    template <typename Range>
    void insertAll(const Range& list) {
        for (const auto& word : list) {
            root->addWord(word);
        }
    }

    bool contains(const string& prefix, bool exact) const;
};
