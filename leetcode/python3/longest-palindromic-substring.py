#
# @lc app=leetcode id=5 lang=python3
#
# [5] Longest Palindromic Substring
#

# Time Complexity: O(N^2)
# class Solution:
#     def longestPalindrome(self, s: str) -> str:
#         if not s:
#             return ''
#         if len(s) == 1:
#             return s
#         ans = ""
#         for i in range(len(s)):
#             ans = max(self.helper(s, i, i), self.helper(s, i, i+1), ans, key=lambda x: len(x))
#         return ans

#     def helper(self, s, left, right):
#         while left >= 0 and right < len(s) and s[left] == s[right]:
#             left -= 1
#             right += 1
#         return s[left+1:right]

class Solution:
    def longestPalindrome(self, s: str) -> str:
        # Manacher's Algorithm. Time Complexity: O(N)
        def manachers(s):
            T = '@#' + '#'.join(s) + '#$'
            P = [0] * len(T)
            center = right = 0
            for i in range(1, len(T) - 1):
                if i < right:
                    P[i] = min(P[2*center-i], right-i)
                while T[i+P[i]+1] == T[i-P[i]-1]:
                    P[i] += 1
                if i+P[i] > right:
                    center, right = i, i+P[i]
            return P
        
        p = manachers(s)
        max_len = 0
        center = 0
        for i, v in enumerate(p):
            if v > max_len:
                max_len = v
                center = i
        start = (center - max_len) // 2
        return s[start:start+max_len]

