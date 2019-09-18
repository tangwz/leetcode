#
# @lc app=leetcode id=45 lang=python3
#
# [45] Jump Game II
#
class Solution:
    def jump(self, nums: List[int]) -> int:
        n = len(nums)
        if n == 1: return 0
        dp = [0] * n
        for i in range(n):
            for j in range(nums[i], 0, -1):
                if i + j >= n-1: return dp[i]+1
                elif dp[i+j] == 0:
                    dp[i+j] = dp[i] + 1
                else:
                    break
        return 0

