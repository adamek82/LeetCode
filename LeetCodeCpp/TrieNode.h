#pragma once
#include <unordered_map>
#include <string>

using namespace std;

/*
 * TrieNode
 * --------
 * Represents a single node in a Trie (prefix tree).
 *
 * Each node stores:
 *   - character: the character on the incoming edge from its parent
 *                (the root uses '\0' as a sentinel).
 *   - children: a mapping from characters to child nodes that continue
 *               words or prefixes from this point.
 *   - terminates: a flag indicating whether a complete word ends at
 *                 this node.
 *
 * Nodes are heap-allocated and form a recursive ownership tree:
 * the destructor deletes all children, so deleting the root frees
 * the entire Trie.
 */
class TrieNode {
private:
    unordered_map<char, TrieNode*> children;
    bool terminates;
    char character;

public:
    /*
     * Constructs a root-like node with no associated character and
     * terminates flag set to false.
     */
    TrieNode();

    /*
     * Constructs a node that represents a given character, with
     * terminates initially set to false.
     */
    TrieNode(char character);

    /*
     * Returns the character stored at this node.
     */
    char getChar() const;

    /*
     * Inserts the given word into the sub-trie rooted at this node.
     * Recursively creates child nodes for each character as needed.
     */
    void addWord(const string& word);

    /*
     * Returns the child node that corresponds to character c, or
     * nullptr if there is no such child.
     */
    TrieNode* getChild(char c);

    /*
     * Returns true if this node marks the end of a complete word;
     * false otherwise.
     */
    bool terminatesWord() const;

    /*
     * Sets or clears the flag indicating that a complete word ends
     * at this node.
     */
    void setTerminates(bool t);

    /*
     * Recursively deletes all child subtrees owned by this node.
     */
    ~TrieNode();
};
