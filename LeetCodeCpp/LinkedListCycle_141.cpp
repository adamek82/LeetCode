#include "LinkedListCycle_141.h"

/*
 * Linked List Cycle (LeetCode 141)
 * --------------------------------
 * Goal: detect whether a singly linked list contains a cycle.
 *
 * Approach — Floyd’s Tortoise and Hare:
 * - Maintain two pointers:
 *     slow: moves one step at a time
 *     fast: moves two steps at a time
 * - On each iteration:
 *     slow = slow->next
 *     fast = fast->next->next
 * - If there is no cycle, `fast` (or `fast->next`) will eventually become null,
 *   so the loop terminates and we return false.
 * - If there is a cycle, `fast` will eventually "lap" `slow` and they will
 *   point to the same node inside the cycle ⇒ return true.
 *
 * Structural note (why the cycle is always a “suffix”):
 * - In a standard singly linked list, each node has at most one outgoing `next`
 *   pointer (or null for the end). Consider the sequence obtained by starting
 *   at the head and repeatedly following `next`:
 *       v0 = head, v1 = v0->next, v2 = v1->next, ...
 * - Because the list is finite and each step has exactly one successor, there
 *   are only two possibilities:
 *     • We eventually reach null  → no cycle.
 *     • At some step, a node repeats (say v_i == v_j for 0 ≤ i < j).
 * - By minimality of the first repetition, v_i, v_{i+1}, ..., v_{j-1} are all
 *   distinct and form a directed cycle. From v_i onward, following `next`
 *   never leaves this cycle, because each node on that cycle has exactly one
 *   outgoing edge that stays within it. Hence the list decomposes uniquely
 *   into:
 *       μ = number of nodes before the cycle (the prefix),
 *       λ = length of the cycle (the suffix),
 *   and there cannot be any “tail after the cycle” or a cycle “in the middle”
 *   with nodes beyond it without violating the one-next-pointer structure.
 *
 * Correctness (proof sketch):
 * - No cycle:
 *   The `fast` pointer always advances strictly faster than `slow` and can
 *   never revisit a node in a finite acyclic list. Therefore, it must
 *   eventually reach a null pointer (or `fast->next` becomes null), which
 *   breaks the loop and we correctly return false.
 *
 * - With cycle:
 *   Let:
 *     μ = number of nodes before the cycle starts,
 *     λ = length of the cycle.
 *   After exactly μ steps, the slow pointer is at the first node of the cycle.
 *   The fast pointer moves twice as fast, so it enters the cycle no later than
 *   step μ (possibly earlier). From that moment on, both pointers stay inside
 *   the same cycle.
 *   Now reason modulo λ:
 *     - At each iteration, `slow` advances by +1 and `fast` by +2 around
 *       the cycle, so their relative position changes by +1 (mod λ) per step.
 *     - Hence within at most λ steps, this relative offset becomes 0, meaning
 *       `slow == fast` at some node in the cycle.
 *   Thus, if a cycle exists, the two pointers must eventually meet and we
 *   correctly return true.
 *
 * Complexity:
 * - Time:  O(n), where n is the number of nodes (each pointer takes at most
 *          a constant multiple of n steps).
 * - Space: O(1), we only use two pointers regardless of list size.
 */
bool LinkedListCycle_141::hasCycle(ListNode<int> *head)
{
    ListNode<int> *slow = head; // Slow pointer starts at head.
    ListNode<int> *fast = head; // Fast pointer starts at head.

    while (fast && fast->next) {
        slow = slow->next;          // Move slow pointer one step.
        fast = fast->next->next;    // Move fast pointer two steps.

        if (slow == fast) {
            return true; // Cycle detected.
        }
    }

    return false; // No cycle detected.
}