#include "ExamRoom_855.h"

#include <iterator>

bool ExamRoom_855::GapCompare::operator()(const Gap& a, const Gap& b) const
{
    if (a.distance != b.distance)
        return a.distance < b.distance;

    return a.seat > b.seat;
}

ExamRoom_855::ExamRoom_855(int n)
    : n(n)
{
    occupied.insert(-1);
    occupied.insert(n);
    pushGap(-1, n);
}

int ExamRoom_855::seat()
{
    while (!gaps.empty()) {
        const Gap gap = gaps.top();
        gaps.pop();

        if (!isValidGap(gap.left, gap.right))
            continue;

        const int seat = gap.seat;
        occupied.insert(seat);

        pushGap(gap.left, seat);
        pushGap(seat, gap.right);

        return seat;
    }

    return 0;
}

void ExamRoom_855::leave(int seat)
{
    const auto it = occupied.find(seat);
    const int left = *prev(it);
    const int right = *next(it);

    occupied.erase(it);

    // Old sub-gaps remain in the heap and are discarded lazily by seat().
    pushGap(left, right);
}

int ExamRoom_855::seatInGap(int left, int right) const
{
    if (left == -1)
        return 0;

    if (right == n)
        return n - 1;

    return left + (right - left) / 2;
}

int ExamRoom_855::distanceInGap(int left, int right) const
{
    if (left == -1)
        return right;

    if (right == n)
        return n - 1 - left;

    return (right - left) / 2;
}

void ExamRoom_855::pushGap(int left, int right)
{
    if (right - left <= 1)
        return;

    gaps.push({
        left,
        right,
        distanceInGap(left, right),
        seatInGap(left, right)
    });
}

bool ExamRoom_855::isValidGap(int left, int right) const
{
    const auto it = occupied.find(left);

    if (it == occupied.end())
        return false;

    const auto nextIt = next(it);
    return nextIt != occupied.end() && *nextIt == right;
}
