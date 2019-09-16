#
# @lc app=leetcode id=90 lang=python3
#
# [90] Subsets II
#
class Solution:
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        ans = [[],]
        def backtracking(tmp, nums):
            for i in range(len(nums)):
                if i > 0 and nums[i] == nums[i-1]:
                    continue
                ans.append(tmp+[nums[i]])
                backtracking(tmp+[nums[i]], nums[i+1:])
        if nums:
            nums.sort()
            backtracking([], nums)
        return ans


