#pragma once

#include <queue>
#include <set>
#include <vector>

using namespace std;

class ExamRoom_855 {
public:
    explicit ExamRoom_855(int n);

    int seat();
    void leave(int seat);

private:
    struct Gap {
        int left;
        int right;
        int distance;
        int seat;
    };

    struct GapCompare {
        bool operator()(const Gap& a, const Gap& b) const;
    };

    const int n;

    set<int> occupied;
    priority_queue<Gap, vector<Gap>, GapCompare> gaps;

    int seatInGap(int left, int right) const;
    int distanceInGap(int left, int right) const;
    void pushGap(int left, int right);
    bool isValidGap(int left, int right) const;
};
