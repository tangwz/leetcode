#
# @lc app=leetcode id=10 lang=python3
#
# [10] Regular Expression Matching
#
class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        if not p:
            return not s

        is_match = s and p[0] in [s[0], '.']

        if len(p) >= 2 and p[1] == '*':
            return self.isMatch(s, p[2:]) or is_match and self.isMatch(s[1:], p)
        else:
            return is_match and self.isMatch(s[1:], p[1:])

        
        

