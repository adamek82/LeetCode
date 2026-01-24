#include "InsertGreatestCommonDivisors_2807.h"
#include <numeric>   // std::gcd

/*
 * Insert Greatest Common Divisors in Linked List (LeetCode 2807)
 *
 * Idea
 * ----
 * Walk the list once with a pointer `cur`. For each adjacent pair (cur, cur->next):
 *   1) compute g = gcd(cur->val, cur->next->val),
 *   2) allocate a new node holding g,
 *   3) splice it between cur and cur->next,
 *   4) advance cur to the original next node.
 *
 * Invariant
 * ---------
 * Before each iteration, `cur` points to an original node, and all nodes strictly
 * before `cur` already have their gcd-nodes inserted between original neighbors.
 *
 * Complexity
 * ----------
 * Time:  O(n)
 * Space: O(1) extra (not counting the newly inserted nodes)
 */

ListNode<int>* InsertGreatestCommonDivisors_2807::insertGreatestCommonDivisors_stdGcd(ListNode<int>* head)
{
    if (head == nullptr) return nullptr;

    ListNode<int>* cur = head;
    while (cur != nullptr && cur->next != nullptr) {
        int g = std::gcd(cur->val, cur->next->val);

        ListNode<int>* inserted = new ListNode<int>(g);
        inserted->next = cur->next;
        cur->next = inserted;

        cur = inserted->next; // jump over the inserted node
    }
    return head;
}

int InsertGreatestCommonDivisors_2807::gcd_euclid(int a, int b)
{
    // Make it robust even if values are negative (LeetCode constraints are positive).
    if (a < 0) a = -a;
    if (b < 0) b = -b;

    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

ListNode<int>* InsertGreatestCommonDivisors_2807::insertGreatestCommonDivisors_euclid(ListNode<int>* head)
{
    if (head == nullptr) return nullptr;

    ListNode<int>* cur = head;
    while (cur != nullptr && cur->next != nullptr) {
        int g = gcd_euclid(cur->val, cur->next->val);

        ListNode<int>* inserted = new ListNode<int>(g);
        inserted->next = cur->next;
        cur->next = inserted;

        cur = inserted->next;
    }
    return head;
}
