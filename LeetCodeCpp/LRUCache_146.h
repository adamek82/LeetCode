#pragma once
#include <list>
#include <utility>
#include <unordered_map>

class LRUCache {
public:
    explicit LRUCache(int capacity);
    int get(int key);
    void put(int key, int value);

private:
    int _cap;
    // front = most-recently used, back = least-recently used
    std::list<std::pair<int,int>> _cache;
    std::unordered_map<int, std::list<std::pair<int,int>>::iterator> _map;
};