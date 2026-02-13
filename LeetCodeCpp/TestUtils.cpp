#include "TestUtils.h"
#include <algorithm>
#include <cmath>
#include <set>
#include <unordered_map>

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

// Print nested string vectors as [[ "a","b" ],[ "c" ]]
void printVVString(const vector<vector<string>>& vv, ostream& os) {
    os << '[';
    for (size_t i = 0; i < vv.size(); ++i) {
        os << '[';
        for (size_t j = 0; j < vv[i].size(); ++j) {
            os << '"' << vv[i][j] << '"';
            if (j + 1 < vv[i].size()) os << ',';
        }
        os << ']';
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

// Normalize vector<vector<string>> by sorting within groups and then sorting groups
// by (size asc, lexicographical order).
vector<vector<string>>
normalizeVVStr_SizeThenLex(vector<vector<string>> vv) {
    for (auto& grp : vv) sort(grp.begin(), grp.end());
    sort(vv.begin(), vv.end(),
        [](const vector<string>& a, const vector<string>& b){
            if (a.size() != b.size()) return a.size() < b.size();
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

bool isStrictlyIncreasing(const vector<int>& v) {
    for (size_t i = 1; i < v.size(); ++i) {
        if (!(v[i - 1] < v[i])) return false;
    }
    return true;
}

bool isSubsequence(const vector<int>& sub, const vector<int>& full) {
    size_t j = 0;
    for (size_t i = 0; i < full.size() && j < sub.size(); ++i) {
        if (full[i] == sub[j]) ++j;
    }
    return j == sub.size();
}

bool isSubsequenceStr(const string& sub, const string& full) {
    size_t j = 0;
    for (size_t i = 0; i < full.size() && j < sub.size(); ++i) {
        if (full[i] == sub[j]) ++j;
    }
    return j == sub.size();
}

/* ---------------- Probability / statistics --------------- */

bool isPermutationVecInt(const vector<int>& expected,
                         const vector<int>& got) {
    if (expected.size() != got.size()) return false;
    auto a = expected;
    auto b = got;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    return a == b;
}

double chiSquare(const vector<long long>& obs, double expectedEach) {
    double X = 0.0;
    for (long long c : obs) {
        const double diff = double(c) - expectedEach;
        X += (diff * diff) / expectedEach;
    }
    return X;
}

/* --------------------- Assert + logging ------------------- */

bool assertApprox(const string& label,
                  double expected, double got, double eps) {
    bool pass = approxEqual(expected, got, eps);
    cout << label << ": " << (pass ? "PASS" : "FAIL")
              << " (Expected: " << expected << ", Got: " << got
              << ", eps: " << eps << ")\n";
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

void assertMaxMin(const string& label,
                  const function<string()>& getMax,
                  const function<string()>& getMin,
                  initializer_list<string> maxSet,
                  initializer_list<string> minSet) {
    const bool maxOk = find(maxSet.begin(), maxSet.end(), getMax()) != maxSet.end();
    const bool minOk = find(minSet.begin(), minSet.end(), getMin()) != minSet.end();

    assertEqScalar(label + " [max]", true, maxOk);
    assertEqScalar(label + " [min]", true, minOk);
}

// distance^2 helper kept file-local
inline long long distSq2D(const vector<int>& p) {
    return 1LL * p[0] * p[0] + 1LL * p[1] * p[1];
}

bool isValidKClosestPoints(const vector<vector<int>>& input,
                           int k,
                           const vector<vector<int>>& out) {
    if (static_cast<int>(out.size()) != k) return false;

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

string makeStepLabel(const string& suite,
                     size_t caseIdx,
                     size_t stepIdx,
                     const string& op,
                     const optional<string>& arg) {
    string label;
    label.reserve(suite.size() + op.size() + 32);
    label.append(suite).append(" ")
         .append(to_string(caseIdx + 1))
         .append(" #").append(to_string(stepIdx + 1))
         .append(" ").append(op);
    if (arg && !arg->empty()) {
        label.append("(\"").append(*arg).append("\")");
    } else {
        label.append("()");
    }
    return label;
}

bool isValidFrequencySort(const string& orig, const string& res) {
    if (orig.size() != res.size()) return false;

    // Count chars in original and result
    unordered_map<char,int> freqOrig, freqRes;
    for (char c : orig) ++freqOrig[c];
    for (char c : res)  ++freqRes[c];
    if (freqOrig != freqRes) return false;

    // Extract contiguous runs in result: [(char, run_length), ...]
    vector<pair<char,int>> runs;
    for (size_t i = 0; i < res.size();) {
        char c = res[i];
        size_t j = i + 1;
        while (j < res.size() && res[j] == c) ++j;
        runs.emplace_back(c, int(j - i));
        i = j;
    }

    // Each run must consume the full frequency for that char (no split runs)
    for (const auto& p : runs) {
        char c = p.first;
        int  cnt = p.second;
        if (freqOrig[c] != cnt) return false;
    }

    // Runs must be in non-increasing frequency order
    for (size_t i = 1; i < runs.size(); ++i) {
        if (runs[i - 1].second < runs[i].second) return false;
    }
    return true;
}

} // namespace TestUtils
