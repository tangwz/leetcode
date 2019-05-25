#
# @lc app=leetcode id=123 lang=python3
#
# [123] Best Time to Buy and Sell Stock III
#
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        j = len(prices) - 1
        dp = [[[0 for i in range(3)] for j in range(2)] for k in range(len(prices) + 1)]
        for i in range(j, -1, -1):
            for j in range(1, -1, -1):
                for k in range(2, -1, -1):
                    if k == 2 and j == 0:
                        continue;
                    if j > 0:
                        dp[i][j][k] = max(prices[i]+dp[i+1][0][k], dp[i+1][1][k])
                    else:
                        dp[i][j][k] = max(-prices[i]+dp[i+1][1][k+1], dp[i+1][0][k])
        return dp[0][0][0]

