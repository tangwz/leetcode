#
# @lc app=leetcode id=78 lang=python
#
# [78] Subsets
#
class Solution(object):
    def subsets(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        ans = [[],]
        def backtracking(tmp, nums):
            for i in range(len(nums)):
                ans.append(tmp+[nums[i]])
                backtracking(tmp+[nums[i]], nums[i+1:])
        if nums:
            backtracking([], nums)
        return ans

