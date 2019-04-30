#
# @lc app=leetcode id=136 lang=python3
#
# [136] Single Number
#
class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        """
        交换律：a ^ b ^ c <=> a ^ c ^ b
        任何数于0异或为任何数 0 ^ n => n
        相同的数异或为0: n ^ n => 0
        """
        ans = 0
        for n in nums:
            ans = ans ^ n
        return ans

