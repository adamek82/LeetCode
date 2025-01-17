#pragma once
#include <string>
#include <vector>

class WordSearch_79 {
public:
    bool exist(std::vector<std::vector<char>>& board, std::string word);
private:
    bool backtrack(std::vector<std::vector<char>>& board, const std::string& word, int row, int col, int index);
};