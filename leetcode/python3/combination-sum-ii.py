#
# @lc app=leetcode id=40 lang=python
#
# [40] Combination Sum II
#
class Solution(object):
    def combinationSum2(self, candidates, target):
        """
        :type candidates: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        candidates.sort()
        ans = []
        def backtracking(start, sum, tmp):
            if sum == target:
                ans.append(tmp)
                return
            elif sum < target:
                for i in range(start, len(candidates)):
                    if i > start and candidates[i] == candidates[i-1]: continue
                    num = candidates[i]
                    backtracking(i+1, sum+num, tmp+[num])
            else:
                return
        if candidates:
            backtracking(0, 0, [])
        return ans       

