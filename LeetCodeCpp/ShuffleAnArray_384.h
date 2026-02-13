#pragma once
#include <random>
#include <vector>

using namespace std;

class ShuffleAnArray_384 {
public:
    using Vec = vector<int>;

    explicit ShuffleAnArray_384(const Vec& nums,
                                uint64_t seed = random_device{}());

    Vec reset();
    Vec shuffle();

private:
    Vec original_;
    Vec current_;
    mt19937_64 rng_;
};
