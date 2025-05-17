#pragma once
#include <string>
#include <vector>

using namespace std;

class WordSearch_79 {
public:
    bool exist(vector<vector<char>>& board, string word);
private:
    bool backtrack(vector<vector<char>>& board, const string& word, int row, int col, int index);
};