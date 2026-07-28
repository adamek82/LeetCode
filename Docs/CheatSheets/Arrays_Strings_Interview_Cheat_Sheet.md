# Arrays and Strings — Interview Cheat Sheet (LeetCode Set)

A compact refresher with C++-style patterns, mental hooks, complexity, and
common gotchas.

For the full explanations and examples, see:

- `Docs/Algorithms/Arrays_Strings.md`

---

## Set Overview

| Problem | LC # | Difficulty | Score | Status |
|---|---:|:---:|:---:|:---:|
| Find Closest Number to Zero | 2239 | Easy | 3/10 | ✔ |
| Merge Strings Alternately | 1768 | Easy | 4/10 | ✔ |
| Roman to Integer | 13 | Easy | 4.5/10 | ✔ |
| Is Subsequence | 392 | Easy | 4.5/10 | ✔ |
| Best Time to Buy and Sell Stock | 121 | Easy | 5/10 | ✔ |
| Longest Common Prefix | 14 | Easy | 5/10 | ✔ |
| Summary Ranges | 228 | Easy | 5/10 | ✔ |
| Remove Duplicates from Sorted Array | 26 | Easy | 5/10 | ✔ |
| Remove Element | 27 | Easy | 5/10 | ✔ |
| Merge Sorted Array | 88 | Easy | 5/10 | ✔ |
| Best Time to Buy and Sell Stock II | 122 | Medium | 5.5/10 | ✔ |
| Remove Duplicates from Sorted Array II | 80 | Medium | 6/10 | ✔ |
| Sort Colors | 75 | Medium | 6.5/10 | ✔ |
| Product of Array Except Self | 238 | Medium | 7/10 | ✔ |
| H-Index | 274 | Medium | 7/10 | ✔ |
| Merge Intervals | 56 | Medium | 8/10 | ✔ |
| Spiral Matrix | 54 | Medium | 8/10 | ✔ |
| Zigzag Conversion | 6 | Medium | 8/10 | ✔ |
| Rotate Image | 48 | Medium | 9/10 | ✔ |

---

## Quick Pattern Map

| Signal in the problem | Pattern to try |
|---|---|
| Need best answer while scanning | Running state / prefix minimum |
| Modify array and return logical length | Read/write pointers |
| Two ordered inputs, output buffer at end | Back-fill two pointers |
| Fixed long `t`, many short subsequence queries | Preprocess positions/table |
| Output depends on left and right sides | Prefix + suffix passes |
| Sorted values form adjacent groups | Run compression / compaction |
| Small value range | Counting / buckets |
| Overlapping intervals | Sort, then sweep |
| Matrix perimeter/layers | Shrinking boundaries / four-cycles |
| Columns must become rows | Transpose |

---

## Core Templates

### 1. Stable read/write compaction

```cpp
size_t write = 0;

for (int value : nums) {
    if (keep(value))
        nums[write++] = value;
}

return static_cast<int>(write);
```

**Invariant:** `nums[0..write-1]` is the correct output for the processed input.

Used by:

- Remove Element;
- Remove Duplicates I/II.

---

### 2. Prefix minimum / best answer

```cpp
int minimum = numeric_limits<int>::max();
int best = 0;

for (int value : values) {
    minimum = min(minimum, value);
    best = max(best, value - minimum);
}
```

Used by Stock I.

---

### 3. Back-fill merge

```cpp
int i = m - 1;
int j = n - 1;
int write = m + n - 1;

while (j >= 0) {
    if (i >= 0 && a[i] > b[j])
        a[write--] = a[i--];
    else
        a[write--] = b[j--];
}
```

**Mental hook:** largest remaining value belongs in the last free slot.

---

### 4. Prefix/suffix output

```cpp
vector<int> result(nums.size(), 1);

int prefix = 1;
for (size_t i = 0; i < nums.size(); ++i) {
    result[i] = prefix;
    prefix *= nums[i];
}

int suffix = 1;
for (size_t i = nums.size(); i-- > 0;) {
    result[i] *= suffix;
    suffix *= nums[i];
}
```

