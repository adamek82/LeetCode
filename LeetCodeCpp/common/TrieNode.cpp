#include "TrieNode.h"

TrieNode::TrieNode()
    : TrieNode('\0') {}

TrieNode::TrieNode(char character)
    : character(character),
      terminates(false) {}

TrieNode::~TrieNode() {
    for (const auto& [_, child] : children) {
        delete child;
    }
}

char TrieNode::getChar() const {
    return character;
}

void TrieNode::addWord(const string& word) {
    TrieNode* node = this;

    for (const char c : word) {
        TrieNode* child = node->getChild(c);

        if (child == nullptr) {
            child = new TrieNode(c);
            node->children[c] = child;
        }

        node = child;
    }

    if (!word.empty()) {
        node->setTerminates(true);
    }
}

TrieNode* TrieNode::getChild(char c) {
    const auto it = children.find(c);
    return it != children.end() ? it->second : nullptr;
}

bool TrieNode::terminatesWord() const {
    return terminates;
}

void TrieNode::setTerminates(bool value) {
    this->terminates = value;
}
