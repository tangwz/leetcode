#
# @lc app=leetcode id=89 lang=python3
#
# [89] Gray Code
#
class Solution:
    def grayCode(self, n: int) -> List[int]:
        ans = [0]
        for i in range(n):
            for j in range(len(ans) - 1, -1, -1):
                ans.append(ans[j] ^ (1 << i))
        return ans


