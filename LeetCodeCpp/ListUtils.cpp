#include "ListUtils.h"

// Create a linked list from a vector
template <typename T>
ListNode<T>* ListUtils::createLinkedList(const std::vector<T>& values) {
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
std::vector<T> ListUtils::toVector(ListNode<T>* head) {
    std::vector<T> result;

    while (head != nullptr) {
        result.push_back(head->val);
        head = head->next;
    }

    return result;
}

// Convert a linked list to a string representation
template <typename T>
std::string ListUtils::toString(ListNode<T>* head) {
    std::ostringstream oss;
    std::unordered_set<ListNode<T>*> visited;
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
    std::unordered_set<ListNode<T>*> visited;

    while (current && visited.find(current) == visited.end()) {
        visited.insert(current);
        ListNode<T>* next = current->next;
        delete current;
        current = next;
    }
}

// Create a linked list from a vector and set up a cycle if pos >= 0
template <typename T>
static ListNode<T>* ListUtils::createLinkedListWithCycle(const std::vector<T>& values, int pos) {
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
ListNode<T>* ListUtils::createLinkedListWithRandom(const std::vector<std::pair<T, std::optional<int>>>& nodes) {
    if (nodes.empty()) return nullptr;

    std::vector<ListNode<T>*> createdNodes;
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
    std::unordered_map<ListNode<T>*, int> list1Mapping;
    std::unordered_map<ListNode<T>*, int> list2Mapping;

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

// Explicit instantiation for int type
template ListNode<int>* ListUtils::createLinkedList<int>(const std::vector<int>&);
template std::vector<int> ListUtils::toVector<int>(ListNode<int>*);
template std::string ListUtils::toString<int>(ListNode<int>*);
template void ListUtils::freeList<int>(ListNode<int>*);
template ListNode<int>* ListUtils::createLinkedListWithCycle(const std::vector<int>& values, int pos);
template ListNode<int>* ListUtils::createLinkedListWithRandom<int>(const std::vector<std::pair<int, std::optional<int>>>&);
template bool ListUtils::compareListsWithRandom<int>(ListNode<int>* list1, ListNode<int>* list2);
