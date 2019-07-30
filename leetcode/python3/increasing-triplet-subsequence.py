#
# @lc app=leetcode id=334 lang=python
#
# [334] Increasing Triplet Subsequence
#
class Solution(object):
    def increasingTriplet(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        one, two = float('inf'), float('inf')
        for n in nums:
            if n <= one:
                one = n
            elif n <= two:
                two = n
            else:
                return True
        return False

