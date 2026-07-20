#include "TestsTrees.h"

#include <optional>
#include <string>
#include <vector>

#include "TestCases.h"
#include "TestUtils.h"
#include "TreeUtils.h"

#include "InvertBinaryTree_226.h"
#include "MaximumDepthOfBinaryTree_104.h"
#include "SameTree_100.h"
#include "SymmetricTree_101.h"
#include "PathSum_112.h"

#include "BalancedBinaryTree_110.h"
#include "DiameterOfBinaryTree_543.h"
#include "SubtreeOfAnotherTree_572.h"

#include "BinaryTreeLevelOrderTraversal_102.h"
#include "AverageOfLevelsInBinaryTree_637.h"

#include "KthSmallestElementInBST_230.h"
#include "MinimumAbsoluteDifferenceInBST_530.h"
#include "ValidateBinarySearchTree_98.h"
#include "LowestCommonAncestorOfBST_235.h"

#include "Trie.h"

using namespace std;
using namespace TestCases;
using namespace TestUtils;

namespace {

/* Basic tree traversal, inspection, and structural transformation */

bool invertBinaryTree_226_tests() {
    vector<InvertBinaryTreeTestCase> testCases = {
        // Example 1 from the problem statement
        {{4, 2, 7, 1, 3, 6, 9},
            {4, 7, 2, 9, 6, 3, 1}},

        // Example 2 from the problem statement
        {{2, 1, 3},
            {2, 3, 1}},

        // Example 3: empty tree
        {{},
            {}},

        // Single-node tree
        {{42},
            {42}},

        // Left-skewed tree turns into right-skewed tree
        // input:  1
        //        /
        //       2
        //      /
        //     3
        //
        // output:
        //     1
        //      \
        //       2
        //        \
        //         3
        {{1, 2, nullopt, 3},
            {1, nullopt, 2, nullopt, 3}},

        // Irregular tree with nulls in the middle
        //    Input:
        //          1
        //        /   \
        //       2     3
        //      /       \
        //     4         5
        //
        //    Output:
        //          1
        //        /   \
        //       3     2
        //      /       \
        //     5         4
        {{1, 2, 3, 4, nullopt, nullopt, 5},
            {1, 3, 2, 5, nullopt, nullopt, 4}},
    };

    InvertBinaryTree_226 solver;

    for (size_t i = 0; i < testCases.size(); ++i) {
        const auto& tc = testCases[i];

        auto root = TreeUtils::makeUniqueTree<int>(tc.tree);
        auto expected = TreeUtils::makeUniqueTree<int>(tc.expected);

        TreeNode<int>* result = solver.invertTree(root.get());

        string gotStr = TreeUtils::toLevelOrderString(result);
        string expectedStr = TreeUtils::toLevelOrderString(expected.get());

        const string label = "Invert Binary Tree 226 Test " + to_string(i + 1);
        REQUIRE_ASSERT(assertEqScalar(label, expectedStr, gotStr));
    }

    return true;
}

bool maximumDepthOfBinaryTree_104_tests() {
    vector<MaximumDepthOfBinaryTreeTestCase> testCases = {
        // two examples from the problem statement
        {{3, 9, 20, nullopt, nullopt, 15, 7}, 3},
        {{1, nullopt, 2},                     2},

        // three extra, increasingly tricky, cases
        // (a) irregular but shallow left/right mix – depth 4
        {{1, 2, 3, 4, nullopt, nullopt, 5, nullopt, 6}, 4},
        // (b) strongly left-skewed – depth 5
        {{1, 2, nullopt, 3, nullopt, 4, nullopt, 5}, 5},
        // (c) empty tree – depth 0
        {{}, 0}
    };

    MaximumDepthOfBinaryTree_104 solver;

    for (size_t i = 0; i < testCases.size(); ++i) {
        auto root = TreeUtils::makeUniqueTree<int>(testCases[i].tree);

        int dRec = solver.maxDepthRecursive(root.get());
        int dStk = solver.maxDepthDFSStack(root.get());
        int dBfs = solver.maxDepthBFSQueue(root.get());

        const string base = "Max Depth 104 Test " + to_string(i + 1);
        REQUIRE_ASSERT(assertEqScalar(base + " [recursive]", testCases[i].expected, dRec));
        REQUIRE_ASSERT(assertEqScalar(base + " [DFS stack]", testCases[i].expected, dStk));
        REQUIRE_ASSERT(assertEqScalar(base + " [BFS queue]", testCases[i].expected, dBfs));
    }

    return true;
}

bool sameTree_100_tests()
{
    vector<SameTreeTestCase> cases = {
        // Examples
        { {1, 2, 3},                  {1, 2, 3},                  true  }, // Example 1
        { {1, 2},                     {1, nullopt, 2},            false }, // Example 2
        { {1, 2, 1},                  {1, 1, 2},                  false }, // Example 3

        // A few extra sanity checks
        { {},                         {},                         true  },
        { {1, nullopt, 2, 3},         {1, nullopt, 2, 3},         true  },
        {
            // 10
            //   \
            //   20
            //  /
            // 15
            //   \
            //   25
            //  /
            // 22
            {10, nullopt, 20, 15, nullopt, nullopt, 25, 22},
            {10, nullopt, 20, 15, nullopt, nullopt, 25, 22},
            true
        },
    };

    SameTree_100 sol;

    for (size_t i = 0; i < cases.size(); ++i) {
        auto p = TreeUtils::makeUniqueTree<int>(cases[i].p);
        auto q = TreeUtils::makeUniqueTree<int>(cases[i].q);

        bool g1 = sol.isSameTreeRecursive(p.get(), q.get());
        bool g2 = sol.isSameTreeIterativeDFS(p.get(), q.get());
        bool g3 = sol.isSameTreeBFSQueue(p.get(), q.get());

        const string base = "Same Tree 100 Test " + to_string(i + 1);
        REQUIRE_ASSERT(assertEqScalar(base + " [recursive]", cases[i].expected, g1));
        REQUIRE_ASSERT(assertEqScalar(base + " [iterative DFS]", cases[i].expected, g2));
        REQUIRE_ASSERT(assertEqScalar(base + " [BFS queue]", cases[i].expected, g3));
    }

    return true;
}

bool symmetricTree_101_tests() {
    vector<SymmetricTreeTestCase> cases = {
        // Example 1
        {{1, 2, 2, 3, 4, 4, 3}, true},

        // Example 2
        {{1, 2, 2, nullopt, 3, nullopt, 3}, false},

        // Empty tree
        {{}, true},

        // Single node
        {{1}, true},

        // Symmetric but not perfect, with interior nulls
        //        1
        //      /   \
        //     2     2
        //    /       \
        //   3         3
        //  /           \
        // 4             4
        {{1, 2, 2, 3, nullopt, nullopt, 3, 4, nullopt, nullopt, 4}, true},

        // Same shape on both sides but values break symmetry
        //        1
        //      /   \
        //     2     2
        //    / \   / \
        //   3   4 3   4   (not symmetric: mirrored nodes differ)
        {{1, 2, 2, 3, 4, 3, 4}, false},
    };

    SymmetricTree_101 sol;

    for (size_t i = 0; i < cases.size(); ++i) {
        auto root = TreeUtils::makeUniqueTree<int>(cases[i].tree);

        bool g1 = sol.isSymmetricRecursive(root.get());
        bool g2 = sol.isSymmetricIterative(root.get());

        const string base = "Symmetric Tree 101 Test " + to_string(i + 1);
        REQUIRE_ASSERT(assertEqScalar(base + " [recursive]", cases[i].expected, g1));
        REQUIRE_ASSERT(assertEqScalar(base + " [iterative]", cases[i].expected, g2));
    }

    return true;
}

bool pathSum_112_tests() {
    vector<PathSumTestCase> cases = {
        // Example 1
        {{5, 4, 8, 11, nullopt, 13, 4, 7, 2, nullopt, nullopt, nullopt, 1}, 22, true},

        // Example 2
        {{1, 2, 3}, 5, false},

        // Example 3: empty tree
        {{}, 0, false},

        // Single node: matches target
        {{5}, 5, true},

        // Single node: does not match target
        {{5}, 4, false},

        // Intermediate sum equals target but only full root-to-leaf should count
        //       1
        //      /
        //     2
        //    /
        //   1
        // Path 1->2 = 3 (not a leaf), leaf path 1->2->1 = 4
        {{1, 2, nullopt, 1}, 3, false},

        // Tree with negative values, path exists:
        //         1
        //       /   \
        //     -2    -3
        //     / \   /
        //    1   3 -2
        //   /
        //  -1
        // Path: 1 + (-2) + 1 + (-1) = -1
        {{1, -2, -3, 1, 3, -2, nullopt, -1}, -1, true},
    };

    PathSum_112 sol;

    for (size_t i = 0; i < cases.size(); ++i) {
        auto root = TreeUtils::makeUniqueTree<int>(cases[i].tree);

        bool got = sol.hasPathSum(root.get(), cases[i].target);

        const string label = "Path Sum 112 Test " + to_string(i + 1);
        REQUIRE_ASSERT(assertEqScalar(label, cases[i].expected, got));
    }

    return true;
}

/* Bottom-up DFS reasoning with subtree-derived information */

bool balancedBinaryTree_110_tests() {
    vector<BalancedBinaryTreeTestCase> testCases = {
        // Example 1
        {{3, 9, 20, nullopt, nullopt, 15, 7}, true},

        // Example 2
        {{1, 2, 2, 3, 3, nullopt, nullopt, 4, 4}, false},

        // Example 3: empty tree
        {{}, true},

        // Single node
        {{1}, true},

        // Balanced but not perfect
        //      1
        //     / \
        //    2   3
        //   / \   \
        //  4   5   6
        {{1, 2, 3, 4, 5, nullopt, 6}, true},

        // Right-skewed chain (unbalanced)
        // 1
        //  \
        //   2
        //    \
        //     3
        {{1, nullopt, 2, nullopt, 3}, false},
    };

    BalancedBinaryTree_110 solver;

    for (size_t i = 0; i < testCases.size(); ++i) {
        const auto& tc = testCases[i];

        auto root = TreeUtils::makeUniqueTree<int>(tc.tree);
        bool got = solver.isBalanced(root.get());

        const string label = "Balanced Binary Tree 110 Test " + to_string(i + 1);
        REQUIRE_ASSERT(assertEqScalar(label, tc.expected, got));
    }

    return true;
}

bool diameterOfBinaryTree_543_tests() {
    vector<DiameterOfBinaryTreeTestCase> testCases = {
        // Example 1: [4,2,1,3,5] diameter = 3
        {{1, 2, 3, 4, 5}, 3},

        // Example 2: [1,2] diameter = 1
        {{1, 2}, 1},

        // Single node: diameter = 0
        {{1}, 0},

        // Left-skewed chain: 1-2-3-4, diameter = 3
        {{1, 2, nullopt, 3, nullopt, 4}, 3},

        // Balanced-ish tree
        //        1
        //      /   \
        //     2     3
        //    / \   /
        //   4   5 6
        // Longest path: 4-2-1-3-6 => 4 edges
        {{1, 2, 3, 4, 5, 6}, 4},

        // Diameter inside a subtree (not through root)
        //        1
        //       /
        //      2
        //     / \
        //    3   4
        //   /
        //  5
        // Longest path: 5-3-2-4 => 3 edges
        {{1, 2, nullopt, 3, 4, 5}, 3},
    };

    DiameterOfBinaryTree_543 solver;

    for (size_t i = 0; i < testCases.size(); ++i) {
        const auto& tc = testCases[i];

        auto root = TreeUtils::makeUniqueTree<int>(tc.tree);
        int got = solver.diameterOfBinaryTree(root.get());

        const string label = "Diameter of Binary Tree 543 Test " + to_string(i + 1);
        REQUIRE_ASSERT(assertEqScalar(label, tc.expected, got));
    }

    return true;
}

bool subtreeOfAnotherTree_572_tests() {
    vector<SubtreeOfAnotherTreeTestCase> cases = {
        // Example 1
        {{3, 4, 5, 1, 2},
            {4, 1, 2},
            true},

        // Example 2
        {{3, 4, 5, 1, 2, nullopt, nullopt, nullopt, nullopt, 0},
            {4, 1, 2},
            false},

        // Whole tree equals subRoot
        {{1, 2, 3, 4, 5},
            {1, 2, 3, 4, 5},
            true},

        // Single-node subRoot present multiple times
        {{1, 1, 2},
            {1},
            true},

        // Single-node subRoot absent
        {{1, 2, 3},
            {4},
            false},

        // The tree could also be considered as a subtree of itself.
        // root:    1
        //         / \
        //        1   1
        // sub:    1
        //        / \
        //       1   1
        {{1, 1, 1},
            {1, 1, 1},
            true},

        // Same multiset of values but different structure should NOT count
        // root:   1
        //        /
        //       1
        //      /
        //     1
        //
        // sub:    1
        //        / \
        //       1   1
        {{1, 1, nullopt, 1},
            {1, 1, 1},
            false},

        // Match deeper in the tree
        // root:      5
        //           / \
        //          3   8
        //         / \
        //        2   4
        // subRoot:   3
        //           / \
        //          2   4
        {{5, 3, 8, 2, 4},
            {3, 2, 4},
            true},
    };

    SubtreeOfAnotherTree_572 sol;

    for (size_t i = 0; i < cases.size(); ++i) {
        const auto& tc = cases[i];

        TreeNode<int>* root    = TreeUtils::vectorToTree<int>(tc.root);
        TreeNode<int>* subRoot = TreeUtils::vectorToTree<int>(tc.subRoot);

        const string label = "SubtreeOfAnotherTree_572 Test " + to_string(i + 1);
        bool got = sol.isSubtree(root, subRoot);

        REQUIRE_ASSERT(assertEqScalar(label, tc.expected, got));

        TreeUtils::freeTree(root);
        TreeUtils::freeTree(subRoot);
    }

    return true;
}

/* Breadth-first traversal by tree levels */

bool binaryTreeLevelOrderTraversal_102_tests() {
    vector<BinaryTreeLevelOrderTraversalTestCase> cases = {
        // Example 1
        {{3, 9, 20, nullopt, nullopt, 15, 7},
            {{3}, {9, 20}, {15, 7}}},

        // Example 2
        {{1},
            {{1}}},

        // Example 3: empty tree
        {{},
            {}},

        // Left-skewed tree
        //   1
        //  /
        // 2
        ///
        //3
        {{1, 2, nullopt, 3},
            {{1}, {2}, {3}}},

        // Unbalanced tree with missing children
        //        1
        //      /   \
        //     2     3
        //      \     \
        //       4     5
        {{1, 2, 3, nullopt, 4, nullopt, 5},
            {{1}, {2, 3}, {4, 5}}},

        // Tree with a deeper left subtree
        //        10
        //       /  \
        //      5    15
        //     /    /  \
        //    3    12  18
        {{10, 5, 15, 3, nullopt, 12, 18},
            {{10}, {5, 15}, {3, 12, 18}}},
    };

    BinaryTreeLevelOrderTraversal_102 sol;

    for (size_t i = 0; i < cases.size(); ++i) {
        const auto& tc = cases[i];

        auto root = TreeUtils::makeUniqueTree<int>(tc.tree);
        vector<vector<int>> got = sol.levelOrder(root.get());

        const string label = "Binary Tree Level Order 102 Test " + to_string(i + 1);
        REQUIRE_ASSERT(assertEqVVIntExact(label, tc.expected, got));
    }

    return true;
}

bool averageOfLevelsInBinaryTree_637_tests() {
    vector<AverageOfLevelsInBinaryTreeTestCase> cases = {
        // Example 1
        {{3, 9, 20, nullopt, nullopt, 15, 7},
            {3.0, 14.5, 11.0}},

        // Example 2
        {{3, 9, 20, 15, 7},
            {3.0, 14.5, 11.0}},

        // Single node
        {{1},
            {1.0}},

        // Left-skewed tree: levels [[1], [2], [3]]
        //     1
        //    /
        //   2
        //  /
        // 3
        {{1, 2, nullopt, 3},
            {1.0, 2.0, 3.0}},

        // Mixed positive/negative values
        //       1
        //      / \
        //    -2   3
        // Averages: [1], [0.5]
        {{1, -2, 3},
            {1.0, 0.5}},

        // Deeper unbalanced tree
        //        5
        //       / \
        //      3   8
        //     /   / \
        //    1   7  10
        // Averages: [5], [5.5], [6.0]
        {{5, 3, 8, 1, nullopt, 7, 10},
            {5.0, 5.5, 6.0}},
    };

    AverageOfLevelsInBinaryTree_637 sol;

    for (size_t i = 0; i < cases.size(); ++i) {
        const auto& tc = cases[i];

        auto root = TreeUtils::makeUniqueTree<int>(tc.tree);
        vector<double> got = sol.averageOfLevels(root.get());

        const string base = "Average of Levels in Binary Tree 637 Test " + to_string(i + 1);
        REQUIRE_ASSERT(assertEqScalar(base + " [size]", tc.expected.size(), got.size()));

        for (size_t j = 0; j < tc.expected.size() && j < got.size(); ++j) {
            const string label = base + " [level " + to_string(j) + "]";
            REQUIRE_ASSERT(assertApprox(label, tc.expected[j], got[j], 1e-5));
        }
    }

    return true;
}

/* BST-specific inorder and ordering properties */

bool kthSmallestElementInBST_230_tests() {
    vector<KthSmallestElementInABSTTestCase> testCases = {
        // Example 1
        {{3, 1, 4, nullopt, 2}, 1, 1},
        // Example 2
        {{5, 3, 6, 2, 4, nullopt, nullopt, 1}, 3, 3},
        // Additional Test 1: Larger balanced tree
        {{15, 10, 20, 5, 13, 17, 25, 3, 8, nullopt, 14, 16, 18}, 6, 14},
        // Additional Test 2: Single node tree
        {{42}, 1, 42},
        // Additional Test 3: Skewed tree
        {{1, nullopt, 2, nullopt, 3, nullopt, 4}, 4, 4}
    };

    KthSmallestElementInBST_230 solution;

    for (size_t i = 0; i < testCases.size(); ++i) {
        auto root = TreeUtils::makeUniqueTree<int>(testCases[i].tree);

        int got = solution.kthSmallest(root.get(), testCases[i].k);

        const string label = "Kth Smallest Element in BST 230 Test " + to_string(i + 1);
        const bool passed = assertEqScalar(label, testCases[i].expected, got);

        if (!passed) {
            cout << "  Input tree:\n";
            TreeUtils::printTree(root.get());
            cout << "  k=" << testCases[i].k << '\n';
            return false;
        }
    }

    return true;
}

bool minimumAbsoluteDifferenceInBST_530_tests() {
    vector<MinimumAbsoluteDifferenceInBSTTestCase> testCases = {
        // Examples from the problem statement
        {{4, 2, 6, 1, 3}, 1},
        {{1, 0, 48, nullopt, nullopt, 12, 49}, 1},

        // Simple two-node tree
        {{1, nullopt, 3}, 2},

        // Skewed increasing tree
        {{1, nullopt, 2, nullopt, 3, nullopt, 4}, 1},

        // In-order: [49, 52, 69, 89, 90]
        {{90, 69, nullopt, 49, 89, nullopt, 52}, 1},
    };

    MinimumAbsoluteDifferenceInBST_530 sol;

    for (size_t i = 0; i < testCases.size(); ++i) {
        const auto& tc = testCases[i];

        auto root = TreeUtils::makeUniqueTree<int>(tc.tree);
        int got = sol.getMinimumDifference(root.get());

        const string label =
            "Minimum Absolute Difference in BST 530 Test " + to_string(i + 1);
        REQUIRE_ASSERT(assertEqScalar(label, tc.expected, got));
    }

    return true;
}

bool validateBinarySearchTree_98_tests() {
    vector<ValidateBinarySearchTreeTestCase> testCases = {
        // Provided examples
        {{2, 1, 3}, true},
        {{5, 1, 4, nullopt, nullopt, 3, 6}, false},

        // Additional cases
        {{10, 5, 15, nullopt, nullopt, 6, 20}, false}, // violation in right subtree
        {{3, 1, 5, 0, 2, 4, 6}, true},
        {{1, nullopt, 2, nullopt, 3, nullopt, 4}, true}, // skewed right
    };

    ValidateBinarySearchTree_98 validator;

    for (size_t i = 0; i < testCases.size(); ++i) {
        const auto& tc = testCases[i];

        auto root = TreeUtils::makeUniqueTree<int>(tc.tree);
        bool got = validator.isValidBST(root.get());

        const string label = "Validate BST 98 Test " + to_string(i + 1);

        if (!assertEqScalar(label, tc.expected, got)) {
            cout << "  Input tree:\n";
            TreeUtils::printTree(root.get());
            return false;
        }
    }

    return true;
}

bool lowestCommonAncestor_235_tests() {
    vector<LowestCommonAncestorTestCase> testCases = {
        // Examples from the problem statement
        {{6, 2, 8, 0, 4, 7, 9, nullopt, nullopt, 3, 5}, 2, 8, 6},
        {{6, 2, 8, 0, 4, 7, 9, nullopt, nullopt, 3, 5}, 2, 4, 2},
        {{2, 1}, 2, 1, 2},

        // Larger BSTs
        {{10, 5, 15, 3, 8, 12, 20, 1, 4, 7, 9, nullopt, nullopt, 18, 25}, 4, 9, 5},
        {{30, 10, 50, 5, 20, 40, 60, nullopt, 8, 15, 25, 35, 45, nullopt, 70}, 15, 45, 30},
    };

    LowestCommonAncestorOfBST_235 solver;

    for (size_t i = 0; i < testCases.size(); ++i) {
        const auto& tc = testCases[i];

        auto root = TreeUtils::makeUniqueTree<int>(tc.tree);

        TreeNode<int>* p = TreeUtils::findNode(root.get(), tc.p);
        TreeNode<int>* q = TreeUtils::findNode(root.get(), tc.q);

        TreeNode<int>* lca = solver.lowestCommonAncestor(root.get(), p, q);
        int got = lca ? lca->val : numeric_limits<int>::min();

        const string label =
            "LCA of BST 235 Test " + to_string(i + 1) +
            " (p=" + to_string(tc.p) + ", q=" + to_string(tc.q) + ")";

        if (!assertEqScalar(label, tc.expected, got)) {
            cout << "  Input tree:\n";
            TreeUtils::printTree(root.get());
            return false;
        }
    }

    return true;
}

/* Tree-like prefix structure design */

bool implementTrie_208_tests() {
    vector<ImplementTrieTestCase> testCases = {
        // Example 1
        {
            {"Trie", "insert", "search", "search", "startsWith", "insert", "search"},
            {nullopt, "apple", "apple", "app", "app", "app", "app"},
            {nullopt, nullopt, true, false, true, nullopt, true}
        },
        // Example 2: Overlapping words
        {
            {"Trie", "insert", "insert", "search", "search", "startsWith"},
            {nullopt, "apple", "applause", "apple", "applause", "app"},
            {nullopt, nullopt, nullopt, true, true, true}
        },
        // Example 3: Single-character operations
        {
            {"Trie", "insert", "search", "startsWith", "search"},
            {nullopt, "a", "a", "a", "b"},
            {nullopt, nullopt, true, true, false}
        },
        // Example 4: No matching prefix
        {
            {"Trie", "insert", "insert", "startsWith", "startsWith", "search"},
            {nullopt, "car", "cart", "ca", "cat", "carrot"},
            {nullopt, nullopt, nullopt, true, false, false}
        },
        // Example 5: Large input set
        {
            {"Trie", "insert", "insert", "insert", "search", "search", "startsWith"},
            {nullopt, "dictionary", "dictionaries", "dictator", "dictionary", "dictionaries", "dict"},
            {nullopt, nullopt, nullopt, nullopt, true, true, true}
        }
    };

    for (size_t i = 0; i < testCases.size(); ++i) {
        const auto& tc = testCases[i];
        unique_ptr<Trie> trie;

        for (size_t j = 0; j < tc.operations.size(); ++j) {
            const auto& op = tc.operations[j];
            const auto& arg = tc.arguments[j];
            const auto& expected = tc.expected[j];

            if (op == "Trie") {
                trie = make_unique<Trie>();
                continue;
            }

            if (op == "insert") {
                trie->insert(arg.value());
                continue;
            }

            if (op == "search" || op == "startsWith") {
                bool got = (op == "search")
                    ? trie->search(arg.value())
                    : trie->startsWith(arg.value());

                const string label = makeStepLabel("Trie 208 Case", i, j, op, arg);
                const bool passed = assertEqScalar(label, expected.value(), got);

                if (!passed) {
                    cout << "  (debug) op=" << op << " arg=\"" << arg.value() << "\"\n";
                    return false;
                }
            }
        }
    }

    return true;
}

} // namespace

