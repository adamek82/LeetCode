# Heap — Quick Guide (LeetCode Set)

A compact refresher with C++ `priority_queue` patterns, correctness sketches, and gotchas. Fits on ~3–4 pages.

---

## Quick Reference

**Heaps in C++ (`std::priority_queue`)**

```cpp
// Max-heap of ints (default): top() is the largest
std::priority_queue<int> pq;

// Min-heap of ints
std::priority_queue<int, std::vector<int>, std::greater<int>> minpq;

// Build from range in linear-time heapify
std::priority_queue<int> pq2(stones.begin(), stones.end());

// push vs emplace
pq.push(42);            // pushes a ready-made value
pq.emplace(42);         // constructs in-place (useful for complex types)

// Inspect/remove
int x = pq.top();       // O(1)
pq.pop();               // O(log n)

// Custom comparator (e.g., ListNode*), min-heap by node->val
auto cmp = [](const ListNode* a, const ListNode* b){ return a->val > b->val; };
std::priority_queue<ListNode*, std::vector<ListNode*>, decltype(cmp)> q(cmp);

// CTAD trick (no explicit <T,...>): deduce T from comparator & container
auto compare = [](ListNode<int>* a, ListNode<int>* b){ return a->val > b->val; };
std::priority_queue minHeap(               // T deduced as ListNode<int>*
    compare,                               // comparator instance
    std::vector<ListNode<int>*>{}          // empty container fixes value_type
);

// <algorithm> heap utilities on a vector
std::vector<int> v = {3,1,4,1,5};
std::make_heap(v.begin(), v.end());        // max-heap in-place, O(n)
std::pop_heap(v.begin(), v.end());         // moves max to v.back()
int maxv = v.back(); v.pop_back();         // actually remove it
v.push_back(9); std::push_heap(v.begin(), v.end());
```

**Notes**

- Default comparator is `std::less` ⇒ **max-heap**. Use `std::greater` or invert predicate for a **min-heap**.
- `emplace` avoids extra copy/move for complex types; for PODs it’s same as `push`.
- `pop_heap` on a vector only *moves* the extremum; call `v.pop_back()` to erase it.
- Comparators must define a **strict weak ordering**.

---

## Set Overview

| Problem | LC # | Difficulty | Score | Status |
|---|---:|:---:|:---:|:---:|
| Last Stone Weight | 1046 | Easy | 5/10 | ✔ |
| Kth Largest Element in an Array | 215 | Medium | 6/10 | ✔ |
| Top K Frequent Elements | 347 | Medium | 6/10 | ✔ |
| K Closest Points to Origin | 973 | Medium | 6.5/10 | ✔ |
| Merge K Sorted Linked Lists | 23 | Hard | 8/10 | ✔ |

---

## 1046. Last Stone Weight — Max-Heap

**Idea.** Maintain a max-heap of stone weights. Repeatedly remove two heaviest stones `y ≥ x`; if `y ≠ x`, push `(y − x)` back. When ≤1 stone remains, return its weight (or 0).

**Pseudocode**

```text
pq ← max-heap built from stones
while size(pq) > 1:
    y ← pq.pop_max()
    x ← pq.pop_max()
    if y ≠ x: pq.push(y − x)
return (pq.empty ? 0 : pq.top())
```

**Correctness (sketch).** Only the two largest stones affect the next outcome; smashing the current maxima first is safe by an exchange argument. Invariants: heap holds the current multiset; each loop strictly decreases it ⇒ termination.

**Complexity.** Build `O(n)`. Each pop/push `O(log n)` performed `O(n)` times ⇒ `O(n log n)` time, `O(n)` space.

**C++ snippet**

```cpp
std::priority_queue<int> pq(stones.begin(), stones.end());
while (pq.size() > 1) {
    int y = pq.top(); pq.pop();
    int x = pq.top(); pq.pop();
    if (y != x) pq.push(y - x);
}
return pq.empty() ? 0 : pq.top();
```

---

## 215. Kth Largest Element in an Array — Heaps

Two patterns:

**(A) Max-heap of all elements** ⇒ pop `k−1` times; answer is `top()`.

**(B) Min-heap of size `k`** holds the `k` largest seen so far; answer is `top()` of min-heap.

**Pseudocode**

```text
(A) Max-heap:
pq ← max-heap over all nums
repeat k−1 times: pq.pop_max()
return pq.top()

(B) Min-heap (preferred):
pq ← empty min-heap
for x in nums:
    pq.push(x)
    if size(pq) > k: pq.pop_min()
return pq.top()   // kth largest
```

