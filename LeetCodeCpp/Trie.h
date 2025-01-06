#pragma once
#include <vector>
#include <string>
#include "TrieNode.h"

class Trie {
private:
    TrieNode* root;

public:
    void insert(const std::string& word);
    bool search(const std::string& word);
    bool startsWith(const std::string& prefix);

    Trie();
    Trie(const std::vector<std::string>& list);
    Trie(const std::initializer_list<std::string>& list);
    bool contains(const std::string& prefix, bool exact = false) const;
    TrieNode* getRoot() const;
    ~Trie();
};
