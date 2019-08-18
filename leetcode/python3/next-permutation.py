#
# @lc app=leetcode id=31 lang=python
#
# [31] Next Permutation
#
class Solution(object):
    def nextPermutation(self, nums):
        """
        :type nums: List[int]
        :rtype: None Do not return anything, modify nums in-place instead.
        """
        def reverse(nums, l, r):
            while l < r:
                nums[l], nums[r] = nums[r], nums[l]
                l += 1
                r -= 1
            return nums
        
        first = -1
        n = len(nums)
        for i in range(n-2, -1, -1):
            if nums[i] < nums[i+1]:
                first = i
                break
                
        if first == -1:
            reverse(nums, 0, n-1)
            return
        
        second = -1
        for i in range(n-1, first, -1):
            if nums[i] > nums[first]:
                second = i
                break
                
        nums[first], nums[second] = nums[second], nums[first]
        reverse(nums, first+1, n-1)

