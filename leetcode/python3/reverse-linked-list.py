#
# @lc app=leetcode id=206 lang=python3
#
# [206] Reverse Linked List
#
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        if not head:
            return head
        current = head
        prev = None
        follow = current.next
        while follow:
            current.next = prev
            prev = current
            current = follow
            follow = follow.next
        current.next = prev
        return current

