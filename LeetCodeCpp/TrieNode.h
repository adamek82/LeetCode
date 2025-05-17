#pragma once
#include <unordered_map>
#include <string>

using namespace std;

class TrieNode {
private:
    unordered_map<char, TrieNode*> children;
    bool terminates;
    char character;

public:
    TrieNode();
    TrieNode(char character);
    char getChar() const;
    void addWord(const string& word);
    TrieNode* getChild(char c);
    bool terminatesWord() const;
    void setTerminates(bool t);
    ~TrieNode();
};
