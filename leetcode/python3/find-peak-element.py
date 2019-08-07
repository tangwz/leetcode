#
# @lc app=leetcode id=162 lang=python3
#
# [162] Find Peak Element
#
class Solution:
    def findPeakElement(self, nums: List[int]) -> int:
        # n = len(nums)
        # if n == 1:
        #     return 0
        # for i in range(n):
        #     if i == 0:
        #         if nums[i] > nums[i+1]:
        #             return i
        #     elif i == n - 1:
        #         if nums[i-1] < nums[i]:
        #             return i
        #     else:
        #         if nums[i] > nums[i-1] and nums[i] > nums[i+1]:
        #             return i
        l, r = 0, len(nums)-1
        while l < r:
            mid = (l + r) // 2
            if nums[mid] > nums[mid+1]:
                r = mid
            else:
                l = mid + 1
        return l


