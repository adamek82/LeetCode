#pragma once

#include <initializer_list>
#include <memory>
#include <string>
#include <vector>

#include "common/TrieNode.h"

class Trie {
public:
    Trie();
    explicit Trie(const std::vector<std::string>& list);
    Trie(const std::initializer_list<std::string>& list);

    Trie(const Trie&) = delete;
    Trie& operator=(const Trie&) = delete;
    Trie(Trie&&) noexcept = default;
    Trie& operator=(Trie&&) noexcept = default;

    void insert(const std::string& word);

    bool search(const std::string& word) const;
    bool startsWith(const std::string& prefix) const;

    const TrieNode* getRoot() const;

private:
    std::unique_ptr<TrieNode> root;

    template <typename Range>
    void insertAll(const Range& list)
    {
        for (const auto& word : list) {
            insert(word);
        }
    }

    bool contains(const std::string& prefix, bool fullWord) const;
};
