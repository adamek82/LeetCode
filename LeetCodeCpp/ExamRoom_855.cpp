#include "ExamRoom_855.h"
#include <algorithm>

// Comparator for priority_queue: larger distance first, then smaller seat index
bool ExamRoom_855::Cmp::operator()(const Seg& a, const Seg& b) const {
    if (a.dist != b.dist) return a.dist < b.dist;
    return a.seat > b.seat;
}

ExamRoom_855::ExamRoom_855(int n_) : n(n_) {
    taken.insert(-1);
    taken.insert(n);
    pushGap(-1, n); // whole room is empty initially
}

int ExamRoom_855::seat() {
    // Pop until we find a still-valid gap (lazy deletion).
    while (!pq.empty()) {
        Seg s = pq.top();
        if (isValid(s.L, s.R)) {
            pq.pop();
            int p = s.seat;
            taken.insert(p);
            // Split into two gaps if there is space
            pushGap(s.L, p);
            pushGap(p, s.R);
            return p;
        } else {
            pq.pop(); // stale segment
        }
    }
    return 0; // should not happen
}

void ExamRoom_855::leave(int p) {
    auto it  = taken.find(p);
    auto itR = next(it);
    auto itL = prev(it);
    int L = *itL, R = *itR;
    taken.erase(it);
    // Merge into a larger gap; old sub-gaps stay in heap and will be discarded lazily.
    pushGap(L, R);
}

// Compute seat to take in gap (L,R)
int ExamRoom_855::seatOf(int L, int R) const {
    if (L == -1) return 0;
    if (R == n)  return n - 1;
    return L + (R - L) / 2;
}

// Compute distance to closest person for the chosen seat in gap (L,R)
int ExamRoom_855::distOf(int L, int R) const {
    if (L == -1) return R;              // sit at 0; nearest person at R
    if (R == n)  return (n - 1) - L;    // sit at n-1; nearest at L
    return (R - L) / 2;                 // middle
}

// Push a gap (L,R) if it actually contains any empty seat.
void ExamRoom_855::pushGap(int L, int R) {
    if (R - L <= 1) return;
    Seg s{L, R, distOf(L, R), seatOf(L, R)};
    pq.push(s);
}

// Gap (L,R) is valid if L and R are adjacent in 'taken'.
bool ExamRoom_855::isValid(int L, int R) const {
    auto it = taken.find(L);
    if (it == taken.end()) return false;
    auto it2 = next(it);
    return (it2 != taken.end() && *it2 == R);
}