Used by Product of Array Except Self.

---

### 5. Sort and sweep

```cpp
sort(items.begin(), items.end());

for (const auto& item : items) {
    if (result.empty() || startsAfter(item, result.back()))
        result.push_back(item);
    else
        mergeInto(result.back(), item);
}
```

Used by Merge Intervals.

---

## Problem-by-Problem Refresher

### 2239. Find Closest Number to Zero

**Hook:** keep the closest value; on equal distance, keep the larger one.

```cpp
int best = nums[0];

for (int x : nums) {
    if (abs(x) < abs(best) || (abs(x) == abs(best) && x > best))
        best = x;
}
```

```text
Time O(n), space O(1)
```

---

### 1768. Merge Strings Alternately

**Hook:** one pointer per string; append from word1, then word2, when available.

```cpp
result.reserve(word1.size() + word2.size());

while (i < word1.size() || j < word2.size()) {
    if (i < word1.size()) result.push_back(word1[i++]);
    if (j < word2.size()) result.push_back(word2[j++]);
}
```

```text
Time O(n+m), output space O(n+m)
```

---

### 13. Roman to Integer

**Hook:** scan right to left; smaller than the value on the right means subtract.

```cpp
int result = 0;
int previous = 0;

for (auto it = s.rbegin(); it != s.rend(); ++it) {
    const int current = value(*it);
    result += current < previous ? -current : current;
    previous = current;
}
```

```text
Time O(n), space O(1)
```

---

### 392. Is Subsequence

#### Single query

**Hook:** scan `t`; advance in `s` only on a match.

```cpp
size_t i = 0;

for (char c : t) {
    if (i < s.size() && s[i] == c)
        ++i;
}

return i == s.size();
```

```text
Time O(|t|), space O(1)
```

#### Many queries: position lists

```text
character -> sorted positions in t
query -> lower_bound(next allowed position)
```

```text
Preprocess O(|t|), query O(|s| log |t|), space O(|t|)
```

#### Many queries: next table

```text
nextPos[i][c] = first c at or after i
```

```text
Preprocess O(26|t|), query O(|s|), space O(26|t|)
```

Choose position lists unless the fastest possible repeated queries justify the
larger table.

---

### 121. Best Time to Buy and Sell Stock

**Hook:** for every sale, pair it with the cheapest earlier purchase.

```cpp
int minPrice = numeric_limits<int>::max();
int maxProfit = 0;

for (int price : prices) {
    if (price < minPrice)
        minPrice = price;
    else
        maxProfit = max(maxProfit, price - minPrice);
}
```

```text
Time O(n), space O(1)
```

Not literally Kadane; equivalent to Kadane only after converting prices to daily
differences.

---

### 14. Longest Common Prefix

#### Vertical

**Hook:** check all strings at column `j`; stop at first mismatch.

```text
Most obvious, O(nm), O(1)
```

#### Horizontal

**Hook:** current prefix starts as the first string and can only shrink.

```text
O(nm), O(1)
```

#### Sort

**Hook:** sort, then compare only the first and last strings.

```text
O(n log n * m), extra copy; least efficient of the three
```

Plain binary search on prefix length is not `O(n log m)` unless prefix equality
can be checked in constant time, for example with hashes.

---

### 228. Summary Ranges

**Hook:** start a run at `i`; advance `j` while `nums[j] == nums[j-1] + 1`.

```cpp
while (i < nums.size()) {
    const int start = nums[i];
    size_t j = i + 1;

    while (j < nums.size() && nums[j] == nums[j - 1] + 1)
        ++j;

    const int end = nums[j - 1];
    // emit start or start->end
    i = j;
}
```

```text
Time O(n)
```

---

### 26. Remove Duplicates from Sorted Array

**Hook:** accept a value when it differs from the last output value.

```cpp
size_t write = 1;

for (size_t read = 1; read < nums.size(); ++read) {
    if (nums[read] != nums[write - 1])
        nums[write++] = nums[read];
}
```

Handle empty input before initializing `write = 1`.

---

### 27. Remove Element

