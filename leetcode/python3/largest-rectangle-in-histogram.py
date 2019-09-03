#
# @lc app=leetcode id=84 lang=python3
#
# [84] Largest Rectangle in Histogram
#
class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:
        # # O(N^2) TLE
        # ans = 0
        # n = len(heights)
        # for i in range(n):
        #     min_height = float('inf')
        #     for j in range(i, n):
        #         min_height = min(heights[j], min_height)
        #         ans = max(ans, min_height*(j-i+1))
        # return ans

