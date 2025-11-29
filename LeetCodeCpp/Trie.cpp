#include "Trie.h"

/*
 * Trie (prefix tree) implementation
 * ---------------------------------
 * Data structure:
 *   - The Trie owns a single root TrieNode that represents the empty prefix.
 *   - Each TrieNode stores:
 *       * character: the character on the edge from its parent
 *       * children: an unordered_map<char, TrieNode*> to child nodes
 *       * terminates: whether a complete word ends at that node
 *
 * Core operations:
 *   - insert(word):
 *       Delegates to root->addWord(word), which walks/creates child nodes
 *       character by character and marks the final node as terminating.
 *
 *   - contains(prefix, exact):
 *       Walks the trie starting at root, following edges that match the
 *       characters of prefix using getChild().
 *       * If at any step the child does not exist, returns false.
 *       * If we successfully consume the entire prefix:
 *           - If exact == false, returns true (prefix exists as a path).
 *           - If exact == true, additionally requires that the last node
 *             terminates a word.
 *
 *   - search(word):
 *       Exact membership check implemented as contains(word, true).
 *
 *   - startsWith(prefix):
 *       Prefix check implemented as contains(prefix, false).
 *
 * Ownership & lifetime:
 *   - The Trie allocates the root in its constructors and destroys it
 *     in the destructor.
 *   - TrieNode::~TrieNode recursively deletes children, so deleting the
 *     root is sufficient to free the entire structure.
 *
 * Complexity (n = length of the query word/prefix):
 *   - insert/search/startsWith: O(n) average time, assuming O(1) average
 *     hashmap lookup in children (unordered_map).
 *   - Space: one node per distinct prefix in the stored set of words,
 *     plus the overhead of the child maps.
 */

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

/*
 * Walks the trie along the characters of prefix.
 *
 * - If at any character the corresponding child is missing, returns false.
 * - If all characters are found:
 *     * If exact == false, returns true (the prefix exists in the trie).
 *     * If exact == true, additionally checks that the final node marks
 *       the end of a complete word.
 */
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
