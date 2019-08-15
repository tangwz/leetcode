#
# @lc app=leetcode id=25 lang=python3
#
# [25] Reverse Nodes in k-Group
#
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def reverseKGroup(self, head: ListNode, k: int) -> ListNode:
        if not head or k == 0:
            return None
        
        i, node = k, head
        while i:
            if not node:
                return head
            node = node.next
            i -= 1

        current = head.next
        prev = head
        i = 1
        while i < k:
                next_node = current.next
                current.next = prev
                prev = current
                current = next_node
                i += 1
        head.next = self.reverseKGroup(current, k)
        return prev
            

