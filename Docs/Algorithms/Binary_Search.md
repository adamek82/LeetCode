# Binary Search

Binary search is a technique for repeatedly cutting a search space in half.

It is most commonly used on sorted arrays, but the deeper idea is more general:
binary search works whenever the search space has a monotone structure.

There are two major families of binary search patterns:

1. **Exact search**
   Find a concrete value if it exists.
   The answer may be absent.

2. **Boundary search**
   Find the first or last position where a monotone condition changes.
   Usually the answer is derived from the final boundary.

This document focuses on invariants, correctness, termination, and common
implementation pitfalls.

---

## 1. Exact Search in a Sorted Array

Problem shape:

```cpp
int search(vector<int>& nums, int target);
```

Given a sorted array `nums`, return the index of `target`, or `-1` if `target`
does not occur in the array.

The array is sorted in non-decreasing order:

```text
nums[0] <= nums[1] <= ... <= nums[n - 1]
```

A typical implementation:

```cpp
int search(vector<int>& nums, int target)
{
    int left = 0;
    int right = static_cast<int>(nums.size()) - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] == target) {
            return mid;
        }

        if (nums[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1;
}
```

---

## 2. Candidate Interval

In exact search we maintain a closed candidate interval:

```text
[left, right]
```

This interval contains all indices that have not yet been ruled out.

At any point:

```text
indices before left        -> already ruled out
indices from left to right -> still possible candidates
indices after right        -> already ruled out
```

So the mental model is:

```text
[ ruled out ][ candidates ][ ruled out ]
             left      right
```

The interval is allowed to become empty.
For a closed interval, emptiness is represented by:

```text
left > right
```

---

## 3. Loop Invariant

At the beginning of each loop iteration:

1. Every index before `left` has been ruled out:

```text
for every i such that 0 <= i < left:
    nums[i] != target
```

2. Every index after `right` has been ruled out:

```text
for every i such that right < i < nums.size():
    nums[i] != target
```

3. Therefore, if `target` occurs in `nums`, it can only occur inside:

```text
[left, right]
```

4. Bounds:

```text
0 <= left <= nums.size()
-1 <= right < nums.size()
```

When `left <= right`, `[left, right]` is a valid non-empty closed interval of
array indices.

When `left > right`, the candidate interval is empty.

---

## 4. Initialization

Initially:

```cpp
int left = 0;
int right = static_cast<int>(nums.size()) - 1;
```

Before the first iteration:

* there are no indices before `left`;
* there are no indices after `right`;
* no valid position has been ruled out incorrectly.

So the invariant is true before the loop starts.

For an empty vector:

```text
nums.size() == 0
left == 0
right == -1
```

Therefore:

```text
left <= right
```

is immediately false, and the function returns `-1`.

---

## 5. Why `while (left <= right)`?

This exact-search version uses a closed interval.

The loop condition:

```cpp
while (left <= right)
```

means:

```text
while the candidate interval is non-empty
```

When:

```text
left == right
```

there is exactly one remaining candidate index.
That index still has to be checked.

If we used:

```cpp
while (left < right)
```

then the loop would stop too early when only one candidate remained.

Example:

```text
nums   = [1, 3, 5, 7, 9]
target = 9
```

After a few iterations, we may reach:

```text
left = 4
right = 4
```

The remaining candidate interval is:

```text
[4, 4]
```

This interval contains one valid index, and `nums[4] == 9`.

With `left < right`, the loop would stop before checking index `4`.

With `left <= right`, we enter the loop one more time, check `nums[4]`, and
return the correct index.

---

## 6. Why Compute `mid` This Way?

Prefer:

```cpp
int mid = left + (right - left) / 2;
```

over:

```cpp
int mid = (left + right) / 2;
```

The second version can overflow when `left` and `right` are large.

The safer version first computes the distance:

```text
right - left
```

and then adds half of that distance to `left`.

During the loop, we know:

```text
left <= right
```

so:

```text
0 <= right - left
```

and therefore:

```text
left <= mid <= right
```

Thus `mid` is always a valid index inside the current candidate interval.

---

## 7. Preservation of the Invariant

Each iteration computes `mid` and compares `nums[mid]` with `target`.

There are three cases.

---

### Case 1: `nums[mid] == target`

```cpp
if (nums[mid] == target) {
    return mid;
}
```

This is immediately correct because:

```text
left <= mid <= right
```

so `mid` is a valid index, and we have directly checked that:

