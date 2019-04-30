#
# @lc app=leetcode id=189 lang=python3
#
# [189] Rotate Array
#
class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        if not k or len(nums) < 2: return
        k = k % len(nums)
        nums[:] = nums[-k:] + nums[:-k]

        """
        for i in range(k):
            nums.insert(0, nums.pop())
        """

