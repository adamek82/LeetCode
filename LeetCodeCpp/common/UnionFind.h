#pragma once

#include <vector>

class UnionFind {
public:
    explicit UnionFind(int elementCount);

    int find(int node);
    void unionSets(int first, int second);

private:
    std::vector<int> parents;
    std::vector<int> componentSizes;
};
