#include "TrieNode.h"

TrieNode::TrieNode() : character(0), terminates(false) {}

TrieNode::TrieNode(char character) : character(character), terminates(false) {}

char TrieNode::getChar() const {
    return character;
}

void TrieNode::addWord(const string& word) {
    if (word.empty()) {
        return;
    }

    char firstChar = word[0];
    TrieNode* child = getChild(firstChar);
    if (child == nullptr) {
        child = new TrieNode(firstChar);
        children[firstChar] = child;
    }

    if (word.length() > 1) {
        child->addWord(word.substr(1));
    } else {
        child->setTerminates(true);
    }
}

// Find a child node of this node that has the char argument as its
// data. Return null if no such child node is present in the trie.
TrieNode* TrieNode::getChild(char c) {
    auto it = children.find(c);
    return it != children.end() ? it->second : nullptr;
}

// Returns whether this node represents the end of a complete word.
bool TrieNode::terminatesWord() const {
    return terminates;
}

// Set whether this node is the end of a complete word.
void TrieNode::setTerminates(bool t) {
    terminates = t;
}

TrieNode::~TrieNode() {
    for (auto& pair : children) {
        delete pair.second;
    }
}
