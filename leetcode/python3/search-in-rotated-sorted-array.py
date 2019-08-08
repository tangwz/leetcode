#
# @lc app=leetcode id=33 lang=python3
#
# [33] Search in Rotated Sorted Array
#
class Solution:
    def find_rotated_pos(self, nums):
        l, r = 0, len(nums) - 1
        if nums[l] < nums[r]:
            return 0
        while l <= r:
            mid = (l + r) >> 1
            if nums[mid] > nums[mid+1]:
                return mid + 1
            else:
                if nums[mid] < nums[l]:
                    r = mid - 1
                else:
                    l = mid + 1
        return 0

    def search(self, nums: List[int], target: int) -> int:
        def binary_search(l, r):
            while l <= r:
                mid = (l + r) >> 1
                if nums[mid] == target:
                    return mid
                elif nums[mid] > target:
                    r = mid - 1
                elif nums[mid] < target:
                    l = mid + 1
            return -1
        n = len(nums)
        
        if n == 0:
            return -1
        if n == 1:
            return 0 if nums[0] == target else -1 

        pos = self.find_rotated_pos(nums)
        if nums[pos] == target:
            return pos
        if pos == 0:
            return binary_search(0, n-1)
        if target < nums[0]:
            return binary_search(pos, n-1)
        return binary_search(0, pos)
       

