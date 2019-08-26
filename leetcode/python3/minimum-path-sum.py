#
# @lc app=leetcode id=64 lang=python3
#
# [64] Minimum Path Sum
#
class Solution:
    def minPathSum(self, grid: List[List[int]]) -> int:
        dp = [[float('inf') for _ in grid[0]] for _ in grid]
        dp[0][0] = grid[0][0]
        for i in range(0, len(grid)):
            for j in range(0, len(grid[0])):
                if i-1 >= 0 and j-1 >= 0:
                    dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i][j]
                elif i-1 >= 0:
                    dp[i][j] = dp[i-1][j] + grid[i][j]
                elif j-1 >= 0:
                    dp[i][j] = dp[i][j-1] + grid[i][j]
        return dp[-1][-1]       

