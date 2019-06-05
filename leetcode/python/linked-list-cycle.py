#
# @lc app=leetcode id=141 lang=python
#
# [141] Linked List Cycle
#
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def hasCycle(self, head):
        """
        :type head: ListNode
        :rtype: bool
        """
        # 快慢指针，若指针相遇则判断有环
        if not head:
            return False
        low = head
        fast = head.next
        while 1:
            if not low or not fast or not fast.next:
                return False
            elif low == fast:
                return True
            else:
                low = low.next
                fast = fast.next.next
        

