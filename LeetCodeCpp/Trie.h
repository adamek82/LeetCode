#pragma once
#include <vector>
#include <string>
#include "TrieNode.h"

using namespace std;

class Trie {
private:
    TrieNode* root;

public:
    void insert(const string& word);
    bool search(const string& word);
    bool startsWith(const string& prefix);

    Trie();
    Trie(const vector<string>& list);
    Trie(const initializer_list<string>& list);
    bool contains(const string& prefix, bool exact = false) const;
    TrieNode* getRoot() const;
    ~Trie();
};
