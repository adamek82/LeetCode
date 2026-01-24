#pragma once
#include <vector>

using namespace std;

class SortColors_75 {
public:
    // 1-pass overwrite with three tails
    void sortColors_threeTails(vector<int>& nums);

    // 2-pass counting (count then fill)
    void sortColors_counting(vector<int>& nums);
};
