#include "DesignHashMap_706.h"

MyHashMap::MyHashMap()
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
