# Arrays and Strings

This set is not one algorithmic family. It is a collection of recurring ways to
scan, compact, preprocess, reorder, and transform linear or two-dimensional data.

The goal is not to memorize nineteen implementations. It is to recognize a
small number of reusable ideas and to know what state each idea maintains.

The main patterns are:

1. **Running state** — keep the best candidate, minimum, count, or partial result.
2. **Read/write compaction** — scan input and build the valid result in its prefix.
3. **Two-pointer construction** — consume one or two sequences in a controlled order.
4. **Preprocessing for repeated queries** — spend work once on fixed data.
5. **Prefix/suffix decomposition** — combine information from both sides of an index.
6. **Greedy accumulation** — take every locally useful contribution when it cannot
   hurt a global optimum.
7. **Sort and sweep** — impose an order that makes only the latest object relevant.
8. **Counting and buckets** — exploit a small alphabet or bounded answer range.
9. **Matrix boundaries and transformations** — reduce geometry to simple passes.

This document emphasizes intuition, invariants, reconstruction of the solution,
and implementation traps. Full source code belongs in the repository; only the
essential operations are shown here.

---

## 1. Set Overview

| Problem | LC # | Difficulty | Score | Main pattern |
|---|---:|:---:|:---:|---|
| Find Closest Number to Zero | 2239 | Easy | 3/10 | Single-pass selection |
| Merge Strings Alternately | 1768 | Easy | 4/10 | Two-pointer construction |
| Roman to Integer | 13 | Easy | 4.5/10 | Reverse scan with local rule |
| Is Subsequence | 392 | Easy | 4.5/10 | Two pointers / preprocessing |
| Best Time to Buy and Sell Stock | 121 | Easy | 5/10 | Prefix minimum |
| Longest Common Prefix | 14 | Easy | 5/10 | Vertical/horizontal scan |
| Summary Ranges | 228 | Easy | 5/10 | Consecutive-run compression |
| Remove Duplicates from Sorted Array | 26 | Easy | 5/10 | Read/write pointers |
| Remove Element | 27 | Easy | 5/10 | Stable compaction |
| Merge Sorted Array | 88 | Easy | 5/10 | Back-fill two pointers |
| Best Time to Buy and Sell Stock II | 122 | Medium | 5.5/10 | Greedy positive differences |
| Remove Duplicates from Sorted Array II | 80 | Medium | 6/10 | Bounded-frequency compaction |
| Sort Colors | 75 | Medium | 6.5/10 | Counting / block tails |
| Product of Array Except Self | 238 | Medium | 7/10 | Prefix and suffix products |
| H-Index | 274 | Medium | 7/10 | Buckets and reverse accumulation |
| Merge Intervals | 56 | Medium | 8/10 | Sort and sweep |
| Spiral Matrix | 54 | Medium | 8/10 | Shrinking boundaries |
| Zigzag Conversion | 6 | Medium | 8/10 | Row simulation / cycle pattern |
| Rotate Image | 48 | Medium | 9/10 | Matrix transformation / layer cycles |

---

## 2. Single-Pass Running State

A common array solution scans once while storing a compact summary of the
processed prefix:

```text
[ processed prefix ][ current ][ unprocessed suffix ]
          state
```

The central question is:

> What is the smallest amount of information about the prefix that is sufficient
> to make the correct decision for the current element?

Typical answers are: the best value so far, the minimum so far, the last matched
position, or the length of a valid output prefix.

---

## 3. Find Closest Number to Zero — LC 2239

### Intuition

Keep the best value seen so far. Replace it when the new value is closer to zero;
if the distances tie, keep the larger value, which prefers `+x` over `-x`.

Essential comparison:

```cpp
abs(x) < abs(best) || (abs(x) == abs(best) && x > best)
```

### Invariant

After processing any prefix, `best` is the correct answer for that prefix.

### Complexity

```text
Time:  O(n)
Space: O(1)
```

### Pitfall

For unrestricted `int` input, `abs(INT_MIN)` is not representable as `int`.
The direct version is safe only when the problem constraints exclude that case.

---

## 4. Best Time to Buy and Sell Stock — LC 121

### Intuition

For every possible selling day, the best buying day is simply the cheapest
previous day.

Maintain:

```text
minPrice  = lowest price seen so far
maxProfit = best price - earlier minPrice seen so far
```

Core update:

```cpp
minPrice = min(minPrice, price);
maxProfit = max(maxProfit, price - minPrice);
```

