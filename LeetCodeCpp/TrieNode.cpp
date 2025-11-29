#include "TrieNode.h"

/*
 * Implementation notes for TrieNode
 * ---------------------------------
 * addWord() consumes the input string one character at a time:
 *   - It looks up (or creates) the child node for the first character.
 *   - If more characters remain, it recurses on the remainder of the string.
 *   - If this is the last character, it sets the terminates flag on
 *     the final node.
 *
 * getChild() is a thin wrapper around the children map lookup.
 *
 * The destructor iterates over all entries in children and deletes each
 * child pointer, which recursively frees the entire subtree underneath
 * this node.
 */

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

/*
 * Finds a child node of this node that stores character c.
 * Returns nullptr if no such child is present in the trie.
 */
TrieNode* TrieNode::getChild(char c) {
    auto it = children.find(c);
    return it != children.end() ? it->second : nullptr;
}

/*
 * Returns whether this node represents the end of a complete word.
 */
bool TrieNode::terminatesWord() const {
    return terminates;
}

/*
 * Marks this node as terminating (or not) a complete word.
 */
void TrieNode::setTerminates(bool t) {
    terminates = t;
}

TrieNode::~TrieNode() {
    for (auto& pair : children) {
        delete pair.second;
    }
}
