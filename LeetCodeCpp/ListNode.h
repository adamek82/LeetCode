#pragma once

template <typename T = int>
struct ListNode {
    T val;
    ListNode* next;
    ListNode* random;

    // Default constructor
    ListNode() : val(T()), next(nullptr), random(nullptr) {}

    // Constructor with value
    ListNode(T x) : val(x), next(nullptr), random(nullptr) {}

    // Constructor with value and next pointer
    ListNode(T x, ListNode* next) : val(x), next(next), random(nullptr) {}
};