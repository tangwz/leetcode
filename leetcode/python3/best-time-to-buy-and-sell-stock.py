#
# @lc app=leetcode id=121 lang=python3
#
# [121] Best Time to Buy and Sell Stock
#
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        min_val = 2**32
        max_val = 0
        for i in range(len(prices)):
            min_val = min(min_val, prices[i])
            max_val = max(max_val, prices[i]-min_val)
        return max_val

