#
# @lc app=leetcode id=152 lang=python3
#
# [152] Maximum Product Subarray
#
class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        ans = max(nums)
        imin, imax = 1, 1
        for n in nums:
            if n < 0:
                imax, imin = imin, imax
            
            imax = max(imax*n, n)
            imin = min(imin*n, n)
            ans = max(ans, imax)
        return ans
                


