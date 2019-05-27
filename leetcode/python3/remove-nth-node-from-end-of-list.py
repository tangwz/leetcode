#
# @lc app=leetcode id=19 lang=python3
#
# [19] Remove Nth Node From End of List
#
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def removeNthFromEnd(self, head: ListNode, n: int) -> ListNode:
        if not head:
            return
        fast = slow = head
        while n:
            fast = fast.next
            n -= 1
        tmp = None    
        while fast:
            tmp = slow
            fast = fast.next
            slow = slow.next
        
        if not tmp:
            return head.next
        tmp.next = slow.next
        return head

