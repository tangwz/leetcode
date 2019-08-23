#
# @lc app=leetcode id=53 lang=python3
#
# [53] Maximum Subarray
#
class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        ans = max(nums)
        tmp = 0
        for n in nums:
            tmp += n
            if tmp >= 0:
                ans = max(ans, tmp)
            else:
                tmp = 0
        return ans