```text
nums[mid] == target
```

---

### Case 2: `nums[mid] < target`

```cpp
left = mid + 1;
```

Because the array is sorted in non-decreasing order, every index `i <= mid`
satisfies:

```text
nums[i] <= nums[mid] < target
```

Therefore `target` cannot occur at any index:

```text
i <= mid
```

So it is safe to discard:

```text
[left, mid]
```

and continue searching only in:

```text
[mid + 1, right]
```

The new `left` becomes:

```text
mid + 1
```

All indices before the new `left` have now been ruled out correctly.

---

### Case 3: `nums[mid] > target`

```cpp
right = mid - 1;
```

Because the array is sorted in non-decreasing order, every index `i >= mid`
satisfies:

```text
nums[i] >= nums[mid] > target
```

Therefore `target` cannot occur at any index:

```text
i >= mid
```

So it is safe to discard:

```text
[mid, right]
```

and continue searching only in:

```text
[left, mid - 1]
```

The new `right` becomes:

```text
mid - 1
```

All indices after the new `right` have now been ruled out correctly.

---

## 8. Correctness

Correctness has two parts:

1. **Soundness** — if the function returns an index, it is a valid answer.
2. **Completeness** — if the target exists, the function will not incorrectly
   return `-1`.

---

### 8.1. Soundness: No False Positives

The function returns an index only here:

```cpp
if (nums[mid] == target) {
    return mid;
}
```

During the loop, `mid` is always inside the current candidate interval:

```text
left <= mid <= right
```

and the candidate interval is a valid range of array indices.

Therefore, every returned index is valid and really contains `target`.

---

### 8.2. Completeness: No False Negatives

The invariant says:

```text
If target occurs in nums, it can only occur inside [left, right].
```

Each non-returning iteration removes only indices where `target` cannot occur:

* if `nums[mid] < target`, all indices `<= mid` are too small;
* if `nums[mid] > target`, all indices `>= mid` are too large.

So the algorithm never discards a possible occurrence of `target`.

When the loop terminates:

```text
!(left <= right)
```

which means:

```text
left > right
```

So the candidate interval is empty.

Since all possible positions outside the candidate interval have already been
ruled out, and the candidate interval is now empty, there is no valid index left
where `target` could occur.

Returning `-1` is therefore correct.

---

## 9. Termination

While the loop runs:

```text
left <= right
```

so the candidate interval has length:

```text
right - left + 1
```

This length is a non-negative integer.

On every non-returning iteration, the interval strictly shrinks:

* if `nums[mid] < target`, then `left` becomes `mid + 1`;
* if `nums[mid] > target`, then `right` becomes `mid - 1`.

Since:

```text
left <= mid <= right
```

each update removes at least `mid` from the candidate interval.

A non-negative integer cannot strictly decrease forever.

Therefore the loop must eventually terminate.

---

## 10. Complexity

Each iteration cuts the candidate interval roughly in half.

Therefore:

```text
Time:  O(log n)
Space: O(1)
```

where:

```text
n = nums.size()
```

---

## 11. Implementation Pitfalls

### 11.1. `nums.size()` is unsigned

`nums.size()` returns `size_t`, which is unsigned.

This is dangerous:

```cpp
int right = nums.size() - 1;
```

If `nums` is empty, then:

```text
nums.size() == 0
```

and the subtraction happens in unsigned arithmetic:

```text
0u - 1u
```

This underflows to a very large unsigned value.

A common LeetCode-style solution is:

```cpp
int right = static_cast<int>(nums.size()) - 1;
```

For an empty vector this gives:

```text
static_cast<int>(0) - 1 == -1
```

so:

```text
left == 0
right == -1
```

and the loop does not run.

This assumes that `nums.size()` fits into `int`, which is fine for typical
LeetCode constraints.

In production code, consider using a signed size type, for example:

```cpp
std::ptrdiff_t
```

or, in C++20:

```cpp
std::ssize(nums)
```

---

### 11.2. Dropping `mid`

In exact search, after checking:

```cpp
if (nums[mid] == target)
```

and not returning, `mid` is known not to be the answer.

Therefore the update must discard `mid`:

```cpp
left = mid + 1;
right = mid - 1;
```

Do not write:

```cpp
left = mid;
right = mid;
```

in this exact-search pattern, because that may fail to make progress and can
cause an infinite loop.

---

### 11.3. `left <= right` versus `left < right`

Use:

```cpp
while (left <= right)
```

when:

