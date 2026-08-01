#pragma once

#include <vector>

using namespace std;

class MajorityElement_169 {
public:
    int majorityElementBoyerMoore(const vector<int>& nums) const;
    int majorityElementHashmap(const vector<int>& nums) const;
    int majorityElementBitCounting(const vector<int>& nums) const;
};
