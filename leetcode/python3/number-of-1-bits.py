#
# @lc app=leetcode id=191 lang=python
#
# [191] Number of 1 Bits
#
class Solution(object):
    def hammingWeight(self, n):
        """
        :type n: int
        :rtype: int
        """
        return bin(n).count("1")

