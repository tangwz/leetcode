#
# @lc app=leetcode id=6 lang=python3
#
# [6] ZigZag Conversion
#
class Solution:
    def convert(self, s: str, numRows: int) -> str:
        # ans = ''
        # if numRows == 1:
        #     return s
            

        # for i in range(numRows):
        #     if i == 0:
        #         n = 0
        #         p = 2*n*numRows - 2*n
        #         while p < len(s):
        #             ans += s[p]
        #             n += 1
        #             p = 2*n*numRows - 2*n
        #     elif i == numRows - 1:
        #         n = 0
        #         p = 2*n*numRows - 2*n + i
        #         while p < len(s):
        #             ans += s[p]
        #             n += 1
        #             p = 2*n*numRows - 2*n + i
        #     else:
        #         n = 0
        #         p = 2*n*numRows - 2*n + i
        #         while p < len(s):
        #             ans += s[p]
        #             n += 1
        #             p = 2*n*numRows - 2*n - i
        #             if p < len(s):
        #                 ans += s[p]
        #                 p = 2*n*numRows - 2*n + i
        # return ans
        if numRows == 1:
            return s

        ans = ''
        n = len(s)
        step = 2*numRows - 2

        for i in range(numRows):
            j = 0
            while j + i < n:
                ans += s[j+i]
                j += step
                if i != 0 and i != numRows - 1 and j - i < n:
                    ans += s[j-i]
        return ans


