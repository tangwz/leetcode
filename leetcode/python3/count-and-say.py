#
# @lc app=leetcode id=38 lang=python3
#
# [38] Count and Say
#
class Solution:
    def countAndSay(self, n: int) -> str:
        def say(s):
            count = 1
            ans = ''
            for i in range(1, len(s)):
                if s[i] == s[i-1]:
                    count += 1
                else:
                    ans += str(count) + s[i-1]
                    count = 1
            ans += str(count) + s[-1]
            return ans

        j = 1
        s = '1'
        while j < n:
            s = say(s)
            j += 1
        return s

