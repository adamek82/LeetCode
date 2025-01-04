#include "Trie.h"

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
