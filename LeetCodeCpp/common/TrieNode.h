#pragma once

#include <string>
#include <unordered_map>

using namespace std;

class TrieNode {
public:
    TrieNode();
    explicit TrieNode(char character);
    ~TrieNode();

    TrieNode(const TrieNode&) = delete;
    TrieNode& operator=(const TrieNode&) = delete;

    char getChar() const;
    void addWord(const string& word);
    TrieNode* getChild(char c);
    bool terminatesWord() const;
    void setTerminates(bool terminates);

private:
    unordered_map<char, TrieNode*> children;
    char character;
    bool terminates;
};
