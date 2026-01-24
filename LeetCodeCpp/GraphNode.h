#pragma once
#include <vector>

using namespace std;

template <typename T = int>
class GraphNode {
public:
    T val;
    vector<GraphNode<T>*> neighbors;

    GraphNode() : val(T()), neighbors({}) {}
    GraphNode(T _val) : val(_val), neighbors({}) {}
    GraphNode(T _val, const vector<GraphNode<T>*>& _neighbors)
        : val(_val), neighbors(_neighbors) {}
};
