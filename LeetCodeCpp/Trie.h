#pragma once
#include <string>
#include <vector>
#include "TrieNode.h"

using namespace std;

/*
 * Trie
 * ----
 * A Trie (prefix tree) for storing and querying a set of strings.
 *
 * Public operations:
 *   - insert(word):        adds a word to the trie.
 *   - search(word):        checks if the exact word exists.
 *   - startsWith(prefix):  checks if any stored word has the given prefix.
 *
 * Internally, the Trie owns a single root TrieNode and delegates
 * most of the work to that node. The implementation details live
 * in Trie.cpp; this header exposes the public API.
 */
class Trie {
private:
    /*
     * Pointer to the root node of the trie. The root does not
     * correspond to any real character.
     */
    TrieNode* root;

    /*
     * Helper used by range-based constructors to insert a batch of words
     * from any iterable range of strings (e.g. vector<string>,
     * initializer_list<string>, etc.).
     */
    template <typename Range>
    void insertAll(const Range& list) {
        for (const auto& word : list) {
            root->addWord(word);
        }
    }

public:
    /*
     * Constructs an empty trie.
     */
    Trie();

    /*
     * Constructs a trie and inserts all words from the given vector.
     */
    Trie(const vector<string>& list);

    /*
     * Constructs a trie and inserts all words from the given initializer list.
     */
    Trie(const initializer_list<string>& list);

    /*
     * Inserts a single word into the trie.
     */
    void insert(const string& word);

    /*
     * Returns true if the trie contains this word as a complete entry.
     */
    bool search(const string& word);

    /*
     * Returns true if there exists at least one word in the trie that
     * starts with the given prefix.
     */
    bool startsWith(const string& prefix);

    /*
     * Internal helper for both search() and startsWith().
     *
     * If exact == true:
     *   - Returns true only if prefix is a complete word stored in the trie.
     *
     * If exact == false:
     *   - Returns true if prefix exists as a path in the trie, regardless of
     *     whether a word terminates exactly at that node.
     */
    bool contains(const string& prefix, bool exact = false) const;

    /*
     * Returns the root node. Exposed mainly for debugging or advanced use.
     */
    TrieNode* getRoot() const;

    /*
     * Deletes the entire trie by deleting the root node; the root
     * recursively deletes all of its descendants.
     */
    ~Trie();
};
