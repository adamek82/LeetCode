#pragma once
#include <vector>

template <typename T = int>
class GraphNode {
public:
    T val;
    std::vector<GraphNode<T>*> neighbors;

    GraphNode() : val(T()), neighbors({}) {}
    GraphNode(T _val) : val(_val), neighbors({}) {}
    GraphNode(T _val, const std::vector<GraphNode<T>*>& _neighbors)
        : val(_val), neighbors(_neighbors) {}
};