namespace TestsTrees {

std::vector<TestRegistry::Entry> getTests() {
    return {
        // Basic tree traversal, inspection, and structural transformation
        TEST(226,  "Invert Binary Tree",                  invertBinaryTree_226_tests),
        TEST(104,  "Maximum Depth of Binary Tree",        maximumDepthOfBinaryTree_104_tests),
        TEST(100,  "Same Tree",                           sameTree_100_tests),
        TEST(101,  "Symmetric Tree",                      symmetricTree_101_tests),
        TEST(112,  "Path Sum",                            pathSum_112_tests),

        // Bottom-up DFS reasoning with subtree-derived information
        TEST(110,  "Balanced Binary Tree",                balancedBinaryTree_110_tests),
        TEST(543,  "Diameter of Binary Tree",             diameterOfBinaryTree_543_tests),
        TEST(572,  "Subtree of Another Tree",             subtreeOfAnotherTree_572_tests),

        // Breadth-first traversal by tree levels
        TEST(102,  "Binary Tree Level Order Traversal",   binaryTreeLevelOrderTraversal_102_tests),
        TEST(637,  "Average of Levels in Binary Tree",    averageOfLevelsInBinaryTree_637_tests),

        // BST-specific inorder and ordering properties
        TEST(230,  "Kth Smallest Element in a BST",       kthSmallestElementInBST_230_tests),
        TEST(530,  "Minimum Absolute Difference in BST",  minimumAbsoluteDifferenceInBST_530_tests),
        TEST(98,   "Validate Binary Search Tree",         validateBinarySearchTree_98_tests),
        TEST(235,  "Lowest Common Ancestor",              lowestCommonAncestor_235_tests),

        // Tree-like prefix structure design
        TEST(208,  "Implement Trie",                      implementTrie_208_tests),
    };
}

} // namespace TestsTrees
