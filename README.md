# LeetCode Solutions

## Project Overview

This repository contains my implementations of LeetCode algorithm and data structure
problems in several programming languages. The C++ part is the primary and most
extensively maintained implementation set and is organized by algorithm/data-structure
category, with category-specific test suites.

The solutions overview below uses the C++ category layout as the canonical classification
while still showing which problems are also implemented in the other languages.

## Project Structure

- `LeetCodeC/` — C solutions and tests
- `LeetCodeCpp/` — C++ solutions, shared data structures/utilities, and tests
  - `problems/` — solutions grouped by category
  - `common/` — shared nodes, utilities, and data structures
  - `tests/` — category-based test suites and test cases
- `LeetCodeJava/` — Java solutions and tests
- `LeetCodeJS/` — JavaScript solutions and tests
- `LeetCodeKotlin/` — Kotlin solutions and tests
- `LeetCodePy/` — Python solutions and tests

---

## Documentation

Algorithm notes and interview refreshers are kept separately from the source code:

- [Documentation index](Docs/README.md)
- [Arrays & Strings — full notes](Docs/Algorithms/Arrays_Strings.md)
- [Binary Search — full notes](Docs/Algorithms/Binary_Search.md)
- [Arrays & Strings — interview cheat sheet](Docs/CheatSheets/Arrays_Strings_Interview_Cheat_Sheet.md)
- [Binary Search — interview cheat sheet](Docs/CheatSheets/Binary_Search_Interview_Cheat_Sheet.md)
- [Heap — interview cheat sheet](Docs/CheatSheets/Heap_Interview_Cheat_Sheet.md)
- [Recursive Backtracking — quick guide](Docs/CheatSheets/Recursive_Backtracking_Quick_Guide.md)

The source code intentionally keeps comments short. Longer explanations, invariants,
correctness arguments, and implementation pitfalls belong in `Docs/`.

---

## Solutions Overview

✓ = implemented in that language.

Problems are grouped according to the C++ directory structure.

### Arrays & Strings

| # | Problem | C | C++ | Java | JS | Kotlin | Python |
| ---: | --- | :---: | :---: | :---: | :---: | :---: | :---: |
| 6 | Zigzag Conversion | ✗ | ✓ | ✗ | ✗ | ✗ | ✗ |
| 13 | Roman to Integer | ✗ | ✓ | ✗ | ✗ | ✗ | ✗ |
| 14 | Longest Common Prefix | ✗ | ✓ | ✗ | ✗ | ✗ | ✗ |
| 26 | Remove Duplicates from Sorted Array | ✗ | ✓ | ✗ | ✗ | ✗ | ✗ |
| 27 | Remove Element | ✗ | ✓ | ✗ | ✗ | ✗ | ✗ |
| 48 | Rotate Image | ✗ | ✓ | ✗ | ✗ | ✗ | ✗ |
| 54 | Spiral Matrix | ✗ | ✓ | ✗ | ✗ | ✗ | ✗ |
| 56 | Merge Intervals | ✗ | ✓ | ✗ | ✗ | ✗ | ✗ |
| 75 | Sort Colors | ✗ | ✓ | ✗ | ✗ | ✗ | ✗ |
| 80 | Remove Duplicates from Sorted Array II | ✗ | ✓ | ✗ | ✗ | ✗ | ✗ |
| 88 | Merge Sorted Array | ✗ | ✓ | ✗ | ✗ | ✗ | ✗ |
| 118 | Pascal's Triangle | ✗ | ✓ | ✗ | ✗ | ✗ | ✗ |
| 121 | Best Time to Buy and Sell Stock | ✗ | ✓ | ✗ | ✗ | ✓ | ✗ |
| 122 | Best Time to Buy and Sell Stock II | ✗ | ✓ | ✗ | ✗ | ✗ | ✗ |
| 228 | Summary Ranges | ✗ | ✓ | ✗ | ✗ | ✗ | ✗ |
| 238 | Product of Array Except Self | ✗ | ✓ | ✗ | ✗ | ✗ | ✗ |
| 274 | H-Index | ✗ | ✓ | ✗ | ✗ | ✗ | ✗ |
| 392 | Is Subsequence | ✗ | ✓ | ✗ | ✗ | ✗ | ✗ |
| 412 | Fizz Buzz | ✗ | ✓ | ✗ | ✗ | ✗ | ✗ |
| 724 | Find Pivot Index | ✗ | ✓ | ✗ | ✗ | ✗ | ✗ |
| 1768 | Merge Strings Alternately | ✗ | ✓ | ✗ | ✗ | ✗ | ✗ |
| 2239 | Find Closest Number to Zero | ✗ | ✓ | ✗ | ✗ | ✗ | ✗ |
| 2798 | Number of Employees Who Met the Target | ✗ | ✓ | ✗ | ✗ | ✗ | ✗ |
| 3046 | Split the Array | ✗ | ✓ | ✗ | ✗ | ✗ | ✗ |
| 3074 | Apple Redistribution into Boxes | ✗ | ✓ | ✗ | ✗ | ✗ | ✗ |