**Correctness.** (A) After removing the largest `k−1`, the next is the kth. (B) Invariant: after processing `i` items, `pq` keeps the `k` largest among them; its minimum is the kth largest; preserved by replace-on-overflow.

**Complexity.** Max-heap: `O(n log n)` time. Min-heap: `O(n log k)` time, `O(k)` space.

**C++ snippet**

```cpp
// (A) Max-heap
std::priority_queue<int> mx(nums.begin(), nums.end());
for (int i = 1; i < k; ++i) mx.pop();
return mx.top();

// (B) Min-heap of size k
std::priority_queue<int, std::vector<int>, std::greater<int>> mn;
for (int x : nums) { mn.push(x); if ((int)mn.size() > k) mn.pop(); }
return mn.top();
```

---

## 347. Top K Frequent Elements — Min-Heap of (freq, value)

**Idea.** Count with a hash map; keep a **min-heap** of pairs `(frequency, value)` with capacity `k`. If heap grows beyond `k`, pop the smallest frequency.

**Pseudocode**

```text
freq ← hashmap counts
pq   ← min-heap of pairs (f, v) ordered by f
for (v, f) in freq:
    pq.push((f, v))
    if size(pq) > k: pq.pop()   // drop least frequent
answer ← values extracted from pq (order arbitrary)
```

**Correctness.** Invariant: `pq` stores `k` highest-frequency values among processed ones; replace the current min frequency when a higher one appears.

**Complexity.** `O(n log k)` after counting; `O(n)` map space + `O(k)` heap.

**C++ snippet**

```cpp
std::unordered_map<int,int> freq;
for (int x : nums) ++freq[x];

using P = std::pair<int,int>; // (freq, value)
std::priority_queue<P, std::vector<P>, std::greater<P>> pq;

for (auto [v,f] : freq) {
    pq.emplace(f, v);
    if ((int)pq.size() > k) pq.pop();
}

std::vector<int> ans;
while (!pq.empty()) { ans.push_back(pq.top().second); pq.pop(); }
return ans;
```

---

## 973. K Closest Points to Origin — Max-Heap of size k

**Idea.** Maintain a **max-heap** of size `k` keyed by squared distance; if a new point is closer than heap top, replace top. Squared distance avoids `sqrt` and preserves order.

**Pseudocode**

```text
pq ← max-heap of pairs (dist2, index) with capacity k
for i in [0..n-1]:
    d ← x[i]^2 + y[i]^2
    if size(pq) < k: pq.push((d, i))
    else if d < pq.top().dist2:
        pq.pop(); pq.push((d, i))
return points at indices stored in pq
```

**Complexity.** `O(n log k)` time, `O(k)` space.

**C++ snippet**

```cpp
using Item = std::pair<long long,int>;               // (dist^2, index)
std::priority_queue<Item> pq;                        // max-heap by dist^2

auto dist2 = [&](const std::vector<int>& p){
    return 1LL*p[0]*p[0] + 1LL*p[1]*p[1];
};

for (int i = 0; i < (int)points.size(); ++i) {
    long long d = dist2(points[i]);
    if ((int)pq.size() < k) pq.emplace(d, i);
    else if (d < pq.top().first) { pq.pop(); pq.emplace(d, i); }
}

// collect k points from pq
std::vector<std::vector<int>> out;
while (!pq.empty()) { out.push_back(points[pq.top().second]); pq.pop(); }
return out;
```

---

## 23. Merge K Sorted Lists — Min-Heap of heads

**Idea.** Put each list’s head into a **min-heap** ordered by `node->val`. Repeatedly extract the smallest node, append to output, and push its successor.

**Pseudocode**

```text
cmp(a,b) = (a->val > b->val)   // inverted for min-heap behavior
pq  ← min-heap of ListNode* using cmp
for each list head h: if h != null: pq.push(h)
dummy ← new ListNode(); tail ← dummy
while !pq.empty():
    node ← pq.pop_min()
    tail.next ← node; tail ← node
    if node.next != null: pq.push(node.next)
return dummy.next
```

**Complexity.** Every one of `N` nodes is pushed and popped once ⇒ `O(N log k)` time, `O(k)` extra space.

**C++ snippet**

