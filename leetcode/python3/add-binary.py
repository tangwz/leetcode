#
# @lc app=leetcode id=67 lang=python3
#
# [67] Add Binary
#
class Solution:
    def addBinary(self, a: str, b: str) -> str:
        # return str(bin(int(a, 2) + int(b, 2)))[2:]
        diff = len(a) - len(b)
        if diff > 0:
            b = '0'*diff + b
        if diff < 0:
            a = '0'*-diff + a
        carry = 0
        l = len(a) - 1
        ans = ''

        while l >= 0:
            s = int(a[l]) + int(b[l]) + carry
            if s == 2:
                carry = 1
                ans = '0' + ans
            elif s == 3:
                carry = 1
                ans = '1' + ans
            else:
                carry = 0
                ans = str(s) + ans
            l -= 1
        if carry:
            ans = str(carry) + ans
        return ans
                

