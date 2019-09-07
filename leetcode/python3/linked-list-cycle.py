#
# @lc app=leetcode id=141 lang=python3
#
# [141] Linked List Cycle
#
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def hasCycle(self, head: ListNode) -> bool:
        if not head:
            return False
        slow = head 
        fast = head.next
        while slow != fast:
            if not slow or not fast or not fast.next:
                return False
            else:
                slow = slow.next
                fast = fast.next.next
        return True

