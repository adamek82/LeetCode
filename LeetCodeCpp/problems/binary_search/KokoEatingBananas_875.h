#pragma once
#include <vector>

using namespace std;

class KokoEatingBananas_875 {
public:
    int minEatingSpeed(vector<int>& piles, int h);

private:
    bool canFinish(const vector<int>& piles, int h, int k);
};
