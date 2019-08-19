#
# @lc app=leetcode id=32 lang=python3
#
# [32] Longest Valid Parentheses
#
class Solution:
    def longestValidParentheses(self, s: str) -> int:
        """
        if not s:
            return 0
        ans = 0
        stack = [-1]
        for i in range(len(s)):
            if s[i] == '(':
                stack.append(i)
            else:
                stack.pop()
                if stack:
                    ans = max(ans, i-stack[-1])
                else:
                    stack.append(i)
        return ans 
        """
        ans = 0
        dp = [0] * len(s)
        for i in range(1, len(s)):
            if s[i] == ')':
                if s[i-1] == '(':
                    dp[i] = dp[i-2] + 2
                else:
                    if i-dp[i-1] >= 1 and s[i-dp[i-1]-1] == '(':
                        dp[i] = dp[i-1] + dp[i-dp[i-1]-2] + 2
                ans = max(ans, dp[i])
        return ans

