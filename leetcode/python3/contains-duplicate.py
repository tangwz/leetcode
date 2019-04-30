#
# @lc app=leetcode id=217 lang=python3
#
# [217] Contains Duplicate
#
class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        return len(set(nums)) != len(nums)

        """
        s = set()
        for i in nums:
            if i in s:
                return True
            else:
                s.add(i)
        return False
        """

