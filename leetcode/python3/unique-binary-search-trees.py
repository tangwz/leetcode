#
# @lc app=leetcode id=96 lang=python3
#
# [96] Unique Binary Search Trees
#
class Solution:
    def numTrees(self, n: int) -> int:
        # dp = [0] * (n+1)
        # dp[0] = 1
        # dp[1] = 1
        # for i in range(2, n+1):
        #     for j in range(1, i+1):
        #         dp[i] += dp[j-1]*dp[i-j]
        # return dp[n]

        # Catalan number:
        # https://baike.baidu.com/item/catalan/7605685
        C = 1
        for i in range(n):
            C = C*2*(2*i+1)/(i+2)
        return int(C)

