#
# @lc app=leetcode id=58 lang=python3
#
# [58] Length of Last Word
#
class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        s = s.strip()
        word = s.split(' ')[-1]
        return len(word)

