#
# @lc app=leetcode id=85 lang=python3
#
# [85] Maximal Rectangle
#
class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:
        stack = [-1]
        ans = 0
        for i in range(len(heights)):
            while stack[-1] != -1 and heights[stack[-1]] >= heights[i]:
                ans = max(ans, heights[stack.pop()] * (i-stack[-1]-1))
            stack.append(i)
        while stack[-1] != -1:
            ans = max(ans, heights[stack.pop()] * (len(heights)-stack[-1]-1))
        return ans
    
    def maximalRectangle(self, matrix: List[List[str]]) -> int:
        if not matrix:
            return 0
        ans = 0
        dp = [0] * len(matrix[0])
        for i in range(len(matrix)):
            for j in range(len(matrix[0])):
                dp[j] = dp[j] + 1 if matrix[i][j] == '1' else 0
            ans = max(ans, self.largestRectangleArea(dp))
        return ans
        