The explicit `if/else` form is equally valid and makes the buy/sell interpretation
more visible.

### Why the order is valid

`minPrice` comes from the current or an earlier day. If the current day becomes a
new minimum, selling on the same day contributes zero and does not change the
answer.

### Relation to Kadane's algorithm

If prices are replaced by consecutive differences, a transaction profit becomes
a sum of a contiguous range of differences. Then the problem is maximum subarray
sum. The prefix-minimum solution is equivalent in result, but it is not literally
Kadane's algorithm.

### Complexity

```text
Time:  O(n)
Space: O(1)
```

---

## 5. Read/Write Pointer Compaction

Use this pattern when the input must be modified in place and the valid output
should occupy its prefix.

```text
read  -> examines original elements
write -> next output position
```

Standard invariant:

```text
nums[0 .. write-1] is the correct result for the processed input prefix
```

The unread part may already be partially overwritten. That is safe when the
range-based loop or read index has already copied the current value before the
write occurs.

---

## 6. Remove Element — LC 27

Accept every value other than `val` and write accepted values consecutively.

Mental model:

```text
for each num:
    if num is kept:
        nums[write] = num
        ++write
```

The returned `write` is both the number of retained elements and the new logical
length.

```text
Time:  O(n)
Space: O(1)
```

---

## 7. Remove Duplicates from Sorted Array — LC 26

Sorted order makes duplicates adjacent. The valid prefix already ends with the
last distinct value, so a read value is accepted only when it differs from that
last written value.

Essential rule:

```cpp
if (nums[read] != nums[write - 1])
    nums[write++] = nums[read];
```

Initialize `write = 1` after handling the empty input because the first element is
always unique.

### Mental hook

> Compare with the last value in the result, not necessarily with the previous
> read position.

---

## 8. Remove Duplicates from Sorted Array II — LC 80

Now each value may appear at most twice.

The compact rule is:

```cpp
write < 2 || num != nums[write - 2]
```

Why it works:

- the first two output positions are always allowed;
- afterward, if `num == nums[write - 2]`, accepting it would make the last three
  retained values equal;
- sorted order ensures equal values form one block.

### Generalization

To allow at most `k` copies:

```cpp
write < k || num != nums[write - k]
```

This is a reusable bounded-frequency compaction pattern for sorted input.

---

## 9. Two-Pointer Construction

Two-pointer algorithms are not always about two ends of one array. They may also
track independent progress in two inputs or one read position plus one write
position.

The useful mental model is:

```text
Each pointer has one clear responsibility.
Every iteration must advance at least one pointer.
```

---

## 10. Merge Strings Alternately — LC 1768

Maintain one index per string. In each iteration, append from the first string if
available, then from the second if available.

```text
word1: a b c
       ^
word2: p q
       ^
result grows: a p b q c
```

The loop condition uses logical OR because processing continues until both inputs
are exhausted.

Pre-reserving `word1.size() + word2.size()` avoids result-buffer reallocations.

```text
Time:  O(n + m)
Space: O(n + m) for the result
```

---

## 11. Merge Sorted Array — LC 88

### Why fill from the back?

`nums1` contains its original values at the front and empty capacity at the end.
Filling from the front could overwrite an original value before it is compared.

From the back, the largest remaining value always belongs in the last free slot:

```text
nums1 real part: [1 3 7 _ _ _]
nums2:           [2 5 6]
write position:            ^
```

Compare the two current tails, place the larger at `write`, and move only the
pointer from which the value was taken.

The loop only needs to continue while `nums2` still has elements. If `nums2` is
exhausted, the remaining prefix of `nums1` is already in the correct place.

```text
Time:  O(m + n)
Space: O(1)
```

Signed indices are natural here because `-1` represents an exhausted input.

---

## 12. Is Subsequence — LC 392

There are two distinct problem shapes:

1. one query `s` against one `t`;
2. many short queries `s1, s2, ...` against the same fixed `t`.

The follow-up changes the optimal organization of the work.

### 12.1. Single query: two pointers

Scan `t` from left to right. Advance the pointer in `s` whenever the current
characters match.

```text
s = a c e
    ^
t = a b c d e
    ^
```

`t` is the stream being searched; `s` records how much has already been matched.
The loop stops as soon as either all of `s` is matched or `t` is exhausted.

```text
Time:  O(|t|)
Space: O(1)
```

### 12.2. Many queries: position index