* the target may be absent;
* the candidate interval is allowed to become empty;
* you return immediately on exact match;
* after the loop you return failure, such as `-1` or `false`;
* or you are using a last-true / first-false style and return a boundary value
  such as `right` or `left`.

Use:

```cpp
while (left < right)
```

for boundary-style searches where:

* the answer is known to exist inside the interval;
* the interval is kept non-empty;
* the loop stops when `left == right`;
* the final index is the answer.

---

## 12. Boundary Search: First True

Boundary search is used when we want the first or last value satisfying a
monotone predicate.

The most common boundary pattern is **first true**.

Example predicate shape:

```text
false false false true true true
                  ^
              first true
```

Generic pattern:

```cpp
int firstTrue(int left, int right)
{
    while (left < right) {
        int mid = left + (right - left) / 2;

        if (ok(mid)) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }

    return left;
}
```

The invariant is different from exact search:

```text
[left, right] is non-empty and contains at least one valid answer.
```

The key question is:

```text
Can mid still be the answer?
```

If yes, keep it:

```cpp
right = mid;
```

If no, discard it:

```cpp
left = mid + 1;
```

### 12.1. Why `left < right`?

This pattern keeps the interval non-empty.

When:

```text
left == right
```

there is exactly one candidate left. By the invariant, that candidate must be
the answer, so the loop should stop.

This is why this pattern uses:

```cpp
while (left < right)
```

and not:

```cpp
while (left <= right)
```

If we used `left <= right` with `right = mid`, the loop could fail to make
progress when `left == right == mid`.

---

## 13. Boundary Search: Last True

Another useful pattern is **last true**.

This appears when the predicate has this shape:

```text
true true true false false false
          ^
       last true
```

For example, in `Sqrt(x)` we want the largest integer `i` such that:

```text
i * i <= x
```

That predicate is true for small values and false for large values:

```text
i:        1     2     3     4
i*i<=8:  true  true  false false
                  ^
              first false

answer = last true = 2
```

A common implementation uses a closed interval that is allowed to become empty:

```cpp
int lastTrue(int left, int right)
{
    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (ok(mid)) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return right;
}
```

After the loop:

```text
right = last true
left  = first false
left == right + 1
```

So the final shape is:

```text
true true true | false false false
          right left
```

### 13.1. Loop Invariant

At the beginning of each iteration:

1. All indices before `left` are known to be true:

```text
for every i < left:
    ok(i) == true
```

2. All indices after `right` are known to be false:

```text
for every i > right:
    ok(i) == false
```

3. The unknown part is the closed interval:

```text
[left, right]
```

4. The bounds satisfy:

```text
left <= right + 1
```

So the mental model is:

```text
[ true ][ unknown ][ false ]
        left   right
```

The interval `[left, right]` may eventually become empty.

---

### 13.2. Preservation

During the loop, the condition gives:

```text
left <= right
```

Therefore:

```text
left <= mid <= right
```

There are two cases.

#### Case 1: `ok(mid) == true`

Because the predicate is monotone in the shape:

```text
true true true false false false
```

if `ok(mid)` is true, then every index `i <= mid` is also true.

So we can discard everything up to and including `mid` from the unknown region:

```cpp
left = mid + 1;
```

This preserves the fact that every index before the new `left` is true.

The right false region is unchanged.

The bound `left <= right + 1` is also preserved because `mid <= right`, so:

```text
mid + 1 <= right + 1
```

#### Case 2: `ok(mid) == false`

If `ok(mid)` is false, then every index `i >= mid` is also false.

So we can discard everything from `mid` onward from the unknown region:

```cpp
right = mid - 1;
```

This preserves the fact that every index after the new `right` is false.

The left true region is unchanged.

The bound `left <= right + 1` is also preserved because `left <= mid`, and
after the update:

```text
right + 1 == mid
```

---

### 13.3. Loop Exit

The loop exits when:

```text
!(left <= right)
```

which means:

```text
left > right
```

For integers, this implies:

```text
left >= right + 1
```

But the invariant also gives:

```text
left <= right + 1
```

Therefore:

```text
left == right + 1
```

Using the semantic parts of the invariant:

* every index `< left` is true;
* every index `> right` is false.

Since:

```text
left == right + 1
```

we get:

```text
right < left
```

So `right` is in the true region, and every index greater than `right` is in
the false region.

Therefore `right` is exactly the last index for which `ok(i)` is true.

---

### 13.4. Example: LC 69 — Sqrt(x)

