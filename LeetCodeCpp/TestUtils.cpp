#include "TestUtils.h"
#include <algorithm>
#include <utility>
#include <cmath>
#include <set>

namespace TestUtils {

/* ------------------------ Printing ------------------------ */

void printQuoted(const vector<string>& v, ostream& os) {
    os << '[';
    for (size_t i = 0; i < v.size(); ++i) {
        os << '"' << v[i] << '"';
        if (i + 1 < v.size()) os << ',';
    }
    os << ']';
}

void printVVInt(const vector<vector<int>>& vv, ostream& os) {
    os << '[';
    for (size_t i = 0; i < vv.size(); ++i) {
        printVec(vv[i], os);
        if (i + 1 < vv.size()) os << ',';
    }
    os << ']';
}

/* ---------------------- Normalization --------------------- */

vector<vector<int>>
normalizeVV_SizeThenLex(vector<vector<int>> vv) {
    for (auto& v : vv) sort(v.begin(), v.end());
    sort(vv.begin(), vv.end(), [](const vector<int>& a, const vector<int>& b){
        if (a.size() != b.size()) return a.size() < b.size();
        return lexicographical_compare(a.begin(), a.end(), b.begin(), b.end());
    });
    return vv;
}

vector<vector<int>>
normalizeVV_LexOnly(vector<vector<int>> vv) {
    sort(vv.begin(), vv.end(), [](const vector<int>& a, const vector<int>& b){
        return lexicographical_compare(a.begin(), a.end(), b.begin(), b.end());
    });
    return vv;
}

vector<string>
normalizeStrings(vector<string> v) {
    sort(v.begin(), v.end());
    return v;
}

/* ------------------------ Equality ------------------------ */

bool equalVecIntExact(const vector<int>& a, const vector<int>& b) {
    return a == b;
}

bool equalStringsExact(const vector<string>& a,
                       const vector<string>& b) {
    return a == b;
}

bool equalStringsAnyOrder(vector<string> a,
                          vector<string> b) {
    return normalizeStrings(move(a)) == normalizeStrings(move(b));
}

bool equalVVIntExact(const vector<vector<int>>& a,
                     const vector<vector<int>>& b) {
    return a == b;
}

bool equalVVIntAnyOrder(vector<vector<int>> a,
                        vector<vector<int>> b) {
    return normalizeVV_SizeThenLex(move(a)) == normalizeVV_SizeThenLex(move(b));
}

bool equalVVIntPermutations(vector<vector<int>> a,
                            vector<vector<int>> b) {
    return normalizeVV_LexOnly(move(a)) == normalizeVV_LexOnly(move(b));
}

bool approxEqual(double a, double b, double eps) {
    return fabs(a - b) < eps;
}

/* --------------------- Assert + logging ------------------- */

bool assertEqStrings(const string& label,
                     const vector<string>& expected,
                     const vector<string>& got) {
    bool pass = (expected == got);
    cout << label << ": " << (pass ? "PASS" : "FAIL") << '\n';
    if (!pass) {
        cout << "  Expected: ";
        printQuoted(expected);
        cout << "  Got: ";
        printQuoted(got);
        cout << '\n';
    }
    return pass;
}

bool assertEqStringsAnyOrder(const string& label,
                             vector<string> expected,
                             vector<string> got) {
    expected = normalizeStrings(move(expected));
    got      = normalizeStrings(move(got));
    bool pass = (expected == got);
    cout << label << ": " << (pass ? "PASS" : "FAIL") << '\n';
    if (!pass) {
        cout << "  Expected: ";
        printQuoted(expected);
        cout << "  Got: ";
        printQuoted(got);
        cout << '\n';
    }
    return pass;
}

bool assertEqVVIntExact(const string& label,
                        const vector<vector<int>>& expected,
                        const vector<vector<int>>& got) {
    bool pass = (expected == got);
    cout << label << ": " << (pass ? "PASS" : "FAIL") << '\n';
    if (!pass) {
        cout << "  Expected: ";
        printVVInt(expected);
        cout << "  Got: ";
        printVVInt(got);
        cout << '\n';
    }
    return pass;
}

bool assertEqVVIntAnyOrder(const string& label,
                           vector<vector<int>> expected,
                           vector<vector<int>> got) {
    expected = normalizeVV_SizeThenLex(move(expected));
    got      = normalizeVV_SizeThenLex(move(got));
    bool pass = (expected == got);
    cout << label << ": " << (pass ? "PASS" : "FAIL") << '\n';
    if (!pass) {
        cout << "  Expected: ";
        printVVInt(expected);
        cout << "  Got: ";
        printVVInt(got);
        cout << '\n';
    }
    return pass;
}

bool assertEqVVIntPermutations(const string& label,
                               vector<vector<int>> expected,
                               vector<vector<int>> got) {
    expected = normalizeVV_LexOnly(move(expected));
    got      = normalizeVV_LexOnly(move(got));
    bool pass = (expected == got);
    cout << label << ": " << (pass ? "PASS" : "FAIL") << '\n';
    if (!pass) {
        cout << "  Expected: ";
        printVVInt(expected);
        cout << "  Got: ";
        printVVInt(got);
        cout << '\n';
    }
    return pass;
}

bool assertApprox(const string& label,
                  double expected, double got, double eps) {
    bool pass = approxEqual(expected, got, eps);
    cout << label << ": " << (pass ? "PASS" : "FAIL")
              << " (Expected: " << expected << ", Got: " << got
              << ", eps: " << eps << ")\n";
    return pass;
}

bool assertEqVIntExact(const string& label,
                       const vector<int>& expected,
                       const vector<int>& got) {
    bool pass = (expected == got);
    cout << label << ": " << (pass ? "PASS" : "FAIL") << '\n';
    if (!pass) {
        cout << "  Expected: ";
        printVec(expected);
        cout << "  Got: ";
        printVec(got);
        cout << '\n';
    }
    return pass;
}

bool assertEqVIntPrefix(const string& label,
                        const vector<int>& expected,
                        const vector<int>& vec, int k) {
    if (k < 0) k = 0;
    if (k > static_cast<int>(vec.size())) k = static_cast<int>(vec.size());
    vector<int> prefix(vec.begin(), vec.begin() + k);
    bool pass = (static_cast<int>(expected.size()) == k) && (expected == prefix);

    cout << label << ": " << (pass ? "PASS" : "FAIL") << '\n';
    if (!pass) {
        cout << "  Expected k=" << expected.size() << ", prefix=";
        printVec(expected);
        cout << "\n  Got      k=" << k << ", prefix=";
        printVec(prefix);
        cout << '\n';
    }
    return pass;
}

// distance^2 helper kept file-local
inline long long distSq2D(const vector<int>& p) {
    return 1LL * p[0] * p[0] + 1LL * p[1] * p[1];
}

bool isValidKClosestPoints(const vector<vector<int>>& input,
                           int k,
                           const vector<vector<int>>& out) {
    if ((int)out.size() != k) return false;

    // Build multiset of original points to check membership & multiplicity.
    multiset<pair<int,int>> pool;
    for (const auto& p : input) pool.emplace(p[0], p[1]);

    // Find k-th smallest distance^2 via nth_element.
    vector<long long> dists;
    dists.reserve(input.size());
    for (const auto& p : input) dists.push_back(distSq2D(p));
    nth_element(dists.begin(), dists.begin() + (k - 1), dists.end());
    const long long kth = dists[k - 1];

    // Validate output points.
    for (const auto& p : out) {
        auto it = pool.find({p[0], p[1]});
        if (it == pool.end()) return false;        // not present
        if (distSq2D(p) > kth) return false;       // too far
        pool.erase(it);                            // consume one copy
    }
    return true;
}

} // namespace TestUtils
