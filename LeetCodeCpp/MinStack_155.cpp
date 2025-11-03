#include "MinStack_155.h"

/*
 * MinStack (O(1) min) — idea and correctness
 * -------------------------------------------
 * We maintain a stack of pairs: {value, min_so_far}.
 * For each pushed value `v`, we also store the minimum value seen up to (and
 * including) this node: min_so_far = min(v, previous_min).
 *
 * Why it works:
 *   - top()      -> st_.back().first
 *   - getMin()   -> st_.back().second (constant-time)
 *   - push(v)    -> compare v with current min and push {v, newMin}
 *   - pop()      -> remove the pair; previous node already has its own min
 *
 * Invariant:
 *   For every node, its second field equals the minimum of all values from
 *   the bottom up to that node. push/pop preserve this invariant.
 *
 * Complexity:
 *   - Time per operation: O(1) for push/pop/top/getMin.
 *   - Extra space: one int per element (the running min).
 */

MinStack_155::MinStack_155() = default;

void MinStack_155::push(int val) {
    if (st_.empty()) {
        st_.emplace_back(val, val);
    } else {
        int curMin = st_.back().second;
        st_.emplace_back(val, val < curMin ? val : curMin);
    }
}

void MinStack_155::pop() {
    st_.pop_back();     // Problem guarantees non-empty on pop.
}

int MinStack_155::top() const {
    return st_.back().first;
}

int MinStack_155::getMin() const {
    return st_.back().second;
}