**Hook:** copy every value that should remain.

```cpp
size_t write = 0;
for (int num : nums)
    if (num != val)
        nums[write++] = num;
```

---

### 88. Merge Sorted Array

**Hook:** fill from the back to avoid overwriting unread `nums1` values.

```text
Time O(m+n), space O(1)
```

Only continue while `nums2` has elements; leftover `nums1` elements are already
in place.

---

### 122. Best Time to Buy and Sell Stock II

**Hook:** collect every positive daily increase.

```cpp
for (size_t i = 1; i < prices.size(); ++i) {
    if (prices[i] > prices[i - 1])
        profit += prices[i] - prices[i - 1];
}
```

Equivalent to explicit valley-to-peak transactions.

```text
Time O(n), space O(1)
```

---

### 80. Remove Duplicates from Sorted Array II

**Hook:** allow at most two copies by comparing with the output two places back.

```cpp
size_t write = 0;

for (int num : nums) {
    if (write < 2 || num != nums[write - 2])
        nums[write++] = num;
}
```

General form for at most `k` copies:

```cpp
write < k || num != nums[write - k]
```

---

### 75. Sort Colors

#### Counting

```text
count 0/1/2 -> overwrite in order
Time O(n), space O(1), two passes
```

#### Three tails

Maintain sorted processed blocks:

```text
[0s][1s][2s]
```

When reading `x`, extend all blocks from `2` down to `x`:

```text
2 -> 2
1 -> 2,1
0 -> 2,1,0
```

One pass, `O(n)`, `O(1)`, but less standard than counting or classic DNF.

---

### 238. Product of Array Except Self

**Hook:** result first stores product on the left; reverse pass multiplies product
on the right.

```text
Time O(n), O(1) extra excluding output
```

No division; zeros work naturally.

---

### 274. H-Index

**Definition:** largest `h` such that at least `h` papers have at least `h`
citations.

**Hook:** bucket citation counts up to `n`, then walk `h` downward while counting
papers with at least `h` citations.

```cpp
vector<int> counts(n + 1);
for (int citation : citations)
    ++counts[min(citation, n)];

int h = n;
int papers = counts[n];
while (papers < h) {
    --h;
    papers += counts[h];
}
```

```text
Time O(n), space O(n)
```

`vector<int> counts(n + 1)` zero-initializes all buckets.

---

### 56. Merge Intervals

**Hook:** after sorting, only the last merged interval can overlap the current
one.

```cpp
sort(intervals.begin(), intervals.end());

for (const auto& interval : intervals) {
    if (merged.empty() || interval[0] > merged.back()[1])
        merged.push_back(interval);
    else
        merged.back()[1] = max(merged.back()[1], interval[1]);
}
```

Use `max`; the current interval may be contained in the existing one.

```text
Time O(n log n)
```

---

### 54. Spiral Matrix

**Hook:** peel one rectangle layer: top, right, bottom, left.

```text
[top..bottom] x [left..right]
```

After top/right, guard bottom and left traversals to avoid duplicates for a
single remaining row or column.

Signed boundaries are convenient because `right` or `bottom` may become `-1`.

```text
Time O(mn), space O(1) excluding output
```

---

### 6. Zigzag Conversion

#### Preferred: row simulation

**Hook:** move a row pointer down and up; at the top set direction to `+1`, at the
bottom set it to `-1`.

```text
0, 1, 2, ..., last, ..., 2, 1, 0, ...
```

Store characters in row buffers, then concatenate them.

```text
Time O(n), space O(n)
```

#### Alternative: direct cycle indexing

```text
cycleLength = 2 * (numRows - 1)
vertical    = cycleStart + row
diagonal    = cycleStart + cycleLength - row
```

Only interior rows contribute the diagonal character. This is easier to reason
about than alternating jump sizes.

```text
Time O(n), space O(1) excluding output
```

**Default choice:** row simulation for clarity; direct indexing for constant
auxiliary space.

---

### 48. Rotate Image

#### Preferred: transpose + reverse rows

```text
clockwise rotation = transpose + horizontal mirror
```

