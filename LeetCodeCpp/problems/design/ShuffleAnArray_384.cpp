#include "ShuffleAnArray_384.h"

#include <algorithm>
#include <utility>

/*
 * Shuffle an Array (LeetCode 384)
 *
 * GOOD: Fisher–Yates / Knuth shuffle (unbiased):
 *   for i = n-1 .. 1:
 *     pick j uniformly from [0, i]
 *     swap(a[i], a[j])
 *
 * Intuition:
 * - Step i chooses which element ends up at position i.
 * - After that swap, position i is never touched again.
 *
 * Under the assumption of an ideal RNG:
 * - Each permutation is produced with probability 1/n!.
 *   There are exactly n*(n-1)*...*1 equally likely (j) choices,
 *   and each unique choice sequence maps to exactly one permutation.
 *
 * Testing note:
 * - Ctors accept a seed so tests can be deterministic.
 *   (Production code can use random_device() to seed.)
 */

ShuffleAnArray_384_FisherYates::ShuffleAnArray_384_FisherYates(
    const Vec& nums, uint64_t seed)
    : original_(nums), current_(nums), rng_(seed) {
}

ShuffleAnArray_384::Vec ShuffleAnArray_384_FisherYates::reset() {
    current_ = original_;
    return current_;
}

ShuffleAnArray_384::Vec ShuffleAnArray_384_FisherYates::shuffle() {
    const int n = static_cast<int>(current_.size());
    if (n <= 1) return current_;

    // Fisher–Yates shuffle: unbiased.
    for (int i = n - 1; i > 0; --i) {
        uniform_int_distribution<int> dist(0, i);
        const int j = dist(rng_);
        swap(current_[i], current_[j]);
    }
    return current_;
}

// A deliberately biased implementation (classic wrong shuffle).
// It *looks* random, but does not generate all permutations with probability 1/n!.
ShuffleAnArray_384_Wrong::ShuffleAnArray_384_Wrong(
    const Vec& nums, uint64_t seed)
    : original_(nums), current_(nums), rng_(seed) {
}

ShuffleAnArray_384::Vec ShuffleAnArray_384_Wrong::reset() {
    current_ = original_;
    return current_;
}

ShuffleAnArray_384::Vec ShuffleAnArray_384_Wrong::shuffle() {
    const int n = static_cast<int>(current_.size());
    if (n <= 1) return current_;
    uniform_int_distribution<int> dist(0, n - 1);

    // WRONG: choosing j from the full [0, n-1] range for each i is biased.
    for (int i = 0; i < n; ++i) {
        const int j = dist(rng_);
        swap(current_[i], current_[j]);
    }
    return current_;
}