### Backtracking

| # | Problem | C | C++ | Java | JS | Kotlin | Python |
| ---: | --- | :---: | :---: | :---: | :---: | :---: | :---: |
| 17 | Letter Combinations of a Phone Number | ✗ | ✓ | ✗ | ✗ | ✓ | ✗ |
| 22 | Generate Parentheses | ✗ | ✓ | ✗ | ✗ | ✓ | ✗ |
| 37 | Sudoku Solver | ✗ | ✓ | ✗ | ✗ | ✗ | ✗ |
| 39 | Combination Sum | ✗ | ✓ | ✗ | ✗ | ✗ | ✗ |
| 46 | Permutations | ✗ | ✓ | ✗ | ✗ | ✗ | ✗ |
| 77 | Combinations | ✗ | ✓ | ✗ | ✗ | ✗ | ✗ |
| 78 | Subsets | ✗ | ✓ | ✗ | ✗ | ✓ | ✗ |
| 79 | Word Search | ✗ | ✓ | ✗ | ✗ | ✓ | ✗ |

### Binary Search

| # | Problem | C | C++ | Java | JS | Kotlin | Python |
| ---: | --- | :---: | :---: | :---: | :---: | :---: | :---: |
| 33 | Search in Rotated Sorted Array | ✗ | ✓ | ✗ | ✗ | ✗ | ✗ |
| 35 | Search Insert Position | ✗ | ✓ | ✗ | ✗ | ✗ | ✗ |
| 69 | Sqrt(x) | ✗ | ✓ | ✗ | ✗ | ✓ | ✗ |
| 74 | Search a 2D Matrix | ✗ | ✓ | ✗ | ✗ | ✗ | ✗ |
| 153 | Find Minimum in Rotated Sorted Array | ✗ | ✓ | ✗ | ✗ | ✗ | ✗ |
| 278 | First Bad Version | ✗ | ✓ | ✗ | ✗ | ✗ | ✗ |
| 367 | Valid Perfect Square | ✗ | ✓ | ✗ | ✗ | ✗ | ✗ |
| 704 | Binary Search | ✗ | ✓ | ✗ | ✗ | ✗ | ✗ |
| 875 | Koko Eating Bananas | ✗ | ✓ | ✗ | ✗ | ✗ | ✗ |

### Bit Manipulation

| # | Problem | C | C++ | Java | JS | Kotlin | Python |
| ---: | --- | :---: | :---: | :---: | :---: | :---: | :---: |
| 67 | Add Binary | ✗ | ✓ | ✗ | ✗ | ✓ | ✗ |
| 136 | Single Number | ✗ | ✓ | ✗ | ✗ | ✗ | ✗ |
| 191 | Number of 1 Bits | ✗ | ✓ | ✗ | ✗ | ✓ | ✗ |
| 268 | Missing Number | ✗ | ✓ | ✗ | ✗ | ✗ | ✗ |
| 504 | Base 7 | ✗ | ✓ | ✗ | ✗ | ✗ | ✗ |

### Design