```cpp
for (size_t row = 0; row < n; ++row)
    for (size_t col = row + 1; col < n; ++col)
        swap(matrix[row][col], matrix[col][row]);

for (auto& row : matrix)
    reverse(row.begin(), row.end());
```

#### Alternative: layer four-cycles

For every top position, rotate:

```text
left -> top -> right -> bottom -> left
```

Both:

```text
Time O(n^2), space O(1)
```

Transpose-and-reverse is easier to derive and less error-prone.

---

## Complexity Summary

| Problem / method | Time | Extra space |
|---|---:|---:|
| Closest to Zero | `O(n)` | `O(1)` |
| Merge Strings | `O(n+m)` | output |
| Roman to Integer | `O(n)` | `O(1)` |
| Is Subsequence, two pointers | `O(|t|)` | `O(1)` |
| Is Subsequence, position lists | `O(|s| log |t|)` query | `O(|t|)` |
| Is Subsequence, next table | `O(|s|)` query | `O(26|t|)` |
| Stock I / II | `O(n)` | `O(1)` |
| Longest Common Prefix scan | `O(nm)` | `O(1)` |
| Summary Ranges | `O(n)` | output |
| Remove Element / Duplicates | `O(n)` | `O(1)` |
| Merge Sorted Array | `O(m+n)` | `O(1)` |
| Sort Colors | `O(n)` | `O(1)` |
| Product Except Self | `O(n)` | `O(1)` excluding output |
| H-Index buckets | `O(n)` | `O(n)` |
| Merge Intervals | `O(n log n)` | output |
| Spiral Matrix | `O(mn)` | `O(1)` excluding output |
| Zigzag row simulation | `O(n)` | `O(n)` |
| Zigzag direct indexing | `O(n)` | `O(1)` excluding output |
| Rotate Image | `O(n^2)` | `O(1)` |

---

## C++ Gotchas

- Use `const vector<T>&` when the function does not modify input.
- Keep non-const references when sorting or modifying in place.
- Prefer `size_t` for ordinary forward indices.
- Use signed indices when `-1` is a natural exhausted state or boundaries may
  move below zero.
- Cast once at an API boundary rather than repeatedly casting `size()` inside
  loops.
- `vector<int> values(count)` value-initializes all elements to `0`.
- `reserve()` changes capacity, not size.
- Default sorting of `vector<int>` is lexicographic, useful for intervals.
- Reverse `size_t` loop pattern:

```cpp
for (size_t i = n; i-- > 0;) {
    // i = n-1, ..., 0
}
```

- Do not use a sentinel value for visited cells if that value may legitimately
  appear in the input; prefer boundaries or a separate visited structure.

---

## Mini Drills

**Q1. Why does `Remove Duplicates II` compare with `nums[write - 2]`?**

Because equality means the new value would become the third copy in the sorted
output.

---

**Q2. Why fill `Merge Sorted Array` from the back?**

Because the unused buffer is at the back and writing there cannot destroy unread
values from `nums1`.

---

**Q3. Why does Stock II sum every positive difference?**

The sum of daily rises across an increasing segment equals the single
valley-to-peak profit.

---

**Q4. Why does Merge Intervals need `max(oldEnd, newEnd)`?**

The new interval may be completely contained in the old one; assigning its end
directly could shrink the union.

---

**Q5. Why is the H-index at most `n`?**

There are only `n` papers, so it is impossible to have more than `n` papers each
meeting any threshold.

---

**Q6. Why does transpose + reverse rows rotate clockwise?**

Transpose turns original columns into rows; reversing each row makes each column
appear bottom-to-top, exactly as required by a clockwise rotation.

---

**Q7. Why are guards needed in Spiral Matrix after top and right traversal?**

The remaining rectangle may have collapsed to zero rows or zero columns; without
the guards, the same row or column could be emitted twice.

---

**Q8. Which Is Subsequence follow-up structure should be the default?**

Position lists plus binary search: simpler and much more memory-efficient. Use
the next-position table when query speed dominates and the alphabet is small.
