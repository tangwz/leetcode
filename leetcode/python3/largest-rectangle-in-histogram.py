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
        stack = [-1]
        ans = 0
        for i in range(len(heights)):
            while stack[-1] != -1 and heights[stack[-1]] >= heights[i]:
                ans = max(ans, heights[stack.pop()] * (i-stack[-1]-1))
            stack.append(i)
        while stack[-1] != -1:
            ans = max(ans, heights[stack.pop()] * (len(heights)-stack[-1]-1))
        return ans

