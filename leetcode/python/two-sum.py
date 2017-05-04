# coding: utf-8

class Solution(object):
    """
        Mapping the result of each element to its index.

        Time complexity : O(n)
        Space complexity: O(n)
    """
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        d = {}
        for i, n in enumerate(nums):
            if n in d:
                return [d[n], i]
            else:
                d[target - n] = i