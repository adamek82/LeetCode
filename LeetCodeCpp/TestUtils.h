#pragma once
#include <cstddef>
#include <functional>
#include <initializer_list>
#include <iostream>
#include <optional>
#include <string>
#include <utility>
#include <vector>

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

// Pretty-print vector<vector<string>> as [[...],[...]] to the provided stream.
void printVVString(const vector<vector<string>>& vv,
                   ostream& os = cout);

// --- print a 2D matrix with rows on separate lines ---
template <typename T>
inline void printMatrix(const vector<vector<T>>& m, ostream& os = cout) {
    for (const auto& row : m) printVec(row, os);
}

/* ===========================================================
 * Normalizers (for order-insensitive comparisons)
 * =========================================================== */

/// Sort inner vectors ascending, then sort outer by (size, lexicographic).
/// Use this when each inner vector is a *set/combination* (order inside shouldn't matter).
vector<vector<int>>
normalizeVV_SizeThenLex(vector<vector<int>> vv);

vector<vector<string>>
normalizeVVStr_SizeThenLex(vector<vector<string>> vv);

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

// Returns true if v[0] < v[1] < ... < v[n-1] (strictly increasing).
bool isStrictlyIncreasing(const vector<int>& v);

// Returns true if `sub` is a subsequence of `full` (in-order, not necessarily contiguous).
bool isSubsequence(const vector<int>& sub, const vector<int>& full);

// Returns true if `sub` is a subsequence of `full` (in-order, not necessarily contiguous).
bool isSubsequenceStr(const string& sub, const string& full);

/* ===========================================================
 * Assert & log shortcuts (print PASS/FAIL + diff on mismatch)
 * =========================================================== */

bool assertApprox(const string& label,
                  double expected, double got, double eps = 1e-5);

// Compares only the first k elements of `vec` with `expected` and logs k.
bool assertEqVIntPrefix(const string& label,
                        const vector<int>& expected,
                        const vector<int>& vec, int k);

/* ===========================================================
 * Probability / statistics helpers
 * =========================================================== */

// Returns true if `got` is a permutation of `expected` (multiset equality).
// This is handy for problems where output order may vary but elements must match.
bool isPermutationVecInt(const vector<int>& expected,
                         const vector<int>& got);

// Pearson chi-square statistic for discrete categories with equal expectation.
// X = sum_i (obs[i] - expectedEach)^2 / expectedEach
double chiSquare(const vector<long long>& obs, double expectedEach);

/* ===========================================================
 * Generic assertion core & thin wrappers (inline)
 * =========================================================== */

// Core comparator that normalizes and prints on failure.
template <typename T, typename Normalizer, typename Printer>
inline bool assertEqGeneric(const string& label,
                            T expected, T got,
                            Normalizer normalize,
                            Printer print) {
    expected = normalize(move(expected));
    got      = normalize(move(got));
    const bool pass = (expected == got);
    cout << label << ": " << (pass ? "PASS" : "FAIL") << '\n';
    if (!pass) {
        cout << "  Expected: "; print(expected);
        cout << "  Got: ";      print(got);
        cout << '\n';
    }
    return pass;
}

// No-op normalizer for exact comparisons.
struct NoNormalize {
    template <typename U>
    U operator()(U v) const { return v; }
};

struct PrintScalar {
    template <typename U>
    void operator()(const U& v) const { cout << v; }
};

template <typename T>
inline bool assertEqScalar(const string& label,
                           const T& expected,
                           const T& got) {
    return assertEqGeneric(label, expected, got, NoNormalize{}, PrintScalar{});
}

// Printers adapted to existing helpers.
struct PrintVecInt {
    void operator()(const vector<int>& v) const { printVec(v); }
};
struct PrintVVInt {
    void operator()(const vector<vector<int>>& vv) const { printVVInt(vv); }
};
struct PrintQuotedStrings {
    void operator()(const vector<string>& v) const { printQuoted(v); }
};

// ----- Public API: thin wrappers kept as function names used in the runner -----

inline bool assertEqVIntExact(const string& label,
                              const vector<int>& expected,
                              const vector<int>& got) {
    return assertEqGeneric(label, expected, got, NoNormalize{}, PrintVecInt{});
}

inline bool assertEqVVIntExact(const string& label,
                               const vector<vector<int>>& expected,
                               const vector<vector<int>>& got) {
    return assertEqGeneric(label, expected, got, NoNormalize{}, PrintVVInt{});
}

inline bool assertEqVVIntAnyOrder(const string& label,
                                  vector<vector<int>> expected,
                                  vector<vector<int>> got) {
    return assertEqGeneric(label, move(expected), move(got),
                           normalizeVV_SizeThenLex, PrintVVInt{});
}

inline bool assertEqVVIntPermutations(const string& label,
                                      vector<vector<int>> expected,
                                      vector<vector<int>> got) {
    return assertEqGeneric(label, move(expected), move(got),
                           normalizeVV_LexOnly, PrintVVInt{});
}

inline bool assertEqStrings(const string& label,
                            const vector<string>& expected,
                            const vector<string>& got) {
    return assertEqGeneric(label, expected, got, NoNormalize{}, PrintQuotedStrings{});
}

inline bool assertEqStringsAnyOrder(const string& label,
                                    vector<string> expected,
                                    vector<string> got) {
    return assertEqGeneric(label, move(expected), move(got),
                           normalizeStrings, PrintQuotedStrings{});
}

// Compare vector<vector<string>> ignoring order of groups and words within groups.
inline bool assertEqVVStrAnyOrder(const string& label,
                                  vector<vector<string>> expected,
                                  vector<vector<string>> got) {
    expected = normalizeVVStr_SizeThenLex(move(expected));
    got      = normalizeVVStr_SizeThenLex(move(got));

    const bool pass = (expected == got);
    cout << label << ": " << (pass ? "PASS" : "FAIL") << '\n';
    if (!pass) {
        cout << "  Expected: "; printVVString(expected);
        cout << "  Got: ";      printVVString(got);
        cout << '\n';
    }
    return pass;
}

void assertMaxMin(const string& label,
                  const function<string()>& getMax,
                  const function<string()>& getMin,
                  initializer_list<string> maxSet,
                  initializer_list<string> minSet);


// ----- Validators -----

/*
 * Validate k-closest result for 2D points (order agnostic, multiplicities respected).
 *
 * Returns true iff `out`
 *   1) has exactly k points,
 *   2) every point comes from the original `input`,
 *   3) every point’s distance² is ≤ the k-th smallest distance²
 *      found in the entire input set.
 */
bool isValidKClosestPoints(const vector<vector<int>>& input,
                           int k,
                           const vector<vector<int>>& out);

/**
 * Validate that 'res' is a correct frequency-sort of 'orig':
 * - Same multiset of characters as 'orig'
 * - Characters appear in contiguous runs (no splitting a char into multiple runs)
 * - Runs are ordered by non-increasing frequency
 */
bool isValidFrequencySort(const string& orig, const string& res);

// Build a step label like: "<suite> X #Y op("arg")" or "<suite> X #Y op()"
string makeStepLabel(const string& suite,
                     size_t caseIdx,
                     size_t stepIdx,
                     const string& op,
                     const optional<string>& arg = nullopt);
} // namespace TestUtils