| # | Problem | C | C++ | Java | JS | Kotlin | Python |
| ---: | --- | :---: | :---: | :---: | :---: | :---: | :---: |
| 384 | Shuffle an Array | ✗ | ✓ | ✗ | ✗ | ✗ | ✗ |
| 432 | All O`one Data Structure | ✓ | ✓ | ✗ | ✗ | ✓ | ✗ |
| 855 | Exam Room | ✗ | ✓ | ✗ | ✗ | ✗ | ✗ |

### Dynamic Programming

| # | Problem | C | C++ | Java | JS | Kotlin | Python |
| ---: | --- | :---: | :---: | :---: | :---: | :---: | :---: |
| 44 | Wildcard Matching | ✗ | ✓ | ✗ | ✗ | ✗ | ✗ |
| 45 | Jump Game II | ✗ | ✓ | ✗ | ✗ | ✓ | ✗ |
| 53 | Maximum Subarray | ✗ | ✓ | ✗ | ✗ | ✗ | ✗ |
| 55 | Jump Game | ✗ | ✓ | ✗ | ✗ | ✗ | ✗ |
| 62 | Unique Paths | ✗ | ✓ | ✗ | ✗ | ✗ | ✗ |
| 63 | Unique Paths II | ✗ | ✓ | ✗ | ✗ | ✗ | ✗ |
| 70 | Climbing Stairs | ✗ | ✓ | ✗ | ✗ | ✗ | ✗ |
| 198 | House Robber | ✗ | ✓ | ✗ | ✗ | ✗ | ✗ |
| 279 | Perfect Squares | ✗ | ✓ | ✗ | ✗ | ✗ | ✗ |
| 300 | Longest Increasing Subsequence | ✗ | ✓ | ✓ | ✗ | ✗ | ✗ |
| 322 | Coin Change | ✗ | ✓ | ✗ | ✗ | ✗ | ✗ |
| 509 | Fibonacci Number | ✗ | ✓ | ✗ | ✗ | ✗ | ✗ |
| 746 | Min Cost Climbing Stairs | ✗ | ✓ | ✗ | ✗ | ✗ | ✗ |
| 1143 | Longest Common Subsequence | ✗ | ✓ | ✗ | ✗ | ✗ | ✗ |

### Graphs

| # | Problem | C | C++ | Java | JS | Kotlin | Python |
| ---: | --- | :---: | :---: | :---: | :---: | :---: | :---: |
| 133 | Clone Graph | ✗ | ✓ | ✗ | ✗ | ✗ | ✗ |
| 200 | Number of Islands | ✗ | ✓ | ✓ | ✓ | ✗ | ✓ |
| 207 | Course Schedule | ✗ | ✓ | ✓ | ✓ | ✓ | ✓ |
| 210 | Course Schedule II | ✗ | ✓ | ✓ | ✓ | ✗ | ✓ |
| 286 | Walls and Gates | ✗ | ✓ | ✗ | ✗ | ✗ | ✗ |
| 289 | Game of Life | ✗ | ✓ | ✗ | ✗ | ✓ | ✗ |
| 329 | Longest Increasing Path in a Matrix | ✗ | ✓ | ✗ | ✗ | ✗ | ✗ |
| 417 | Pacific Atlantic Water Flow | ✗ | ✓ | ✗ | ✗ | ✗ | ✗ |
| 463 | Island Perimeter | ✗ | ✓ | ✗ | ✗ | ✓ | ✗ |
| 695 | Max Area of Island | ✗ | ✓ | ✓ | ✓ | ✗ | ✓ |
| 743 | Network Delay Time | ✗ | ✓ | ✓ | ✓ | ✗ | ✓ |
| 773 | Sliding Puzzle | ✗ | ✓ | ✗ | ✗ | ✗ | ✗ |
| 815 | Bus Routes | ✗ | ✓ | ✗ | ✗ | ✗ | ✗ |
| 994 | Rotting Oranges | ✗ | ✓ | ✗ | ✗ | ✗ | ✗ |
| 1091 | Shortest Path in Binary Matrix | ✗ | ✓ | ✗ | ✗ | ✗ | ✗ |
| 1584 | Min Cost to Connect All Points | ✗ | ✓ | ✓ | ✗ | ✗ | ✗ |
| 1971 | Find if Path Exists in Graph | ✓ | ✓ | ✓ | ✓ | ✓ | ✓ |
| 2360 | Longest Cycle in a Graph | ✗ | ✓ | ✗ | ✗ | ✗ | ✗ |
| 2608 | Shortest Cycle in a Graph | ✗ | ✓ | ✗ | ✗ | ✗ | ✗ |
| 2642 | Design Graph With Shortest Path Calculator | ✗ | ✓ | ✗ | ✗ | ✗ | ✗ |

### Hash Maps & Sets

| # | Problem | C | C++ | Java | JS | Kotlin | Python |
| ---: | --- | :---: | :---: | :---: | :---: | :---: | :---: |
| 1 | Two Sum | ✗ | ✓ | ✗ | ✗ | ✗ | ✗ |
| 36 | Valid Sudoku | ✗ | ✓ | ✗ | ✗ | ✗ | ✗ |
| 49 | Group Anagrams | ✗ | ✓ | ✗ | ✗ | ✓ | ✗ |
| 128 | Longest Consecutive Sequence | ✗ | ✓ | ✗ | ✗ | ✓ | ✗ |
| 169 | Majority Element | ✗ | ✓ | ✗ | ✗ | ✗ | ✗ |
| 217 | Contains Duplicate | ✗ | ✓ | ✗ | ✗ | ✗ | ✗ |
| 242 | Valid Anagram | ✗ | ✓ | ✗ | ✗ | ✗ | ✗ |
| 383 | Ransom Note | ✗ | ✓ | ✗ | ✗ | ✗ | ✗ |
| 451 | Sort Characters By Frequency | ✗ | ✓ | ✗ | ✗ | ✗ | ✗ |
| 692 | Top K Frequent Words | ✗ | ✓ | ✗ | ✗ | ✗ | ✗ |
| 706 | Design HashMap | ✗ | ✓ | ✗ | ✗ | ✗ | ✗ |
| 771 | Jewels and Stones | ✗ | ✓ | ✗ | ✗ | ✗ | ✗ |
| 1152 | Analyze User Website Visit Pattern | ✗ | ✓ | ✗ | ✗ | ✗ | ✗ |
| 1189 | Maximum Number of Balloons | ✗ | ✓ | ✗ | ✗ | ✗ | ✗ |
| 1207 | Unique Number of Occurrences | ✗ | ✓ | ✗ | ✗ | ✓ | ✗ |

### Heaps

| # | Problem | C | C++ | Java | JS | Kotlin | Python |
| ---: | --- | :---: | :---: | :---: | :---: | :---: | :---: |
| 23 | Merge k Sorted Lists | ✗ | ✓ | ✗ | ✗ | ✗ | ✗ |
| 215 | Kth Largest Element in an Array | ✗ | ✓ | ✗ | ✗ | ✗ | ✗ |
| 347 | Top K Frequent Elements | ✗ | ✓ | ✗ | ✗ | ✗ | ✗ |
| 973 | K Closest Points to Origin | ✗ | ✓ | ✗ | ✗ | ✗ | ✗ |
| 1046 | Last Stone Weight | ✗ | ✓ | ✗ | ✗ | ✗ | ✗ |
| 2812 | Find the Safest Path in a Grid | ✗ | ✓ | ✗ | ✗ | ✗ | ✗ |

### Linked Lists

| # | Problem | C | C++ | Java | JS | Kotlin | Python |
| ---: | --- | :---: | :---: | :---: | :---: | :---: | :---: |
| 19 | Remove Nth Node From End of List | ✗ | ✓ | ✗ | ✗ | ✗ | ✗ |
| 21 | Merge Two Sorted Lists | ✗ | ✓ | ✗ | ✗ | ✗ | ✗ |
| 83 | Remove Duplicates from Sorted List | ✗ | ✓ | ✗ | ✗ | ✗ | ✗ |
| 138 | Copy List with Random Pointer | ✗ | ✓ | ✗ | ✗ | ✗ | ✗ |
| 141 | Linked List Cycle | ✗ | ✓ | ✗ | ✗ | ✗ | ✗ |
| 146 | LRU Cache | ✗ | ✓ | ✗ | ✗ | ✗ | ✗ |
| 206 | Reverse Linked List | ✗ | ✓ | ✗ | ✗ | ✗ | ✗ |
| 876 | Middle of the Linked List | ✗ | ✓ | ✗ | ✗ | ✗ | ✗ |
| 2807 | Insert Greatest Common Divisors in Linked List | ✗ | ✓ | ✗ | ✗ | ✗ | ✗ |

### Other

| # | Problem | C | C++ | Java | JS | Kotlin | Python |
| ---: | --- | :---: | :---: | :---: | :---: | :---: | :---: |
| 65 | Valid Number | ✗ | ✓ | ✗ | ✗ | ✗ | ✗ |
| 277 | Find the Celebrity | ✗ | ✓ | ✗ | ✗ | ✗ | ✗ |

### Sliding Window

| # | Problem | C | C++ | Java | JS | Kotlin | Python |
| ---: | --- | :---: | :---: | :---: | :---: | :---: | :---: |
| 3 | Longest Substring Without Repeating Characters | ✗ | ✓ | ✗ | ✗ | ✗ | ✗ |
| 209 | Minimum Size Subarray Sum | ✗ | ✓ | ✗ | ✗ | ✓ | ✗ |
| 424 | Longest Repeating Character Replacement | ✗ | ✓ | ✗ | ✗ | ✓ | ✗ |
| 567 | Permutation in String | ✗ | ✓ | ✗ | ✗ | ✓ | ✗ |
| 643 | Maximum Average Subarray I | ✗ | ✓ | ✗ | ✗ | ✓ | ✗ |
| 1004 | Max Consecutive Ones III | ✗ | ✓ | ✗ | ✗ | ✓ | ✗ |

### Stacks

| # | Problem | C | C++ | Java | JS | Kotlin | Python |
| ---: | --- | :---: | :---: | :---: | :---: | :---: | :---: |
| 20 | Valid Parentheses | ✗ | ✓ | ✗ | ✗ | ✗ | ✗ |
| 84 | Largest Rectangle in Histogram | ✗ | ✓ | ✗ | ✗ | ✗ | ✗ |
| 85 | Maximal Rectangle | ✗ | ✓ | ✗ | ✗ | ✗ | ✗ |
| 150 | Evaluate Reverse Polish Notation | ✗ | ✓ | ✗ | ✗ | ✗ | ✗ |
| 155 | Min Stack | ✗ | ✓ | ✗ | ✗ | ✗ | ✗ |
| 682 | Baseball Game | ✗ | ✓ | ✗ | ✗ | ✗ | ✗ |
| 739 | Daily Temperatures | ✗ | ✓ | ✗ | ✗ | ✗ | ✗ |

### Trees

| # | Problem | C | C++ | Java | JS | Kotlin | Python |
| ---: | --- | :---: | :---: | :---: | :---: | :---: | :---: |
| 98 | Validate Binary Search Tree | ✗ | ✓ | ✗ | ✗ | ✓ | ✗ |
| 100 | Same Tree | ✗ | ✓ | ✗ | ✗ | ✓ | ✗ |
| 101 | Symmetric Tree | ✗ | ✓ | ✗ | ✗ | ✓ | ✗ |
| 102 | Binary Tree Level Order Traversal | ✗ | ✓ | ✗ | ✗ | ✓ | ✗ |
| 104 | Maximum Depth of Binary Tree | ✗ | ✓ | ✗ | ✗ | ✓ | ✗ |
| 110 | Balanced Binary Tree | ✗ | ✓ | ✗ | ✗ | ✓ | ✗ |
| 112 | Path Sum | ✗ | ✓ | ✗ | ✗ | ✓ | ✗ |
| 208 | Implement Trie (Prefix Tree) | ✗ | ✓ | ✗ | ✗ | ✗ | ✗ |
| 226 | Invert Binary Tree | ✗ | ✓ | ✗ | ✗ | ✓ | ✗ |
| 230 | Kth Smallest Element in a BST | ✗ | ✓ | ✗ | ✗ | ✓ | ✗ |
| 235 | Lowest Common Ancestor of a Binary Search Tree | ✗ | ✓ | ✗ | ✗ | ✓ | ✗ |
| 530 | Minimum Absolute Difference in BST | ✗ | ✓ | ✗ | ✗ | ✓ | ✗ |
| 543 | Diameter of Binary Tree | ✗ | ✓ | ✗ | ✗ | ✓ | ✗ |
| 572 | Subtree Of Another Tree | ✗ | ✓ | ✗ | ✗ | ✓ | ✗ |
| 637 | Average of Levels in Binary Tree | ✗ | ✓ | ✗ | ✗ | ✓ | ✗ |

### Two Pointers

| # | Problem | C | C++ | Java | JS | Kotlin | Python |
| ---: | --- | :---: | :---: | :---: | :---: | :---: | :---: |
| 11 | Container With Most Water | ✗ | ✓ | ✗ | ✗ | ✗ | ✗ |
| 15 | 3Sum | ✗ | ✓ | ✗ | ✗ | ✗ | ✗ |
| 16 | 3Sum Closest | ✗ | ✓ | ✗ | ✗ | ✗ | ✗ |
| 18 | 4Sum | ✗ | ✓ | ✗ | ✗ | ✗ | ✗ |
| 42 | Trapping Rain Water | ✗ | ✓ | ✗ | ✗ | ✗ | ✗ |
| 125 | Valid Palindrome | ✗ | ✓ | ✗ | ✗ | ✗ | ✗ |
| 167 | Two Sum II - Input Array Is Sorted | ✗ | ✓ | ✗ | ✗ | ✗ | ✗ |
| 344 | Reverse String | ✗ | ✓ | ✗ | ✗ | ✗ | ✗ |
| 977 | Squares of a Sorted Array | ✗ | ✓ | ✗ | ✗ | ✓ | ✗ |
| 1099 | Two Sum Less Than K | ✗ | ✓ | ✗ | ✗ | ✗ | ✗ |

### Additional C++ Exercises

The C++ `problems/` tree also contains a few implementations that are not included in
the numbered overview above because their repository filenames do not identify a
specific LeetCode problem number:

- `heaps/MinHeap` — standalone min-heap implementation
- `stacks/DecodeString_GoogleOnsite` — Google onsite-style decode-string exercise
