#pragma once
#include "ListNode.h"

/*
 * 2807. Insert Greatest Common Divisors in Linked List
 *
 * Between every adjacent pair (a, b), insert a node with value gcd(a, b).
 * The list is modified in-place by splicing new nodes between existing ones.
 *
 * Both methods are O(n) time and O(1) extra space (besides the inserted nodes).
 */
class InsertGreatestCommonDivisors_2807 {
public:
    // Uses std::gcd from <numeric>.
    ListNode<int>* insertGreatestCommonDivisors_stdGcd(ListNode<int>* head);

    // Uses an explicitly implemented Euclidean algorithm.
    ListNode<int>* insertGreatestCommonDivisors_euclid(ListNode<int>* head);

private:
    static int gcd_euclid(int a, int b);
};
