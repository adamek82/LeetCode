#pragma once
#include <vector>
#include <utility>

using namespace std;

class MinStack_155 {
public:
    MinStack_155() = default;

    void push(int val);
    void pop();
    int  top() const;
    int  getMin() const;

private:
    // Each entry stores: {value, min_so_far_at_this_node}
    vector<pair<int, int>> st_;
};
