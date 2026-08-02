#pragma once

#include "TreeNode.h"

#include <memory>
#include <optional>
#include <string>
#include <vector>

using namespace std;

class TreeUtils {
public:
    template <typename T>
    static TreeNode<T>* vectorToTree(const vector<optional<T>>& values);

    template <typename T>
    static string toLevelOrderString(TreeNode<T>* root);

    template <typename T>
    static void printTree(TreeNode<T>* root);

    template <typename T>
    static TreeNode<T>* findNode(TreeNode<T>* root, T value);

    template <typename T>
    static void freeTree(TreeNode<T>* root);

    template <typename T>
    struct TreeDeleter {
        void operator()(TreeNode<T>* root) const {
            TreeUtils::freeTree<T>(root);
        }
    };

    template <typename T>
    using UniqueTree = unique_ptr<TreeNode<T>, TreeDeleter<T>>;

    template <typename T>
    static UniqueTree<T> makeUniqueTree(const vector<optional<T>>& values) {
        return UniqueTree<T>(vectorToTree<T>(values));
    }

    // For in-place tree algorithms that may return a different root.
    template <typename T>
    static void resetTreeRoot(UniqueTree<T>& owner, TreeNode<T>* newRoot) {
        owner.release();
        owner.reset(newRoot);
    }

private:
    template <typename T>
    static void printNodeInternal(const vector<TreeNode<T>*>& nodes, int level, int maxLevel);

    static void printWhitespaces(int count);

    template <typename T>
    static int maxLevel(TreeNode<T>* node);

    template <typename T>
    static bool isAllElementsNull(const vector<TreeNode<T>*>& nodes);
};
