#
# @lc app=leetcode id=50 lang=python
#
# [50] Pow(x, n)
#
class Solution(object):
    def myPow(self, x, n):
        """
        :type x: float
        :type n: int
        :rtype: float
        """
        ans = 1
        i = abs(n)
        while i:
            if i % 2 != 0:
                ans *= x
            x *= x
            i //= 2
        return ans if n > 0 else 1/ans

