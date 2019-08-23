#
# @lc app=leetcode id=51 lang=python3
#
# [51] N-Queens
#
class Solution:
    def solveNQueens(self, n: int) -> List[List[str]]:
        ans = []
        s = '.' * n
        def backtracking(i, tmp, col, hill, dale):
            if i == n:
                ans.append(tmp)
                return
            for j in range(n):
                if j not in col and i+j not in hill and i-j not in dale:
                    backtracking(i+1, tmp + [s[:j] + 'Q' + s[j+1:]], col | {j}, hill | {i+j}, dale | {i-j})
        backtracking(0, [], set(), set(), set())
        return ans        

