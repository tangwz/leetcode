#
# @lc app=leetcode id=215 lang=python3
#
# [215] Kth Largest Element in an Array
#
# https://leetcode.com/problems/kth-largest-element-in-an-array/description/
#
# algorithms
# Medium (46.67%)
# Total Accepted:    353.1K
# Total Submissions: 750.7K
# Testcase Example:  '[3,2,1,5,6,4]\n2'
#
# Find the kth largest element in an unsorted array. Note that it is the kth
# largest element in the sorted order, not the kth distinct element.
# 
# Example 1:
# 
# 
# Input: [3,2,1,5,6,4] and k = 2
# Output: 5
# 
# 
# Example 2:
# 
# 
# Input: [3,2,3,1,2,4,5,5,6] and k = 4
# Output: 4
# 
# Note: 
# You may assume k is always valid, 1 ≤ k ≤ array's length.
# 
#
class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        def partition(lst, left, right):
            pivot = lst[left]
            i = left
            j = right
            while j > i:
                while lst[j] <= pivot and j > i:
                    j -= 1
                while lst[i] >= pivot and j > i:
                    i += 1
                if j > i:
                    lst[i], lst[j] = lst[j], lst[i]
            lst[left], lst[i] = lst[i], lst[left]
            return i

        left = 0
        right = len(nums) - 1
        while right >= left:
            p = partition(nums, left, right)
            if p == k-1:
                return nums[p]
            elif p > k-1:
                right = p - 1
            else:
                left = p + 1

