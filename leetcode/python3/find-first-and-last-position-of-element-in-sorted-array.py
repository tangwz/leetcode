#
# @lc app=leetcode id=34 lang=python3
#
# [34] Find First and Last Position of Element in Sorted Array
#
class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        if not nums:
            return [-1, -1]
        
        l, r = 0, len(nums) - 1
        while l < r:
            mid = (l + r) >> 1
            if nums[mid] < target:
                l = mid + 1
            else:
                r = mid
        if nums[l] != target:
            return [-1, -1]
        left = l

        l, r = 0, len(nums) - 1
        while l < r:
            mid = (l + r + 1) >> 1
            if nums[mid] > target:
                r = mid - 1
            else:
                l = mid
        if nums[l] != target:
            return [-1, -1]
        right = r

        return [left, right]

