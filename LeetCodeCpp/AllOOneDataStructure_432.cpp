#include "AllOOneDataStructure_432.h"

/*
 * 432. All O`one Data Structure
 * -----------------------------
 * Data structure idea:
 *   We must support these operations in O(1) average time:
 *
 *     - inc(key):    increment the count of key
 *     - dec(key):    decrement the count of key
 *     - getMaxKey(): return any key with the maximum count
 *     - getMinKey(): return any key with the minimum count
 *
 *   To achieve this, we combine:
 *
 *     1) A doubly linked list (std::list<Node>) of "count buckets",
 *        sorted by count in ascending order.
 *
 *        Each node represents one distinct count value and stores:
 *          - count
 *          - all keys currently having that count
 *
 *        So:
 *          - nodeList.front() holds the minimum count
 *          - nodeList.back()  holds the maximum count
 *
 *     2) A hash map:
 *
 *          key2node[key] = iterator to the list node currently holding key
 *
 *        This lets us locate the current bucket of any key in O(1) average time.
 *
 * Core invariant:
 *   - The list is always sorted by count in strictly increasing order.
 *   - There is at most one list node for any given count.
 *   - Every key appears in exactly one node's key set.
 *   - key2node always points to the correct node for each existing key.
 *
 * How inc(key) works:
 *   1) If key does not exist yet:
 *      - Its new count becomes 1.
 *      - If the front node does not already represent count=1, create such a node.
 *      - Insert the key into that node and record it in key2node.
 *
 *   2) If key already exists:
 *      - Let curIt be the node currently holding the key, with count = c.
 *      - Remove the key from that node.
 *      - The key must move to count = c + 1, which should be the next node.
 *      - If the next node does not exist or does not have count = c + 1,
 *        insert a new node for c + 1 directly after curIt.
 *      - Insert the key into that destination node and update key2node.
 *      - If the old node became empty, erase it from the list.
 *
 * How dec(key) works:
 *   1) Let curIt be the node currently holding the key, with count = c.
 *   2) Remove the key from that node.
 *   3) If c - 1 == 0:
 *      - The key disappears completely from the data structure,
 *        so erase it from key2node.
 *   4) Otherwise:
 *      - The key must move to count = c - 1, which should be the previous node.
 *      - If the previous node does not exist or does not have count = c - 1,
 *        insert a new node for c - 1 directly before curIt.
 *      - Insert the key into that destination node and update key2node.
 *   5) If the old node became empty, erase it from the list.
 *
 * How getMaxKey() works:
 *   - If the structure is empty, return "".
 *   - Otherwise, the last node in the list has the maximum count.
 *   - Return any key from that node's key set.
 *
 * How getMinKey() works:
 *   - If the structure is empty, return "".
 *   - Otherwise, the first node in the list has the minimum count.
 *   - Return any key from that node's key set.
 *
 * Why it works (intuitive justification):
 *   - Keys only ever move between neighboring counts:
 *       c -> c + 1   during inc
 *       c -> c - 1   during dec
 *   - Therefore, once we know the current node of a key, we never need to search
 *     the whole structure; we only inspect its immediate neighbor in the list
 *     (next or previous), or create that neighbor if it does not exist.
 *   - The list stays sorted by count, so minimum and maximum are always available
 *     directly at the front and back.
 *   - Empty buckets are removed immediately, which preserves the invariant that
 *     each count appears in at most one node.
 *
 * Complexity:
 *   - inc(key):    O(1) average
 *   - dec(key):    O(1) average
 *   - getMaxKey(): O(1)
 *   - getMinKey(): O(1)
 *
 * Notes on complexity:
 *   - std::list insertion/erasure at a known iterator is O(1).
 *   - unordered_map and unordered_set operations are O(1) average.
 *   - Therefore all required operations satisfy the problem's O(1) average-time goal.
 */
AllOOneDataStructure_432::AllOOneDataStructure_432()
{
    // empty
}

void AllOOneDataStructure_432::inc(const string &key)
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
        auto nextIt = next(curIt);
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

void AllOOneDataStructure_432::dec(const string &key)
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
        auto prevIt = (curIt == nodeList.begin()) ? nodeList.end() : prev(curIt);

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

string AllOOneDataStructure_432::getMaxKey()
{
    // If no keys at all
    if (nodeList.empty()) return "";
    // The back of nodeList has the largest count
    // Return any key from that node's set
    return *(nodeList.back().keys.begin());
}

string AllOOneDataStructure_432::getMinKey()
{
    // If no keys at all
    if (nodeList.empty()) return "";
    // The front of nodeList has the smallest count
    // Return any key from that node's set
    return *(nodeList.front().keys.begin());
}
