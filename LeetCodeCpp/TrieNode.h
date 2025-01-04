#pragma once
#include <unordered_map>
#include <string>

class TrieNode {
private:
    std::unordered_map<char, TrieNode*> children;
    bool terminates;
    char character;

public:
    TrieNode();
    TrieNode(char character);
    char getChar() const;
    void addWord(const std::string& word);
    TrieNode* getChild(char c);
    bool terminatesWord() const;
    void setTerminates(bool t);
    ~TrieNode();
};
