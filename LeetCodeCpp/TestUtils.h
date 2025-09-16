#pragma once
#include <vector>
#include <string>
#include <ostream>
#include <iostream>

using namespace std;

namespace TestUtils {

/* ===========================================================
 * Printing helpers (uniform, compact, copy-paste friendly)
 * =========================================================== */

/// Prints a 1D vector in bracketed form: [a,b,c]
template <typename T>
void printVec(const vector<T>& v, ostream& os = cout) {
    os << '[';
    for (size_t i = 0; i < v.size(); ++i) {
        os << v[i];
        if (i + 1 < v.size()) os << ',';
    }
    os << ']';
}

/// Prints a 1D vector<string> with quotes: ["a","b","c"]
void printQuoted(const vector<string>& v,
                 ostream& os = cout);

/// Prints a 2D vector<int> like: [[1,2],[3]]
void printVVInt(const vector<vector<int>>& vv,
                ostream& os = cout);

/* ===========================================================
 * Normalizers (for order-insensitive comparisons)
 * =========================================================== */

/// Sort inner vectors ascending, then sort outer by (size, lexicographic).
/// Use this when each inner vector is a *set/combination* (order inside shouldn't matter).
vector<vector<int>>
normalizeVV_SizeThenLex(vector<vector<int>> vv);

/// Sort the outer list lexicographically; *do not* modify inner order.
/// Use this for permutations: inner order matters, outer order does not.
vector<vector<int>>
normalizeVV_LexOnly(vector<vector<int>> vv);

/// Sort a vector<string> lexicographically (order-insensitive string lists).
vector<string>
normalizeStrings(vector<string> v);

/* ===========================================================
 * Equality helpers (with/without normalization)
 * =========================================================== */

bool equalVecIntExact(const vector<int>& a, const vector<int>& b);
bool equalStringsExact(const vector<string>& a,
                       const vector<string>& b);

bool equalStringsAnyOrder(vector<string> a,
                          vector<string> b);

bool equalVVIntExact(const vector<vector<int>>& a,
                     const vector<vector<int>>& b);

bool equalVVIntAnyOrder(vector<vector<int>> a,
                        vector<vector<int>> b);

bool equalVVIntPermutations(vector<vector<int>> a,
                            vector<vector<int>> b);

/// Compare doubles within epsilon.
bool approxEqual(double a, double b, double eps = 1e-5);

/* ===========================================================
 * Assert & log shortcuts (print PASS/FAIL + diff on mismatch)
 * =========================================================== */

bool assertEqStrings(const string& label,
                     const vector<string>& expected,
                     const vector<string>& got);

bool assertEqStringsAnyOrder(const string& label,
                             vector<string> expected,
                             vector<string> got);

bool assertEqVVIntExact(const string& label,
                        const vector<vector<int>>& expected,
                        const vector<vector<int>>& got);

bool assertEqVVIntAnyOrder(const string& label,
                           vector<vector<int>> expected,
                           vector<vector<int>> got);

bool assertEqVVIntPermutations(const string& label,
                               vector<vector<int>> expected,
                               vector<vector<int>> got);

bool assertApprox(const string& label,
                  double expected, double got, double eps = 1e-5);

bool assertEqVIntExact(const std::string& label,
                       const std::vector<int>& expected,
                       const std::vector<int>& got);

// Compares only the first k elements of `vec` with `expected` and logs k.
bool assertEqVIntPrefix(const std::string& label,
                        const std::vector<int>& expected,
                        const std::vector<int>& vec, int k);

} // namespace TestUtils
