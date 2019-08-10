#
# @lc app=leetcode id=69 lang=python
#
# [69] Sqrt(x)
#
class Solution(object):
    def mySqrt(self, x):
        """
        :type x: int
        :rtype: int
        """
        """
        if x <= 1:
            return x
        r = x
        while r > x/r:
            r = (r + x/r) // 2
        return int(r)
        """
        left = 0
        right = 999999
        while left < right:
            mid = (left+right+1)>>1
            square = mid*mid
            if square > x:
                right = mid - 1
            else:
                left = mid
        return left   
