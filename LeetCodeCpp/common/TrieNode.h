#pragma once

#include <memory>
#include <string>
#include <unordered_map>

class TrieNode {
public:
    TrieNode() = default;

    TrieNode(const TrieNode&) = delete;
    TrieNode& operator=(const TrieNode&) = delete;

    void addWord(const std::string& word);
    TrieNode* getChild(char c);
    const TrieNode* getChild(char c) const;
    bool terminatesWord() const;

private:
    std::unordered_map<char, std::unique_ptr<TrieNode>> children;
    bool terminates = false;
};
