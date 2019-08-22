#
# @lc app=leetcode id=47 lang=python3
#
# [47] Permutations II
#
class Solution:
    def permuteUnique(self, nums: List[int]) -> List[List[int]]:
        # ans = []
        # def backtracking(tmp, nums):
        #     if not nums:
        #         if tmp not in ans:
        #             ans.append(tmp)
        #         return
        #     else:
        #         for i in range(len(nums)):
        #           backtracking(tmp + [nums[i]], nums[:i] + nums[i+1:])
        # if nums:
        #     backtracking([], nums)
        # return ans
        ans = []
        def backtracking(tmp, nums):
            if not nums:
                ans.append(tmp)
                return
            else:
                for i in range(len(nums)):
                  if i > 0 and nums[i] == nums[i-1]: continue
                  backtracking(tmp + [nums[i]], nums[:i] + nums[i+1:])
        if nums:
            backtracking([], sorted(nums))
        return ans        

