#
# @lc app=leetcode id=242 lang=python3
#
# [242] Valid Anagram
#
class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        x = [0] * 26
        y = [0] * 26
        for i in s:
            x[ord(i)-ord('a')] += 1
        for i in t:
            y[ord(i)-ord('a')] += 1
        for i in range(26):
            if x[i] != y[i]:
                return False
        return True

