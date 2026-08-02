#pragma once

#include <random>
#include <vector>

using namespace std;

/*
 * LeetCode 384 (Shuffle an Array)
 *
 * We keep an interface + two implementations:
 * - ShuffleAnArray_384_FisherYates: unbiased Fisher–Yates / Knuth shuffle
 * - ShuffleAnArray_384_Wrong: classic biased "looks random" shuffle
 *
 * This makes it easy for tests to compare GOOD vs WRONG implementations
 * without defining helper classes inside test functions.
 *
 */
class ShuffleAnArray_384 {
public:
    using Vec = vector<int>;

    virtual ~ShuffleAnArray_384() = default;

    virtual Vec reset() = 0;
    virtual Vec shuffle() = 0;
};

class ShuffleAnArray_384_FisherYates final : public ShuffleAnArray_384 {
public:
    explicit ShuffleAnArray_384_FisherYates(const Vec& nums,
                                           uint64_t seed = random_device{}());

    Vec reset() override;
    Vec shuffle() override;

private:
    Vec original_;
    Vec current_;
    mt19937_64 rng_;
};

class ShuffleAnArray_384_Wrong final : public ShuffleAnArray_384 {
public:
    explicit ShuffleAnArray_384_Wrong(const Vec& nums,
                                     uint64_t seed = random_device{}());

    Vec reset() override;
    Vec shuffle() override;

private:
    Vec original_;
    Vec current_;
    mt19937_64 rng_;
};
