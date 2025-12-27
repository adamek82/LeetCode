#pragma once
#include "ListNode.h"

class MergeTwoSortedLists_21 {
public:
    ListNode<int>* mergeTwoLists_DummyNode(ListNode<int>* list1, ListNode<int>* list2);
    ListNode<int>* mergeTwoLists_NoDummy(ListNode<int>* l1, ListNode<int>* l2);
};