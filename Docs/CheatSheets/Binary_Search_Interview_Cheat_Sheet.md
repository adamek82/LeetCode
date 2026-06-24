# Binary Search — Interview Cheat Sheet (LeetCode Set)

A compact refresher with C++-style patterns, invariants, and gotchas. Aimed as a 4–5 page pre-interview recap.

For full proofs, invariants, and termination arguments, see:

- `Docs/Algorithms/Binary_Search.md`

---

## Set Overview

| Problem | LC # | Difficulty | Score | Status |
|---|---:|:---:|:---:|:---:|
| Binary Search | 704 | Easy | 3/10 | ✔ |
| Search Insert Position | 35 | Easy | 3.5/10 | ✔ |
| Sqrt(x) | 69 | Easy | 4/10 | ✔ |
| First Bad Version | 278 | Easy | 4/10 | ✔ |
| Valid Perfect Square | 367 | Easy | 4/10 | ✔ |
| Search a 2D Matrix | 74 | Medium | 5/10 | ✔ |
| Find Minimum in Rotated Sorted Array | 153 | Medium | 6/10 | ✔ |
| Search in Rotated Sorted Array | 33 | Medium | 7/10 | ✔ |
| Koko Eating Bananas | 875 | Medium | 7/10 | ✔ |

---

## Quick Reference

**Core idea.** Binary search works when the search space is monotone in some sense:

- sorted array;
- sorted logical range, for example a matrix flattened to 1D;
- parameter `x` where a predicate changes monotonically.

There are three common loop shapes in this set.

### 1. Exact search — `while (left <= right)`

Use when you are looking for an exact value and the answer may be absent.

Predicate shape is not usually written explicitly; you compare `a[mid]` with `target`.

```text
[ possible candidates ]
  left          right
```

Typical rules:

- found: `return mid;`
- too small: `left = mid + 1;`
- too large: `right = mid - 1;`
- after the loop: interval is empty, so return failure.

Examples:

- LC 704 — Binary Search
- LC 74 — Search a 2D Matrix
- LC 33 — Search in Rotated Sorted Array
- LC 367 — Valid Perfect Square

---

### 2. First true / minimum feasible — `while (left < right)`

Use when the predicate has shape:

```text
false false false true true true
                   ^
               first true
```

Keep the interval non-empty and keep `mid` when it can still be the answer.

```cpp
int firstTrue(int left, int right) { // answer exists in [left, right]
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (ok(mid))
            right = mid;      // mid can still be the first true
        else
            left = mid + 1;   // mid is definitely false
    }
    return left;              // left == right
}
```

Examples:

- LC 278 — First Bad Version
- LC 875 — Koko Eating Bananas
- LC 153 — Find Minimum in Rotated Sorted Array, structurally similar

---

### 3. Last true / maximum feasible — `while (left <= right)`

Use when the predicate has shape:

```text
true true true false false false
           ^
       last true
```

Here both branches discard `mid` with `±1`, and the loop ends with an empty interval:

```text
true true true | false false false
          right left
```

Generic pattern:

```cpp
int lastTrue(int left, int right) {
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (ok(mid))
            left = mid + 1;   // mid works; try larger
        else
            right = mid - 1;  // mid is too large
    }
    return right;             // last true
}
```

Example:

- LC 69 — Sqrt(x), where `ok(mid)` means `mid * mid <= x`.

---

## Generic Templates

### 1. Exact search on indices — `while (left <= right)`

Used when the target may be absent.

```cpp
int binarySearch(const vector<int>& a, int target) {
    int left = 0, right = (int)a.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (a[mid] == target)
            return mid;
        else if (a[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}
```

**Invariant.** If the target exists, it is inside `[left, right]`. On every non-returning iteration, `mid` is discarded.

---

### 2. First true / lower-bound-style boundary — `while (left < right)`

Used when you know an answer exists and want the first position where `ok(x)` becomes true.

```cpp
int firstTrue(int left, int right) {
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (ok(mid))
            right = mid;
        else
            left = mid + 1;
    }
    return left;
}
```

**Invariant.** `[left, right]` is non-empty and contains the first true.

**Mental hook:** if `mid` can still be the answer, keep it.

---

### 3. Last true / upper-bound-minus-one boundary — `while (left <= right)`

Used when you want the last position where `ok(x)` is true.

```cpp
int lastTrue(int left, int right) {
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (ok(mid))
            left = mid + 1;
        else
            right = mid - 1;
    }
    return right;
}
```

