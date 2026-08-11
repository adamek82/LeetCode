#include "ImplementTrie_208.h"

Trie::Trie()
    : root(new TrieNode()) {}

Trie::Trie(const vector<string>& list)
    : Trie() {
    insertAll(list);
}

Trie::Trie(const initializer_list<string>& list)
    : Trie() {
    insertAll(list);
}

Trie::~Trie() {
    delete root;
}

void Trie::insert(const string& word) {
    root->addWord(word);
}

bool Trie::search(const string& word) const {
    return contains(word, true);
}

bool Trie::startsWith(const string& prefix) const {
    return contains(prefix, false);
}

TrieNode* Trie::getRoot() const {
    return root;
}

bool Trie::contains(const string& prefix, bool exact) const {
    TrieNode* node = root;

    for (const char c : prefix) {
        node = node->getChild(c);
        if (node == nullptr) {
            return false;
        }
    }

    return !exact || node->terminatesWord();
}
