#include "ListUtils.h"
#include <unordered_map>
#include <unordered_set>
#include <sstream>

// Create a linked list from a vector
template <typename T>
ListNode<T>* ListUtils::createLinkedList(const vector<T>& values) {
    if (values.empty()) return nullptr;

    ListNode<T>* head = new ListNode<T>(values[0]);
    ListNode<T>* current = head;

    for (size_t i = 1; i < values.size(); ++i) {
        current->next = new ListNode<T>(values[i]);
        current = current->next;
    }

    return head;
}

// Convert a linked list to a vector
template <typename T>
vector<T> ListUtils::toVector(ListNode<T>* head) {
    vector<T> result;

    while (head != nullptr) {
        result.push_back(head->val);
        head = head->next;
    }

    return result;
}

// Convert a linked list to a string representation
template <typename T>
string ListUtils::toString(ListNode<T>* head) {
    ostringstream oss;
    unordered_set<ListNode<T>*> visited;
    while (head) {
        if (visited.find(head) != visited.end()) {
            oss << head->val << " (cycle)";
            return oss.str();
        }
        visited.insert(head);
        oss << head->val << " -> ";
        head = head->next;
    }
    oss << "null";
    return oss.str();
}

// Free the linked list memory
template <typename T>
static void ListUtils::freeList(ListNode<T>* head) {
    ListNode<T>* current = head;
    unordered_set<ListNode<T>*> visited;

    while (current && visited.find(current) == visited.end()) {
        visited.insert(current);
        ListNode<T>* next = current->next;
        delete current;
        current = next;
    }
}

// Create a linked list from a vector and set up a cycle if pos >= 0
template <typename T>
static ListNode<T>* ListUtils::createLinkedListWithCycle(const vector<T>& values, int pos) {
    if (values.empty()) return nullptr;

    ListNode<T>* head = new ListNode<T>(values[0]);
    ListNode<T>* current = head;
    ListNode<T>* cycleNode = head;

    for (size_t i = 1; i < values.size(); ++i) {
        current->next = new ListNode<T>(values[i]);
        current = current->next;

        if (static_cast<int>(i) == pos) {
            cycleNode = current;
        }
    }

    if (pos >= 0) {
        current->next = cycleNode;
    }

    return head;
}

template <typename T>
ListNode<T>* ListUtils::createLinkedListWithRandom(const vector<pair<T, optional<int>>>& nodes) {
    if (nodes.empty()) return nullptr;

    vector<ListNode<T>*> createdNodes;
    ListNode<T>* head = new ListNode<T>(nodes[0].first);
    createdNodes.push_back(head);

    ListNode<T>* current = head;
    for (size_t i = 1; i < nodes.size(); ++i) {
        current->next = new ListNode<T>(nodes[i].first);
        current = current->next;
        createdNodes.push_back(current);
    }

    current = head;
    for (size_t i = 0; i < nodes.size(); ++i) {
        if (nodes[i].second.has_value()) {
            current->random = createdNodes[nodes[i].second.value()];
        }
        current = current->next;
    }

    return head;
}

template <typename T>
bool ListUtils::compareListsWithRandom(ListNode<T>* list1, ListNode<T>* list2) {
    unordered_map<ListNode<T>*, int> list1Mapping;
    unordered_map<ListNode<T>*, int> list2Mapping;

    ListNode<T>* current1 = list1;
    ListNode<T>* current2 = list2;
    int index = 0;

    // Build mappings and compare node values
    while (current1 != nullptr && current2 != nullptr) {
        if (current1->val != current2->val) return false;

        list1Mapping[current1] = index;
        list2Mapping[current2] = index;

        current1 = current1->next;
        current2 = current2->next;
        ++index;
    }

    if (current1 != nullptr || current2 != nullptr) return false;

    // Compare random pointers
    current1 = list1;
    current2 = list2;
    while (current1 != nullptr && current2 != nullptr) {
        if ((current1->random == nullptr) != (current2->random == nullptr)) return false;
        if (current1->random != nullptr &&
            list1Mapping[current1->random] != list2Mapping[current2->random]) {
            return false;
        }
        current1 = current1->next;
        current2 = current2->next;
    }

    return true;
}

/*
    NOTE: Explicit template instantiations (for `int`) are required here because the
    template *definitions* live in this `.cpp` file, not in the header.

    With templates, the compiler must see the full function body at the point of use
    to generate code for a concrete type (e.g., `ListNode<int>`). If a translation unit
    includes only `ListUtils.h`, it sees just the declarations, so it cannot instantiate
    `ListUtils::createLinkedList<int>()`, `toVector<int>()`, etc. That typically ends up
    as "undefined reference / unresolved external symbol" at link time.

    By explicitly instantiating the commonly used `int` variants in this `.cpp`, we force
    the compiler to emit the corresponding symbols once, in a single place, and other
    translation units can link against them without needing the template bodies in the header.

    Alternatives would be:
      - move the template definitions into the header (or an included `.inl/.tpp`),
      - or keep definitions in `.cpp` but add explicit instantiations for every type used.
*/
template ListNode<int>* ListUtils::createLinkedList<int>(const vector<int>&);
template vector<int> ListUtils::toVector<int>(ListNode<int>*);
template string ListUtils::toString<int>(ListNode<int>*);
template void ListUtils::freeList<int>(ListNode<int>*);
template ListNode<int>* ListUtils::createLinkedListWithCycle(const vector<int>& values, int pos);
template ListNode<int>* ListUtils::createLinkedListWithRandom<int>(const vector<pair<int, optional<int>>>&);
template bool ListUtils::compareListsWithRandom<int>(ListNode<int>* list1, ListNode<int>* list2);
