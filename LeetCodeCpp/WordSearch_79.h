#pragma once
#include <vector>
#include <string>

using namespace std;

class WordSearch_79 {
public:
    bool exist(vector<vector<char>>& board, string word);
private:
    bool backtrack(vector<vector<char>>& board,
    const string& word,
    size_t row,
    size_t col,
    size_t index);
};
