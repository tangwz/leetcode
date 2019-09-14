#
# @lc app=leetcode id=83 lang=python3
#
# [83] Remove Duplicates from Sorted List
#
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def deleteDuplicates(self, head: ListNode) -> ListNode:
        ans = head
        while ans and ans.next:
            if ans.next.val == ans.val:
                ans.next = ans.next.next
            else:
                ans = ans.next
        return head

