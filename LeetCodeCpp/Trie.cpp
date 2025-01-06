#include "Trie.h"

Trie::Trie() {
    root = new TrieNode();
}

Trie::Trie(const std::vector<std::string>& list) {
    root = new TrieNode();
    for (const auto& word : list) {
        root->addWord(word);
    }
}

Trie::Trie(const std::initializer_list<std::string>& list) {
    root = new TrieNode();
    for (const auto& word : list) {
        root->addWord(word);
    }
}

void Trie::insert(const std::string& word) {
    root->addWord(word);
}

bool Trie::search(const std::string& word) {
    return contains(word, true);
}

bool Trie::startsWith(const std::string& prefix) {
    return contains(prefix, false);
}

bool Trie::contains(const std::string& prefix, bool exact) const {
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
