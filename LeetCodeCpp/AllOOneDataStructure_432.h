#pragma once
#include <string>
#include <list>
#include <unordered_map>
#include <unordered_set>

using namespace std;

struct Node {
    int count;
    unordered_set<string> keys;
    Node(int c) : count(c) {}
};

class AllOOneDataStructure_432 {
public:
    AllOOneDataStructure_432();
    void inc(const string &key);
    void dec(const string &key);
    string getMaxKey();
    string getMinKey();

private:
    // A list of nodes sorted by count (ascending).
    // front() will have the smallest count, back() the largest.
    list<Node> nodeList;

    // Maps each key to the corresponding iterator in nodeList.
    unordered_map<string, list<Node>::iterator> key2node;
};
