#
# @lc app=leetcode id=39 lang=python
#
# [39] Combination Sum
#
class Solution(object):
    def combinationSum(self, candidates, target):
        """
        :type candidates: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        ans = []
        def backtracking(start, sum, lst):
            if sum == target:
                ans.append(lst)
                return
            elif sum < target:
                for i in range(start, len(candidates)):
                    backtracking(i, sum+candidates[i], lst+[candidates[i]])
            else:
                return
        if candidates:
            backtracking(0, 0, [])
        return ans



        