**Invariant.** Everything before `left` is known true; everything after `right` is known false.

At exit:

```text
left == right + 1
```

so:

```text
right = last true
left  = first false
```

---

## Problem-by-Problem Patterns

### 704. Binary Search — exact hit or fail

Classic exact search.

- Search over indices `[0, n - 1]`.
- Return index if found.
- Return `-1` otherwise.

```cpp
int search(vector<int>& nums, int target) {
    int left = 0, right = (int)nums.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) return mid;
        if (nums[mid] < target) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}
```

---

### 74. Search a 2D Matrix — flatten to 1D

Treat the matrix as a sorted array of length `m * n`.

```cpp
bool searchMatrix(const vector<vector<int>>& mat, int target) {
    int m = mat.size(), n = mat[0].size();
    int left = 0, right = m * n - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        int val = mat[mid / n][mid % n];

        if (val == target) return true;
        if (val < target) left = mid + 1;
        else right = mid - 1;
    }

    return false;
}
```

Same exact-search logic, only with 1D-to-2D mapping.

---

### 367. Valid Perfect Square — exact search over values

Search for an integer root `r` such that `r * r == num`.

```cpp
bool isPerfectSquare(int num) {
    if (num == 1) return true;

    long long left = 1, right = num / 2;
    while (left <= right) {
        long long mid = left + (right - left) / 2;
        long long sq = mid * mid;

        if (sq == num) return true;
        if (sq < num) left = mid + 1;
        else right = mid - 1;
    }

    return false;
}
```

Still exact search: success requires equality.

---

### 69. Sqrt(x) — last true

Return `floor(sqrt(x))` without using `sqrt`.

Predicate:

```text
ok(mid) = mid * mid <= x
```

Predicate shape:

```text
true true true false false false
          ^
      answer
```

Use the last-true pattern. Avoid overflow by checking `mid <= x / mid` instead of `mid * mid <= x`.

```cpp
int mySqrt(int x) {
    if (x < 2) return x;

    int left = 1;
    int right = x / 2;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (mid <= x / mid)     // mid * mid <= x, without overflow
            left = mid + 1;     // mid works; try larger
        else
            right = mid - 1;    // mid is too large
    }

    return right;               // last value with right * right <= x
}
```

**Why `return right`?**

At loop exit:

```text
true true true | false false false
          right left
```

So `right` is the largest integer whose square does not exceed `x`.

---

### 35. Search Insert Position — exact search + insertion index

Same exact-search template, but if not found, return the insertion index.

```cpp
int searchInsert(const vector<int>& a, int target) {
    int left = 0, right = (int)a.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (a[mid] == target) return mid;
        if (a[mid] < target) left = mid + 1;
        else right = mid - 1;
    }

    return left;
}
```

At exit:

```text
left == right + 1
```

All indices `< left` are too small. Therefore `left` is the insertion position.

---

### 278. First Bad Version — first true

Predicate:

```text
isBad(v)
```

Shape:

```text
false false false true true true
                  ^
             first bad
```

```cpp
int firstBadVersion(int n) {
    int left = 1, right = n;

    while (left < right) {
        int mid = left + (right - left) / 2;
        if (isBadVersion(mid))
            right = mid;       // mid can still be the first bad
        else
            left = mid + 1;
    }

    return left;
}
```

Do not use `while (left <= right)` with `right = mid`; when `left == right`, this can loop forever.

---

### 153. Find Minimum in Rotated Sorted Array — boundary on structure

Compare `nums[mid]` with `nums[right]`.

- If `nums[mid] > nums[right]`, the minimum is strictly to the right of `mid`.
- Otherwise, `mid` can still be the minimum.

```cpp
int findMin(const vector<int>& nums) {
    int left = 0, right = (int)nums.size() - 1;

    while (left < right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] > nums[right])
            left = mid + 1;
        else
            right = mid;
    }

    return nums[left];
}
```

This is structurally similar to first-true search: one branch discards `mid`, the other keeps it.

---

### 875. Koko Eating Bananas — binary search on the answer

Search for the smallest feasible speed `k`.

Predicate:

```text
canFinish(k) = total hours at speed k <= h
```

Shape:

```text
false false false true true true
                   ^
          minimum feasible speed
```