Preprocess fixed `t` into a sorted list of positions for each letter:

```text
t = "abacaba"

a -> [0, 2, 4, 6]
b -> [1, 5]
c -> [3]
```

For each character of `s`, find the earliest stored position that is still
allowed. With `nextPosition` meaning the first usable index, use:

```cpp
lower_bound(positions.begin(), positions.end(), nextPosition)
```

After choosing position `p`, set:

```text
nextPosition = p + 1
```

The greedy choice of the earliest possible occurrence leaves the maximum space
for the remaining characters.

```text
Preprocess: O(|t|) time, O(|t|) space
Query:      O(|s| log |t|) worst case
```

The more precise query bound sums the binary-search costs in the occurrence lists,
but `O(|s| log |t|)` is the useful worst-case expression.

### 12.3. Many queries: next-position table

Build a table where:

```text
nextPos[i][c] = earliest position of character c at or after i
```

For `t = "abac"`, showing only `a`, `b`, and `c`:

```text
i    a    b    c
0    0    1    3
1    2    1    3
2    2   none  3
3   none none   3
4   none none  none
```

The extra row `i = |t|` is a sentinel meaning “past the end.”

Build from right to left:

1. copy the next row;
2. overwrite the column for `t[i]` with `i`.

Core recurrence:

```cpp
nextPos[i] = nextPos[i + 1];
nextPos[i][col(t[i])] = i;
```

A query performs one table lookup per character. After matching at `p`, continue
from `p + 1`.

```text
Preprocess: O(26 · |t|) time and space
Query:      O(|s|)
```

### Choosing between follow-up methods

| Method | Preprocessing | Query | Memory | Main advantage |
|---|---:|---:|---:|---|
| Position lists | `O(|t|)` | `O(|s| log |t|)` | `O(|t|)` | Simpler and compact |
| Next table | `O(26|t|)` | `O(|s|)` | `O(26|t|)` | Fastest queries |

The next table is only attractive because the alphabet is fixed and small.

---

## 13. Reverse Scan with a Local Rule

Sometimes scanning from the opposite direction turns a global-looking condition
into a local comparison with the immediately processed state.

---

## 14. Roman to Integer — LC 13

Roman numerals are additive except when a smaller symbol appears before a larger
one. Scanning from right to left makes that rule local:

```text
current < previous-right-value -> subtract current
otherwise                      -> add current
```

Example:

```text
M C M
right-to-left:
M = +1000
C < M, so -100
M >= C, so +1000
result = 1900
```

This avoids hard-coding pairs such as `IV`, `IX`, `XL`, or `CM`.

```text
Time:  O(n)
Space: O(1)
```

---

## 15. Prefix and Suffix Information

When the answer at index `i` depends on everything before and after `i`, try to
separate it into:

```text
answer[i] = leftContribution(i) combined with rightContribution(i)
```

One side can often be stored in the output while the other is maintained as a
running variable.

---

## 16. Product of Array Except Self — LC 238

For every index:

```text
answer[i] = product(left of i) × product(right of i)
```

First pass, left to right:

- write the product strictly to the left into `result[i]`;
- then multiply the running prefix by `nums[i]`.

Second pass, right to left:

- multiply `result[i]` by the product strictly to the right;
- then include `nums[i]` in the running suffix.

Example:

```text
nums:    [1, 2, 3, 4]
prefix:  [1, 1, 2, 6]
suffix multiplication produces:
result:  [24, 12, 8, 6]
```

Zeros require no special cases; the multiplication naturally handles one or
multiple zeros.

```text
Time:  O(n)
Space: O(1) extra, excluding the output
```

---

## 17. Greedy Local Accumulation

A greedy sum is valid when every positive local contribution can be taken
without reducing any future opportunity, and adjacent contributions can be
combined into an equivalent larger action.

---

## 18. Best Time to Buy and Sell Stock II — LC 122

Unlimited transactions are allowed, but only one stock may be held at a time.
Every positive day-to-day increase can be collected:

```text
prices:      1  3  2  5
changes:       +2 -1 +3
profit:         2     3 = 5
```

Taking `1 -> 3` and `2 -> 5` is equivalent to explicitly identifying each valley
and following peak. On a continuously rising segment:

```text
(a1 - a0) + (a2 - a1) + ... + (ak - a{k-1}) = ak - a0
```

So the local differences telescope into the same valley-to-peak profit.

Two equivalent implementations are useful:

