#
# @lc app=leetcode id=77 lang=python3
#
# [77] Combinations
#
class Solution:
    def combine(self, n: int, k: int) -> List[List[int]]:
        ans = []
        def backtracking(tmp, start):
            if len(tmp) == k:
                ans.append(tmp)
                return
            else:
                for i in range(start, n+1):
                    backtracking(tmp + [i], i+1)
        backtracking([], 1)
        return ans


