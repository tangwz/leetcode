#
# @lc app=leetcode id=142 lang=python3
#
# [142] Linked List Cycle II
#
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def detectCycle(self, head: ListNode) -> ListNode:
        # visited = set()
        # while head:
        #     if head in visited:
        #         return head
        #     else:
        #         visited.add(head)
        #         head = head.next
        # return None
        slow = fast = head
        while fast and fast.next:
            fast = fast.next.next
            slow = slow.next
            if slow == fast:
                break
        else:
            return None
        
        while head is not slow:
            head = head.next
            slow = slow.next
        return head

