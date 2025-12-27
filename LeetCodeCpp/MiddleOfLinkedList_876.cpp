#include "MiddleOfLinkedList_876.h"
#include "ListNode.h"

/*
 * Middle of the Linked List (LeetCode 876) — tortoise & hare
 *
 * Idea
 * ----
 * Use two pointers:
 *   - `slow` moves 1 node per loop iteration,
 *   - `fast` moves 2 nodes per loop iteration.
 * When `fast` reaches the end, `slow` is at the middle.
 *
 * Loop condition and the "second middle" requirement
 * --------------------------------------------------
 * We iterate while:
 *   fast != nullptr && fast->next != nullptr
 * which means: we only take another step if `fast` can move forward by 2 nodes
 * (`fast->next->next` is safe).
 *
 * Let the list length be N.
 * After t iterations:
 *   slow has moved t steps,
 *   fast has moved 2t steps.
 *
 * - If N is odd (N = 2m + 1):
 *     After m iterations, `fast` is at the last node (index 2m), so `fast->next == nullptr`
 *     and the loop stops. `slow` is at index m — the unique middle.
 *
 * - If N is even (N = 2m):
 *     After m iterations, `fast` becomes nullptr (it jumps from index 2m-2 to "past the end"),
 *     so `fast == nullptr` and the loop stops. `slow` is at index m.
 *     The two middle nodes are indices (m-1) and m, so returning index m means returning
 *     the *second* middle node, exactly as required.
 *
 * Why this specific condition matters:
 * -----------------------------------
 * Because we keep iterating as long as `fast->next` exists, the loop executes one extra
 * iteration in the even-length case, pushing `slow` from the first middle (m-1) to the
 * second middle (m). If we stopped earlier, we'd return the first middle instead.
 *
 * Complexity
 * ----------
 * Time:  O(N)
 * Space: O(1)
 */
ListNode<int> *MiddleOfLinkedList_876::middleNode(ListNode<int> *head)
{
    // Initialize two pointers
    ListNode<int> *slow = head;
    ListNode<int> *fast = head;

    // Move fast by 2 steps and slow by 1 step until fast reaches the end
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Slow pointer now points to the middle node
    return slow;
}