#include "UnionFind.h"

#include <numeric>
#include <utility>

using namespace std;

UnionFind::UnionFind(int elementCount)
    : parents(elementCount),
      componentSizes(elementCount, 1)
{
    iota(parents.begin(), parents.end(), 0);
}

int UnionFind::find(int node)
{
    if (parents[node] != node) {
        parents[node] = find(parents[node]);
    }

    return parents[node];
}

void UnionFind::unionSets(int first, int second)
{
    int firstRoot = find(first);
    int secondRoot = find(second);

    if (firstRoot == secondRoot) {
        return;
    }

    if (componentSizes[firstRoot] < componentSizes[secondRoot]) {
        swap(firstRoot, secondRoot);
    }

    parents[secondRoot] = firstRoot;
    componentSizes[firstRoot] += componentSizes[secondRoot];
}