- **Daily differences** — simpler and shorter;
- **Valley/peak scan** — makes transaction boundaries explicit.

```text
Time:  O(n)
Space: O(1)
```

---

## 19. Consecutive Runs and Compression

For sorted input, equal or consecutive values form contiguous runs. A common
pattern is:

1. mark the start of a run;
2. advance until the run ends;
3. emit one compressed representation;
4. continue from the next unprocessed position.

---

## 20. Summary Ranges — LC 228

Start a range at `nums[i]`, then advance `j` while values remain consecutive:

```cpp
nums[j] == nums[j - 1] + 1
```

At exit, the range is:

```text
start = nums[i]
end   = nums[j - 1]
```

Emit either one number or `start->end`.

The `+1` is safe under the problem's strictly increasing `int` input: if a next
larger element exists, the previous element cannot be `INT_MAX`.

```text
Time:  O(n)
Space: O(1) extra, excluding output strings
```

---

## 21. Longest Common Prefix — LC 14

Let `n` be the number of strings and `m` the length of the shortest relevant
prefix. The useful solutions all compare characters; they differ mainly in the
order of comparison.

### 21.1. Vertical scan

Compare one column across all strings before moving to the next column:

```text
flower
flow
flight
^^
```

Stop at the first missing or different character.

This is the most direct interpretation of “common prefix” and usually the easiest
solution to derive.

### 21.2. Horizontal scan

Start with the first string as the current prefix candidate. Compare it with each
following string and shrink the candidate length to their common prefix.

```text
flower vs flow   -> flow
flow   vs flight -> fl
```

The candidate can only shrink, never grow.

### 21.3. Sort and compare extremes

After lexicographic sorting, compare only the first and last strings. They are the
most lexicographically separated; any prefix shared by both is shared by every
string between them.

This is elegant but performs unnecessary sorting and usually requires a copy if
the input should not be modified.

### Complexity

| Method | Time | Extra space | Notes |
|---|---:|---:|---|
| Vertical | `O(nm)` | `O(1)` | Often exits very early |
| Horizontal | `O(nm)` | `O(1)` | Prefix bound shrinks over time |
| Sort | `O(n log n · m)` worst case | copy-dependent | Least efficient here |

### Binary-search-on-prefix warning

Binary-searching the prefix length does not automatically give `O(n log m)`.
A test of a prefix of length `mid` costs `O(n · mid)` without hashing, so the
straightforward method can reach `O(nm log m)` and is worse than a linear scan.

---

## 22. Sorting Followed by a Sweep

Sorting often converts a global overlap problem into a local one. Once objects
are ordered by their start, only the last merged object can overlap the next
object.

The usual tradeoff is:

```text
sorting cost O(n log n)
for a much simpler O(n) scan afterward
```

---

## 23. Merge Intervals — LC 56

Sort intervals by start. Maintain a result of already merged, non-overlapping
intervals.

For each interval:

- if it starts after the end of the last merged interval, append it;
- otherwise extend the last merged end.

Essential merge update:

```cpp
merged.back()[1] = max(merged.back()[1], interval[1]);
```

### Why `max` is required

An overlapping interval may be contained inside the current one:

```text
current:  [1, 10]
next:     [2, 5]
```

Assigning `5` directly would incorrectly shorten the union.

### Why only the last interval matters

After sorting by start, earlier merged intervals end no later than the current
last merged interval and are already disjoint from it. The next interval cannot
reach past the last interval to overlap an earlier one without also overlapping
the last.

### Sorting detail

Default lexicographic sorting of `vector<int>` sorts by start first and end second,
which is sufficient for two-element intervals.

```text
Time:  O(n log n)
Space: O(n) for output; input is sorted in place
```

---

## 24. Counting and Buckets

When values belong to a small fixed set, counting can replace comparisons and
sorting. When the answer is bounded by `n`, values beyond `n` can sometimes be
collapsed into one bucket.

---

## 25. Sort Colors — LC 75

### 25.1. Counting

Count zeros, ones, and twos, then overwrite the array with the corresponding
number of each value.

```text
input:  [2, 0, 2, 1, 1, 0]
counts: 0 -> 2, 1 -> 2, 2 -> 2
output: [0, 0, 1, 1, 2, 2]
```

```text
Time:  O(n)
Space: O(1)
Passes: two
```

### 25.2. Three tails

Maintain the processed prefix as three sorted blocks:

```text
[ zeros ][ ones ][ twos ]
```

