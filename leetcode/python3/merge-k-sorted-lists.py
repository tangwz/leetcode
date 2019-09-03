#
# @lc app=leetcode id=23 lang=python3
#
# [23] Merge k Sorted Lists
#
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def mergeKLists(self, lists: List[ListNode]) -> ListNode:
        # # Nlog(N)
        # nums = []
        # for l in lists:
        #     while l:
        #         nums.append(l.val)
        #         l = l.next
        # head = point = ListNode(None)
        # for num in sorted(nums):
        #     point.next = ListNode(num)
        #     point = point.next
        # return head.next


        # Nlog(k)
        if not lists: return
        n = len(lists)
        step = 1
        while step < n:
            for i in range(0, n-step, step*2):
                lists[i] = self.merge2Lists(lists[i], lists[i+step])
            step *= 2
        return lists[0]
        

    def merge2Lists(self, l1, l2):
        head = point = ListNode(None)
        while l1 and l2:
            if l1.val < l2.val:
                point.next = l1
                l1 = l1.next
            else:
                point.next = l2
                l2 = l2.next
            point = point.next
        if l1:
            point.next = l1
        if l2:
            point.next = l2
        return head.next
        