Problem:

```text
return floor(sqrt(x))
```

For `x >= 2`, search possible roots:

```text
[1, x / 2]
```

The predicate is:

```text
ok(mid) := mid * mid <= x
```

To avoid overflow, use the equivalent check:

```cpp
mid <= x / mid
```

Implementation:

```cpp
int mySqrt(int x)
{
    if (x < 2) {
        return x;
    }

    int left = 1;
    int right = x / 2;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (mid <= x / mid) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return right;
}
```

This returns the largest integer whose square does not exceed `x`, which is
exactly `floor(sqrt(x))`.

---

## 14. Exact Search vs Boundary Search

| Question                  | Exact Search                          | First True Boundary       | Last True Boundary            |
| ------------------------- | ------------------------------------- | ------------------------- | ----------------------------- |
| Predicate shape           | equality / comparison to target       | `false ... false true...`  | `true ... true false...`      |
| Can the answer be absent? | Yes                                   | Usually no                | Usually no                    |
| Interval type             | Closed, may become empty              | Closed, kept non-empty    | Closed, may become empty      |
| Loop condition            | `left <= right`                       | `left < right`            | `left <= right`               |
| What happens to `mid`?    | Discarded after failed equality check | Kept when it may answer   | Always discarded after classifying |
| Exit state                | `left > right`                        | `left == right`           | `left == right + 1`           |
| Typical result            | index or `-1`                         | `left` / `right`          | `right`                       |

---

## 15. LeetCode Examples

### LC 704 — Binary Search

Classic exact search.

```cpp
while (left <= right)
```

Return index if found, otherwise `-1`.

---

### LC 35 — Search Insert Position

Very similar to exact search.

If `target` is found, return its index.

If not found, return `left`.

At loop exit:

```text
left == right + 1
```

All indices before `left` are too small, and all indices from `left` onward are
large enough. Therefore `left` is the correct insertion position.

---

### LC 74 — Search a 2D Matrix

Treat the matrix as a flattened sorted array.

For a matrix with `rows` rows and `cols` columns:

```cpp
int row = mid / cols;
int col = mid % cols;
```

The binary search logic remains the same as exact search.

---

### LC 278 — First Bad Version

This is a first-true boundary search.

The predicate:

```text
isBadVersion(version)
```

has the shape:

```text
false false false true true true
```

The answer is the first version where the predicate becomes true.

Use:

```cpp
while (left < right)
```

and when `mid` is bad:

```cpp
right = mid;
```

because `mid` can still be the first bad version.

---

### LC 69 — Sqrt(x)

This is a last-true boundary search.

The predicate:

```text
mid * mid <= x
```

has the shape:

```text
true true true false false false
```

The answer is the last value where the predicate is true.

Use:

```cpp
while (left <= right)
```

and return:

```cpp
right
```

after the loop.

---

### LC 367 — Valid Perfect Square

This is exact search over a numeric value space.

We search for an integer `mid` such that:

```text
mid * mid == num
```

To avoid overflow, compute the square as `long long`.

---

### LC 153 — Find Minimum in Rotated Sorted Array

This is a boundary-style search.

The answer always exists.

Use:

```cpp
while (left < right)
```

Compare:

```cpp
nums[mid] > nums[right]
```

If true, the minimum is strictly to the right of `mid`:

```cpp
left = mid + 1;
```

Otherwise, `mid` can still be the minimum:

```cpp
right = mid;
```

---

### LC 875 — Koko Eating Bananas

This is binary search on the answer.

Search space:

```text
speed k from 1 to max(piles)
```

Predicate:

```text
canFinish(k)
```

As speed increases, finishing becomes easier, so the predicate is monotone:

```text
false false false true true true
```

Find the first speed for which `canFinish(k)` is true.

---

## 16. Recommended Source Code Comment Style

Do not put the full proof in the `.cpp` file.

Good source comment:

```cpp
// Classic closed-interval binary search.
// Full invariant and correctness proof: Docs/Algorithms/Binary_Search.md
```

Acceptable implementation comment:

```cpp
int right = static_cast<int>(nums.size()) - 1; // Empty vector gives right == -1.
```

For boundary-style searches, mention only the local trap:

```cpp
right = mid; // mid can still be the minimum.
```

or:

```cpp
return right; // Last value for which ok(value) is true.
```

Avoid long comments that explain the entire algorithm in the source file.

The code should show the implementation.
The documentation should explain the algorithm.