When reading color `x`, extend every block from `2` down to `x`, writing from
right to left:

```text
read 2 -> write 2
read 1 -> write 2, 1
read 0 -> write 2, 1, 0
```

This is the complete reconstruction rule for the algorithm. Writing later colors
first makes room before placing the new earlier color.

Example with two colors explains the trick:

```text
processed: 0 0 1 1
read 0:
    append a 1 at the end -> 0 0 1 1 1
    extend zero block     -> 0 0 0 1 1
```

The three-color version applies the same shift to both later blocks.

```text
Time:  O(n)
Space: O(1)
Passes: one, but some positions are overwritten multiple times
```

It is not the classic swap-based Dutch National Flag implementation, although it
maintains an analogous partition into color regions.

---

## 26. H-Index — LC 274

### Definition

An H-index of `h` means:

> At least `h` papers have at least `h` citations each.

Sort citations conceptually in descending order:

```text
6, 5, 3, 1, 0
```

The third paper has at least three citations, but the fourth does not have at
least four. Therefore the H-index is `3`.

Geometrically, it is the largest `h × h` square that fits under the descending
citation bars.

### Bucket algorithm

With `n` papers, the H-index cannot exceed `n`. Therefore all citation counts
`>= n` can be placed in the same bucket `n`.

For `[3, 0, 6, 1, 5]`, `n = 5`:

```text
bucket 0: 1 paper
bucket 1: 1 paper
bucket 3: 1 paper
bucket 5: 2 papers   // citations 5 and 6
```

Scan candidate `h` from `n` downward while accumulating how many papers have at
least the current `h` citations.

```text
h=5: papers=2 -> insufficient
h=4: papers=2 -> insufficient
h=3: papers=3 -> valid, answer 3
```

The first valid value encountered while descending is the maximum valid H-index.

### Mental hook

> Count papers by citation level, then descend while accumulating papers that
> qualify for the current threshold.

```text
Time:  O(n)
Space: O(n)
```

A sorting solution is easier to derive but costs `O(n log n)`.

---

## 27. Row Simulation and Periodic Structure

When output is formed by repeatedly moving through a small set of logical rows or
states, simulation is often clearer than deriving the direct formula first.

After understanding the simulation, a periodic formula may explain or optimize it.

---

## 28. Zigzag Conversion — LC 6

### Row simulation

Move a current row index down and up:

```text
0 -> 1 -> 2 -> ... -> last -> ... -> 1 -> 0 -> ...
```

Append each character to its current row. Reverse direction at the first and last
rows, then concatenate all rows.

For `numRows = 4`:

```text
row sequence: 0 1 2 3 2 1 0 1 2 3 ...
```

This is a tiny state machine with state `(row, direction)`.

Special case:

```text
numRows == 1 -> output equals input
```

### Cycle interpretation

A complete down-and-up cycle has length:

```text
cycleLength = 2 · numRows - 2
```

The first and last rows contribute one character per cycle. Interior rows may
contribute two, one on the downward diagonal and one on the upward diagonal.

The cycle formula is useful for direct indexing, but simulation is usually easier
to explain and less error-prone.

```text
Time:  O(n)
Space: O(n)
```

---

## 29. Matrix Traversal with Shrinking Boundaries

For rectangular-layer traversal, keep four active boundaries:

```text
top, bottom, left, right
```

Process the current outer boundary and move it inward. This avoids a visited
matrix, direction arrays, and sentinel values.

---

## 30. Spiral Matrix — LC 54

Each iteration removes one outer layer in clockwise order:

1. top row, left to right;
2. right column, top to bottom;
3. bottom row, right to left, if still present;
4. left column, bottom to top, if still present.

Then continue with the smaller inner rectangle.

```text
+-------------------+
| 1 -> 2 -> 3 -> 4  |
| ^             |   |
| |   inner     v   |
| 8 <- 7 <- 6 <- 5  |
+-------------------+
```

The checks before traversing the bottom row and left column prevent duplicate
visits when the remaining rectangle has only one row or one column.

Signed boundaries are convenient because `--right` or `--bottom` may make a
boundary negative after the final layer.

```text
Time:  O(rows · cols)
Space: O(1) extra, excluding output
```

---

## 31. Matrix Rotation

A 90-degree rotation can be understood in two ways:

1. compose simple global transformations;
2. move each group of four corresponding boundary positions directly.

The first is easier to reconstruct; the second exposes the coordinate cycle.

