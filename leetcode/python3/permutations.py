#
# @lc app=leetcode id=46 lang=python
#
# [46] Permutations
#
class Solution(object):
    def permute(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        ans = []
        def backtracking(tmp, nums):
            if not nums:
                ans.append(tmp)
                return
            for i in range(len(nums)):
                backtracking(tmp+[nums[i]], nums[:i]+nums[i+1:])
        if nums:
            backtracking([], nums)
        return ans

