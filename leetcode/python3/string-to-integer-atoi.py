#
# @lc app=leetcode id=8 lang=python3
#
# [8] String to Integer (atoi)
#
class Solution:
    def myAtoi(self, str: str) -> int:
        ans = []
        target = str.strip()
        
        if not target:
            return 0
        
        i = 0
        if target[i] == '-':
            ans += '-'
            i += 1
        elif target[i] == '+':
            i += 1
            
        ints = list("0123456789")
        
        while i < len(target):
            if target[i] in ints:
                ans.append(target[i])
            else:
                i = len(target)
            i += 1
            
        if not len(ans) or ans == ["-"]:
            ans = 0
        else:
            ans = int(''.join(ans))
        
        INT_MAX = 2_147_483_647
        INT_MIN = -2_147_483_648
        if ans >= 0:
            return min(ans, INT_MAX)
        return max(INT_MIN, ans)

