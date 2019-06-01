#
# @lc app=leetcode id=21 lang=python3
#
# [21] Merge Two Sorted Lists
#
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def mergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode:
        ans = ListNode(None)
        l = ans
        while l1 or l2:
            if not l1:
                val = l2.val
                l2 = l2.next
                l.next = ListNode(val)
                l = l.next
                continue
            if not l2:
                val = l1.val
                l1 = l1.next
                l.next = ListNode(val)
                l = l.next
                continue
            if l1.val > l2.val:
                val = l2.val
                l2 = l2.next
            else:
                val = l1.val
                l1 = l1.next
            l.next = ListNode(val)
            l = l.next
        return ans.next

