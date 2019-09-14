#
# @lc app=leetcode id=59 lang=python3
#
# [59] Spiral Matrix II
#
class Solution:
    def generateMatrix(self, n: int) -> List[List[int]]:
        if n < 1:
            return [[]]
        r1, c1, r2, c2 = 0, 0, n-1, n-1
        ans = [[0 for _ in range(n)] for _ in range(n)]
        count = 1
        while r1 <= r2 and c1 <= c2:
            for i in range(c1, c2+1):
                ans[r1][i] = count
                count += 1
            for i in range(r1+1, r2+1):
                ans[i][c2] = count
                count += 1
            if c1 < c2 and r1 < r2:
                for i in range(c2-1, c1, -1):
                    ans[r2][i] = count
                    count += 1
                for i in range(r2, r1, -1):
                    ans[i][c1] = count
                    count += 1
            r1 += 1
            c1 += 1
            r2 -= 1
            c2 -= 1
        return ans

