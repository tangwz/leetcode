#
# @lc app=leetcode id=461 lang=python
#
# [461] Hamming Distance
#
class Solution(object):
    def hammingDistance(self, x, y):
        """
        :type x: int
        :type y: int
        :rtype: int
        """
        return bin(x^y).count('1')

