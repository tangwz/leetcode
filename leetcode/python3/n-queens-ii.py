#
# @lc app=leetcode id=52 lang=python3
#
# [52] N-Queens II
#
class Solution:
    def totalNQueens(self, n: int) -> int:
        self.ans = 0
        def backtracking(i, col, hill, dale):
            if i == n: return True
            for j in range(n):
                if j not in col and i+j not in hill and i-j not in dale:
                    if backtracking(i+1, col|{j}, hill|{i+j}, dale|{i-j}):
                        self.ans += 1
            return False
        backtracking(0, set(), set(), set())
        return self.ans

