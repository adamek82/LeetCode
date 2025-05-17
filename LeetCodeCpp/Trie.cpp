#include "Trie.h"

Trie::Trie() {
    root = new TrieNode();
}

Trie::Trie(const vector<string>& list) {
    root = new TrieNode();
    for (const auto& word : list) {
        root->addWord(word);
    }
}

Trie::Trie(const initializer_list<string>& list) {
    root = new TrieNode();
    for (const auto& word : list) {
        root->addWord(word);
    }
}

void Trie::insert(const string& word) {
    root->addWord(word);
}

bool Trie::search(const string& word) {
    return contains(word, true);
}

bool Trie::startsWith(const string& prefix) {
    return contains(prefix, false);
}

bool Trie::contains(const string& prefix, bool exact) const {
    TrieNode* lastNode = root;
    for (char c : prefix) {
        lastNode = lastNode->getChild(c);
        if (lastNode == nullptr) {
            return false;
        }
    }
    return !exact || lastNode->terminatesWord();
}

TrieNode* Trie::getRoot() const {
    return root;
}

Trie::~Trie() {
    delete root;
}
