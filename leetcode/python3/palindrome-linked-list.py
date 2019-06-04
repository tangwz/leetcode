#
# @lc app=leetcode id=234 lang=python3
#
# [234] Palindrome Linked List
#
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def isPalindrome(self, head: ListNode) -> bool:
        slow = head
        fast = head
        while fast:
            slow = slow.next
            # fast 走两步，slow 走一步，找到中点
            if fast.next:
                fast = fast.next.next
            else:
                fast = fast.next
        
        # 反转后半部分
        prev = None
        while slow:
            n = slow.next
            slow.next =prev
            prev = slow
            slow = n
            
        while head and prev:
            if head.val != prev.val:
                return False
            head = head.next
            prev = prev.next
            
        return True        

