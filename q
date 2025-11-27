[1mdiff --git a/LeetCodeCpp/TestCases.h b/LeetCodeCpp/TestCases.h[m
[1mindex ba94dad..763eade 100644[m
[1m--- a/LeetCodeCpp/TestCases.h[m
[1m+++ b/LeetCodeCpp/TestCases.h[m
[36m@@ -870,4 +870,11 @@[m [mnamespace TestCases {[m
         int target;[m
         bool expected;[m
     };[m
[32m+[m
[32m+[m[32m    // 572. Subtree of Another Tree[m
[32m+[m[32m    struct SubtreeOfAnotherTreeTestCase {[m
[32m+[m[32m        vector<optional<int>> root;     // level-order representation of main tree[m
[32m+[m[32m        vector<optional<int>> subRoot;  // level-order representation of subtree[m
[32m+[m[32m        bool expected;[m
[32m+[m[32m    };[m
 } // namespace TestCases[m
[1mdiff --git a/LeetCodeCpp/TestsRunner.cpp b/LeetCodeCpp/TestsRunner.cpp[m
[1mindex 3cc9012..1553dd7 100644[m
[1m--- a/LeetCodeCpp/TestsRunner.cpp[m
[1m+++ b/LeetCodeCpp/TestsRunner.cpp[m
[36m@@ -147,6 +147,7 @@[m
 #include "DiameterOfBinaryTree_543.h"[m
 #include "SymmetricTree_101.h"[m
 #include "PathSum_112.h"[m
[32m+[m[32m#include "SubtreeOfAnotherTree_572.h"[m
 [m
 using namespace std;[m
 using namespace TestUtils;[m
[36m@@ -4119,6 +4120,90 @@[m [mpublic:[m
         }[m
     }[m
 [m
[32m+[m[32m    static void subtreeOfAnotherTree_572_tests() {[m
[32m+[m[32m        vector<SubtreeOfAnotherTreeTestCase> cases = {[m
[32m+[m[32m            // Example 1[m
[32m+[m[32m            {{3, 4, 5, 1, 2},[m
[32m+[m[32m             {4, 1, 2},[m
[32m+[m[32m             true},[m
[32m+[m
[32m+[m[32m            // Example 2[m
[32m+[m[32m            {{3, 4, 5, 1, 2, nullopt, nullopt, nullopt, nullopt, 0},[m
[32m+[m[32m             {4, 1, 2},[m
[32m+[m[32m             false},[m
[32m+[m
[32m+[m[32m            // Whole tree equals subRoot[m
[32m+[m[32m            {{1, 2, 3, 4, 5},[m
[32m+[m[32m             {1, 2, 3, 4, 5},[m
[32m+[m[32m             true},[m
[32m+[m
[32m+[m[32m            // Single-node subRoot present multiple times[m
[32m+[m[32m            {{1, 1, 2},[m
[32m+[m[32m             {1},[m
[32m+[m[32m             true},[m
[32m+[m
[32m+[m[32m            // Single-node subRoot absent[m
[32m+[m[32m            {{1, 2, 3},[m
[32m+[m[32m             {4},[m
[32m+[m[32m             false},[m
[32m+[m
[32m+[m[32m            // The tree could also be considered as a subtree of itself.[m
[32m+[m[32m            // root:    1[m
[32m+[m[32m            //         / \[m
[32m+[m[32m            //        1   1[m
[32m+[m[32m            // sub:    1[m
[32m+[m[32m            //        / \[m
[32m+[m[32m            //       1   1[m
[32m+[m[32m            {{1, 1, 1},[m
[32m+[m[32m             {1, 1, 1},[m
[32m+[m[32m             true},[m
[32m+[m
[32m+[m[32m            // Same multiset of values but different structure should NOT count[m
[32m+[m[32m            // root:   1[m
[32m+[m[32m            //        /[m
[32m+[m[32m            //       1[m
[32m+[m[32m            //      /[m
[32m+[m[32m            //     1[m
[32m+[m[32m            //[m
[32m+[m[32m            // sub:    1[m
[32m+[m[32m            //        / \[m
[32m+[m[32m            //       1   1[m
[32m+[m[32m            {{1, 1, nullopt, 1},[m
[32m+[m[32m             {1, 1, 1},[m
[32m+[m[32m             false},[m
[32m+[m
[32m+[m[32m            // Match deeper in the tree[m
[32m+[m[32m            // root:      5[m
[32m+[m[32m            //           / \[m
[32m+[m[32m            //          3   8[m
[32m+[m[32m            //         / \[m
[32m+[m[32m            //        2   4[m
[32m+[m[32m            // subRoot:   3[m
[32m+[m[32m            //           / \[m
[32m+[m[32m            //          2   4[m
[32m+[m[32m            {{5, 3, 8, 2, 4},[m
[32m+[m[32m             {3, 2, 4},[m
[32m+[m[32m             true},[m
[32m+[m[32m        };[m
[32m+[m
[32m+[m[32m        SubtreeOfAnotherTree_572 sol;[m
[32m+[m
[32m+[m[32m        for (size_t i = 0; i < cases.size(); ++i) {[m
[32m+[m[32m            const auto& tc = cases[i];[m
[32m+[m
[32m+[m[32m            TreeNode<int>* root    = TreeUtils::vectorToTree<int>(tc.root);[m
[32m+[m[32m            TreeNode<int>* subRoot = TreeUtils::vectorToTree<int>(tc.subRoot);[m
[32m+[m
[32m+[m[32m            const string label = "SubtreeOfAnotherTree_572 Test " + to_string(i + 1);[m
[32m+[m[32m            bool got = sol.isSubtree(root, subRoot);[m
[32m+[m
[32m+[m[32m            assertEqScalar(label, tc.expected, got);[m
[32m+[m
[32m+[m[32m            TreeUtils::freeTree(root);[m
[32m+[m[32m            TreeUtils::freeTree(subRoot);[m
[32m+[m[32m        }[m
[32m+[m[32m    }[m
[32m+[m
     inline static const TestEntry kTests[] = {[m
         TEST(207,  "Course Schedule",                                courseSchedule_207_tests),[m
         TEST(1971, "Find if Path Exists in Graph",                   findIfPathExistsInGraph_1971_tests),[m
[36m@@ -4256,6 +4341,7 @@[m [mpublic:[m
         TEST(543,  "Diameter of Binary Tree",                        diameterOfBinaryTree_543_tests),[m
         TEST(101,  "Symmetric Tree",                                 symmetricTree_101_tests),[m
         TEST(112,  "Path Sum",                                       pathSum_112_tests),[m
[32m+[m[32m        TEST(572,  "Subtree of Another Tree",                        subtreeOfAnotherTree_572_tests),[m
     };[m
 [m
     static void runAllTests() {[m
