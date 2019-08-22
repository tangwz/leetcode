#
# @lc app=leetcode id=43 lang=python3
#
# [43] Multiply Strings
#
class Solution:
    def multiply(self, num1: str, num2: str) -> str:
        len1, len2 = len(num1), len(num2)
        dig1 = dig2 = 0
        for i in range(len1):
            dig1 = dig1 * 10 + ord(num1[i]) - ord('0')
        for i in range(len2):
            dig2 = dig2 * 10 + ord(num2[i]) - ord('0')
        return str(dig1*dig2)

