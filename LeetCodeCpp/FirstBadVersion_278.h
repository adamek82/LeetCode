#pragma once
#include <vector>

using namespace std;

/*
 * 278. First Bad Version
 * ----------------------
 * LeetCode provides a monotone predicate isBadVersion(version) with
 * the guarantee that:
 *
 *   - versions are numbered from 1 to n (inclusive),
 *   - there exists some first bad version F (1 <= F <= n),
 *   - all versions < F are good,
 *   - all versions >= F are bad.
 *
 * The goal is to find F using as few calls to isBadVersion as possible.
 *
 * In this local setup, we simulate the hidden API by exposing a public
 * field `firstBad` and implementing isBadVersion(version) as:
 *
 *      version >= firstBad
 *
 * so tests can choose any monotone boundary F and verify the algorithm.
 */
class FirstBadVersion_278 {
public:
    // Ground truth for the "first bad" version used by isBadVersion().
    // Tests are expected to set this value before calling firstBadVersion().
    int firstBad = 1;

    // Simulated LeetCode API: monotone predicate.
    bool isBadVersion(int version) const;

    // Returns the index of the first bad version in [1, n].
    int firstBadVersion(int n);
};
