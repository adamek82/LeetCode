#include "AllOOneDataStructure_432.h"

AllOOneDataStructure_432::AllOOneDataStructure_432()
{
    // empty
}

void AllOOneDataStructure_432::inc(const std::string &key)
{
    // Case 1: Key is NOT present yet
    if (key2node.find(key) == key2node.end()) {
        // If the list is empty or the front has count != 1, we need a new node for count=1
        if (nodeList.empty() || nodeList.front().count != 1) {
            nodeList.push_front(Node(1));
        }
        // Insert key into the node with count=1
        nodeList.front().keys.insert(key);
        // Update map
        key2node[key] = nodeList.begin();
    }
    // Case 2: Key already present
    else {
        auto curIt = key2node[key]; // current node iterator
        int oldCount = curIt->count;
        int newCount = oldCount + 1;

        // Remove this key from the current node's set
        curIt->keys.erase(key);

        // If there's a next node and it has count = newCount, use it
        auto nextIt = std::next(curIt);
        if (nextIt == nodeList.end() || nextIt->count != newCount) {
            // Insert a new node after curIt
            nextIt = nodeList.insert(nextIt, Node(newCount));
        }
        // Put the key in that next node
        nextIt->keys.insert(key);
        // Update the map
        key2node[key] = nextIt;

        // If the old node is now empty, remove it
        if (curIt->keys.empty()) {
            nodeList.erase(curIt);
        }
    }
}

void AllOOneDataStructure_432::dec(const std::string &key)
{
    auto curIt = key2node[key];
    int oldCount = curIt->count;
    int newCount = oldCount - 1;

    // Remove key from current node
    curIt->keys.erase(key);

    // If newCount == 0, key should be removed entirely
    if (newCount == 0) {
        key2node.erase(key);
    } else {
        // Move to the node that has (oldCount - 1)
        auto prevIt = (curIt == nodeList.begin()) ? nodeList.end() : std::prev(curIt);

        if (curIt == nodeList.begin() || prevIt->count != newCount) {
            // We need to insert a new node for count=newCount BEFORE curIt
            prevIt = nodeList.insert(curIt, Node(newCount));
        }
        // Insert the key in prevIt->keys
        prevIt->keys.insert(key);
        // Update map
        key2node[key] = prevIt;
    }

    // If the old node is empty, remove it
    if (curIt->keys.empty()) {
        nodeList.erase(curIt);
    }
}

std::string AllOOneDataStructure_432::getMaxKey()
{
    // If no keys at all
    if (nodeList.empty()) return "";
    // The back of nodeList has the largest count
    // Return any key from that node's set
    return *(nodeList.back().keys.begin());
}

std::string AllOOneDataStructure_432::getMinKey()
{
    // If no keys at all
    if (nodeList.empty()) return "";
    // The front of nodeList has the smallest count
    // Return any key from that node's set
    return *(nodeList.front().keys.begin());
}
