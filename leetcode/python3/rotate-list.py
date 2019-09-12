#
# @lc app=leetcode id=61 lang=python3
#
# [61] Rotate List
#
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def rotateRight(self, head: ListNode, k: int) -> ListNode:
        if k == 0: return head
        h = head
        n = 0
        while h:
            n += 1
            h = h.next
        if n <= 1 or n == k or k % n == 0:
            return head

        if k > n:
            k = k % n
        t = k
        fast = head
        while t > 0:
            t -= 1
            fast = fast.next
        slow = head
        while fast.next:
            slow = slow.next
            fast = fast.next
        tmp = slow.next
        slow.next = None
        fast.next = head
        return tmp