```cpp
auto cmp = [](ListNode<int>* a, ListNode<int>* b){ return a->val > b->val; };
std::priority_queue<ListNode<int>*, std::vector<ListNode<int>*>, decltype(cmp)> pq(cmp);

for (auto h : lists) if (h) pq.push(h);

ListNode<int> dummy, *tail = &dummy;

while (!pq.empty()) {
    auto node = pq.top(); pq.pop();
    tail->next = node; tail = node;
    if (node->next) pq.push(node->next);
}
return dummy.next;
```

---

## Common Pitfalls with Heaps

- **Comparator direction.** `priority_queue` treats `Compare` as “is *a* before *b*?”; with `std::less` it’s a max-heap. For a min-heap use `std::greater` or invert the predicate.
- **Strict weak ordering.** Custom comparators must be transitive and never return `true` in both directions for ties.
- **Pointer comparators & captures.** Avoid capturing references to locals that won’t outlive the heap.
- **CTAD gotcha.** When using class template argument deduction, pass an explicit empty container to stabilize `value_type` deduction.
- **`make_heap`/`pop_heap` semantics.** Remember `pop_heap` only moves the extremum; call `v.pop_back()`.
- **Pairs and ordering.** `std::greater<std::pair<...>>` gives a min-heap by `(first, then second)`; no stability for equal keys.
- **Kth largest off-by-one.** `k` is 1-indexed.
- **Distance overflow.** Use `1LL*a*a + 1LL*b*b` for squared distances.
- **Zero reinsert in 1046.** Don’t push back `0` when stones are equal.

---

## Mini Drills (tiny answers below each)

**Q:** Which value is at `top()` after inserting `[3, 1, 5, 2]` into default `priority_queue`?  
**Q:** Turn a `priority_queue<int>` into a min-heap in one line.  
**Q:** Fill the blank: maintain a **____-heap** of size `k` to compute the kth largest in `O(n log k)`.  
**Q:** Fix the bug — we want a min-heap by `node->val`: `std::priority_queue<ListNode*, ???> pq;`  
**Q:** Vector heap API: after `std::make_heap(v.begin(), v.end());` what two steps remove the current maximum?  
**Q:** Given points `(3,4), (2,2), (0,5)` and `k=2`, which two are returned by the max-heap-of-size-`k` pattern (ties arbitrary)?  
**Q:** Why is a min-heap (by freq) better than a max-heap over all pairs for Top K Frequent? Give complexity.  
**Q:** Pairs — min-heap by `(freq ASC, value ASC)` using only standard comparators. Fill the `???`:  
`using P = std::pair<int,int>; std::priority_queue<P, std::vector<P>, ???> pq;`  
**Q:** Pairs — min-heap by `(freq ASC, value DESC)`. Write a comparator lambda for `priority_queue`.  
**Q:** Tuples — MAX-heap by `(a DESC, b ASC, c DESC)` for `std::tuple<int,int,int>`. Provide `Compare` lambda.

### Answers (tiny)

1. **A1.** 5.
2. **A2.** `std::priority_queue<int, std::vector<int>, std::greater<int>> pq;`
3. **A3.** `min`.
4. **A4.** Use comparator `a->val > b->val` and pass its instance: `auto cmp = [](const ListNode* a, const ListNode* b){ return a->val > b->val; };` `std::priority_queue<ListNode*, std::vector<ListNode*>, decltype(cmp)> pq(cmp);`
5. **A5.** `std::pop_heap(v.begin(), v.end());` then `v.pop_back();`
6. **A6.** `(2,2)` and any of `(3,4)` or `(0,5)` (tie on 25).
7. **A7.** Keep only `k` items ⇒ `O(n log k)` after counting (vs `O(n log n)`).
8. **A8.** `std::greater<P>`.
9. **A9.** `return (a.first > b.first) || (a.first == b.first && a.second < b.second);`
10. **A10.**  
    ```cpp
    auto cmp = [](const std::tuple<int,int,int>& x, const std::tuple<int,int,int>& y){
        auto [ax,bx,cx]=x; auto [ay,by,cy]=y;
        if (ax != ay) return ax < ay;      // larger a is greater ⇒ x<y when ax<ay
        if (bx != by) return bx > by;      // smaller b is greater ⇒ x<y when bx>by
        return cx < cy;                     // larger c is greater ⇒ x<y when cx<cy
    };
    ```

---

**Tip.** Prefer the **min-heap-of-size-`k`** pattern for streaming/top-k; prefer **heapify** with range constructor for bulk builds in `O(n)`.
