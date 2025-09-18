#pragma once
#include <set>
#include <queue>
#include <vector>

using namespace std;

// LeetCode 855. Exam Room
// Optimal O(log M) per operation using a max-heap of gaps + lazy deletion.
// M = number of seated students (<= #operations).

class ExamRoom_855 {
public:
    explicit ExamRoom_855(int n_);
    int seat();
    void leave(int p);

private:
    const int n;

    struct Seg {
        int L, R;     // bounding occupied seats (may be sentinels -1 and n)
        int dist;     // priority distance for this gap
        int seat;     // chosen seat in this gap
    };

    struct Cmp {
        bool operator()(const Seg& a, const Seg& b) const;
    };

    set<int> taken;   // occupied seats; includes sentinels -1 and n
    priority_queue<Seg, vector<Seg>, Cmp> pq;

    // helpers
    int seatOf(int L, int R) const;
    int distOf(int L, int R) const;
    void pushGap(int L, int R);
    bool isValid(int L, int R) const;
};
