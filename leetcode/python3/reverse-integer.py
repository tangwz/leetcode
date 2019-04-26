#
# @lc app=leetcode id=7 lang=python3
#
# [7] Reverse Integer
#
class Solution:
    def reverse(self, x: int) -> int:
        limit = 2**31
        if x >= 0:
            d = int(str(x)[::-1])
            return d if d < limit else 0
        else:
            d = int(str(x)[:0:-1])
            return -d if d <= limit else 0

