#include "TrieNode.h"

using namespace std;

void TrieNode::addWord(const string& word)
{
    TrieNode* node = this;

    for (const char c : word) {
        auto& child = node->children[c];
        if (child == nullptr) {
            child = make_unique<TrieNode>();
        }
        node = child.get();
    }

    node->terminates = true;
}

TrieNode* TrieNode::getChild(char c)
{
    const auto it = children.find(c);
    return it != children.end() ? it->second.get() : nullptr;
}

const TrieNode* TrieNode::getChild(char c) const
{
    const auto it = children.find(c);
    return it != children.end() ? it->second.get() : nullptr;
}

bool TrieNode::terminatesWord() const
{
    return terminates;
}
