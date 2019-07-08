#
# @lc app=leetcode id=326 lang=python
#
# [326] Power of Three
#
class Solution(object):
    def isPowerOfThree(self, n):
        """
        :type n: int
        :rtype: bool
        """
        # result = 1
        # while result <= n:
        #     if result == n:
        #         return True
        #     result *= 3
        # return False
        return n > 0 and 3**19 % n == 0

