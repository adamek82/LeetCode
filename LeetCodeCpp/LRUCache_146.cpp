#include "LRUCache_146.h"

LRUCache::LRUCache(int capacity)
    : _cap(capacity) {}

int LRUCache::get(int key) {
    auto it = _map.find(key);
    if (it == _map.end()) return -1;
    // move accessed node to front (MRU)
    _cache.splice(_cache.begin(), _cache, it->second);
    return it->second->second;
}

void LRUCache::put(int key, int value) {
    auto it = _map.find(key);
    if (it != _map.end()) {
        // key exists: update and move to front
        it->second->second = value;
        _cache.splice(_cache.begin(), _cache, it->second);
    } else {
        // key not present: evict LRU if at capacity
        if (_cache.size() == _cap) {
            auto &lru = _cache.back();
            _map.erase(lru.first);
            _cache.pop_back();
        }
        // insert new item at front
        _cache.emplace_front(key, value);
        _map[key] = _cache.begin();
    }
}