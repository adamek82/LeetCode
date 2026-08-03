#pragma once
#include <list>
#include <utility>
#include <unordered_map>

using namespace std;

class LRUCache {
public:
    explicit LRUCache(int capacity);
    int get(int key);
    void put(int key, int value);

private:
    int _cap;
    // front = most-recently used, back = least-recently used
    list<pair<int,int>> _cache;
    unordered_map<int, list<pair<int,int>>::iterator> _map;
};
