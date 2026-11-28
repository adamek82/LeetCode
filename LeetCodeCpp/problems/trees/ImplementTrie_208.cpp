#include "ImplementTrie_208.h"

using namespace std;

Trie::Trie()
    : root(make_unique<TrieNode>())
{
}

Trie::Trie(const vector<string>& list)
    : Trie()
{
    insertAll(list);
}

Trie::Trie(initializer_list<string> list)
    : Trie()
{
    insertAll(list);
}

void Trie::insert(const string& word)
{
    root->addWord(word);
}

bool Trie::search(const string& word) const
{
    return contains(word, true);
}

bool Trie::startsWith(const string& prefix) const
{
    return contains(prefix, false);
}

const TrieNode* Trie::getRoot() const
{
    return root.get();
}

bool Trie::contains(const string& prefix, bool fullWord) const
{
    const TrieNode* node = root.get();

    for (const char c : prefix) {
        node = node->getChild(c);
        if (node == nullptr) {
            return false;
        }
    }

    return !fullWord || node->terminatesWord();
}