---

## 32. Rotate Image — LC 48

### 32.1. Transpose, then reverse every row

After a clockwise rotation, each output row is an original column read from
bottom to top.

For:

```text
1 2 3
4 5 6
7 8 9
```

Transpose turns columns into rows:

```text
1 4 7
2 5 8
3 6 9
```

Reverse every row:

```text
7 4 1
8 5 2
9 6 3
```

Mental reconstruction:

```text
clockwise rotation = transpose + reverse rows
```

Only the upper triangle needs to be swapped during transposition, otherwise each
pair would be swapped twice.

### 32.2. Layer-by-layer four-way cycles

Treat the matrix as concentric square layers. For each position along the top
edge of a layer, rotate four corresponding values:

```text
left -> top -> right -> bottom -> left
```

Operationally, preserve the top value and assign in the opposite direction:

```text
top    <- left
left   <- bottom
bottom <- right
right  <- saved top
```

The offset from the beginning of the top edge determines the matching offset on
all four sides.

This method moves values directly to their rotated positions, but its index
mapping is harder to derive and maintain than transpose-and-reverse.

```text
Both methods:
Time:  O(n²)
Space: O(1)
```

---

## 33. Type and Const-Correctness Guidelines

### Use `const vector<T>&` when input is not modified

Examples include stock prices, citation counts, strings being queried, and the
matrix in a boundary-based spiral traversal.

Do not add `const` when the algorithm deliberately sorts or overwrites the input,
as in `Merge Intervals`, `Remove Element`, or `Rotate Image`.

### Prefer `size_t` for forward indexing

Use `size_t` when indices move from zero upward and are compared with `.size()`.
This avoids repeated narrowing casts.

### Signed indices are sometimes clearer

Use a signed type when `-1` naturally means exhausted or when a boundary can move
below zero, for example:

- back-filling `Merge Sorted Array`;
- rectangular spiral boundaries;
- closed-interval binary search.

Do not force `size_t` when it makes reverse traversal or sentinel logic obscure.

### Reverse traversal with `size_t`

When unsigned indexing is otherwise appropriate:

```cpp
for (size_t i = n; i-- > 0;)
```

visits `n-1, n-2, ..., 0` and also handles `n == 0` safely. Use it only when the
team is comfortable with the idiom.

### Vector value initialization

```cpp
vector<int> counts(n + 1);
```

creates `n + 1` value-initialized integers, so every element is zero. It is
equivalent here to `vector<int> counts(n + 1, 0)`.

---

## 34. Recommended Source Code Comment Style

Do not keep long algorithm lectures in `.cpp` files.

Good source comments explain only a local trap that the code cannot express:

```cpp
right = mid; // mid can still be the first valid answer.
```

For an unusual algorithm, a two-line mental hook may be justified:

```cpp
// Keep the processed prefix as blocks of 0s, 1s, and 2s.
// Reading color x extends every block from 2 down to x.
```

Full intuition, examples, invariants, and complexity analysis belong in this
Markdown document.

---

## 35. Pattern Summary

| Pattern | Recognition clue | Representative problems |
|---|---|---|
| Running best/minimum | Need best answer over all prefixes | Closest to Zero, Stock I |
| Read/write compaction | Modify array; valid answer is a prefix | Remove Element, Remove Duplicates I/II |
| Two-pointer construction | Consume ordered inputs without backtracking | Merge Strings, Merge Sorted Array |
| Fixed-target preprocessing | Many queries against the same long sequence | Is Subsequence follow-up |
| Reverse local rule | Right-to-left makes decision local | Roman to Integer |
| Prefix × suffix | Answer at `i` excludes or combines both sides | Product Except Self |
| Greedy local gains | Positive local contributions telescope | Stock II |
| Run compression | Sorted consecutive values form blocks | Summary Ranges |
| Multi-string scanning | Compare columns or shrink candidate prefix | Longest Common Prefix |
| Sort and sweep | After sorting, only latest merged item matters | Merge Intervals |
| Counting/buckets | Tiny value set or answer capped by `n` | Sort Colors, H-Index |
| State/row simulation | Output follows a repeated directional pattern | Zigzag Conversion |
| Shrinking boundaries | Process outer rectangle, then move inward | Spiral Matrix |
| Matrix transformations | Geometric operation decomposes into passes | Rotate Image |

The strongest interview preparation is to be able to reconstruct each solution
from its mental hook rather than recall its exact syntax.
