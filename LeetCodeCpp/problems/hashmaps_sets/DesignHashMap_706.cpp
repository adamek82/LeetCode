#include "DesignHashMap_706.h"

MyHashMap::MyHashMap()
    /*
     * We need indices 0..kMaxKey inclusive, so the table size is kMaxKey + 1.
     * The vector constructor (size, value) fills all entries with kMissing (-1),
     * which is safe because valid values are in [0..1_000_000].
     */
    : values_(kMaxKey + 1, kMissing) {
}

void MyHashMap::put(int key, int value) {
    values_[key] = value;
}

int MyHashMap::get(int key) {
    return values_[key];
}

void MyHashMap::remove(int key) {
    values_[key] = kMissing;
}
