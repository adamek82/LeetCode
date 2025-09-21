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

bool assertApprox(const string& label,
                  double expected, double got, double eps = 1e-5);

// Compares only the first k elements of `vec` with `expected` and logs k.
bool assertEqVIntPrefix(const string& label,
                        const vector<int>& expected,
                        const vector<int>& vec, int k);

/* ===========================================================
 * Generic assertion core & thin wrappers (inline)
 * =========================================================== */

// Core comparator that normalizes and prints on failure.
template <typename T, typename Normalizer, typename Printer>
inline bool assertEqGeneric(const string& label,
                            T expected, T got,
                            Normalizer normalize,
                            Printer print) {
    expected = normalize(std::move(expected));
    got      = normalize(std::move(got));
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

// ----- Thin wrappers that keep the public API names -----

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
    return assertEqGeneric(label, std::move(expected), std::move(got),
                           normalizeVV_SizeThenLex, PrintVVInt{});
}

inline bool assertEqVVIntPermutations(const string& label,
                                      vector<vector<int>> expected,
                                      vector<vector<int>> got) {
    return assertEqGeneric(label, std::move(expected), std::move(got),
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
    return assertEqGeneric(label, std::move(expected), std::move(got),
                           normalizeStrings, PrintQuotedStrings{});
}

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

} // namespace TestUtils