```cpp
bool canFinish(const vector<int>& piles, int h, int k) {
    long long hours = 0;
    for (int p : piles) {
        hours += (p + k - 1) / k;  // ceil(p / k)
        if (hours > h) return false;
    }
    return true;
}

int minEatingSpeed(const vector<int>& piles, int h) {
    int left = 1;
    int right = *max_element(piles.begin(), piles.end());

    while (left < right) {
        int mid = left + (right - left) / 2;
        if (canFinish(piles, h, mid))
            right = mid;
        else
            left = mid + 1;
    }

    return left;
}
```

Classic first-true pattern over a parameter value.

---

### 33. Search in Rotated Sorted Array — structural exact search

Target may be absent, so use exact-search loop:

```cpp
while (left <= right)
```

At every step, at least one half is normally sorted.

```cpp
int search(const vector<int>& nums, int target) {
    int left = 0, right = (int)nums.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) return mid;

        if (nums[left] <= nums[mid]) {
            // Left half is sorted.
            if (nums[left] <= target && target < nums[mid])
                right = mid - 1;
            else
                left = mid + 1;
        } else {
            // Right half is sorted.
            if (nums[mid] < target && target <= nums[right])
                left = mid + 1;
            else
                right = mid - 1;
        }
    }

    return -1;
}
```

Still exact search: once `nums[mid] != target`, `mid` is discarded.

---

## How to Choose the Pattern

### Q1. Can the answer be absent?

If yes, often use exact search:

```cpp
while (left <= right)
```

Examples:

- LC 704 — Binary Search
- LC 74 — Search a 2D Matrix
- LC 33 — Search in Rotated Sorted Array
- LC 367 — Valid Perfect Square

---

### Q2. Are you looking for the first true?

Predicate shape:

```text
false false false true true true
```

Use:

```cpp
while (left < right)
```

and keep `mid` when it may still be the answer:

```cpp
if (ok(mid)) right = mid;
else left = mid + 1;
```

Examples:

- LC 278 — First Bad Version
- LC 875 — Koko Eating Bananas

---

### Q3. Are you looking for the last true?

Predicate shape:

```text
true true true false false false
```

Use:

```cpp
while (left <= right)
```

and discard `mid` in both branches:

```cpp
if (ok(mid)) left = mid + 1;
else right = mid - 1;
```

Return:

```cpp
right
```

Example:

- LC 69 — Sqrt(x)

---

## Common Gotchas & Invariants

- Always compute mid safely:

```cpp
int mid = left + (right - left) / 2;
```

- Exact search invariant:

```text
If the answer exists, it is in [left, right].
```

- First-true invariant:

```text
[left, right] is non-empty and contains the first true.
```

- Last-true invariant:

```text
Everything before left is true.
Everything after right is false.
left <= right + 1.
```

- `while (left < right)` usually means one branch keeps `mid`.

```cpp
right = mid;
```

- `while (left <= right)` usually means both branches discard `mid`.

```cpp
left = mid + 1;
right = mid - 1;
```

- `right = mid` with `while (left <= right)` can cause an infinite loop when `left == right`.

- For multiplication checks such as `mid * mid`, use `long long` or compare by division:

```cpp
mid <= x / mid
```

- For ceiling division of positive integers:

```cpp
ceil(p / k) == (p + k - 1) / k
```

---

## Mini Drills

**Q1. Why use `left + (right - left) / 2` instead of `(left + right) / 2`?**

To avoid integer overflow when `left` and `right` are large.

---

**Q2. When should I think `while (left <= right)`?**

When the interval may become empty and both branches discard `mid`, usually with `mid ± 1`.

Examples:

- exact search;
- last-true search, such as `Sqrt(x)`.

---

**Q3. When should I think `while (left < right)`?**

When the interval must remain non-empty and one branch keeps `mid` because it may still be the answer.

Examples:

- first bad version;
- minimum feasible speed;
- minimum in rotated sorted array.

---

**Q4. In first-bad-version style, why `right = mid` and not `right = mid - 1`?**

Because `mid` itself may be the first bad version. Dropping it can skip the answer.

---

**Q5. In `Sqrt(x)`, why do we return `right`?**

Because the loop ends with:

```text
true true true | false false false
          right left
```

So `right` is the last value whose square is `<= x`.

---

**Q6. In `Sqrt(x)`, why check `mid <= x / mid` instead of `mid * mid <= x`?**

To avoid overflow. For large `x`, `mid * mid` may not fit into `int`.

---

**Q7. What is binary search on the answer?**

You search over a parameter rather than an array index. If `ok(k)` is monotone, you can binary-search the smallest or largest feasible value.

Examples:

- Koko Eating Bananas: smallest speed that works.
- Sqrt(x): largest integer root that does not exceed `x`.
