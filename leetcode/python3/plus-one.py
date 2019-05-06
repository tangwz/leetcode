#
# @lc app=leetcode id=66 lang=python3
#
# [66] Plus One
#
class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        ans = []
        value = 1
        for i, n in enumerate(digits[::-1]):
            value = n +  value
            ans.insert(0, value % 10)
            value = value // 10
        if value > 0:
            ans.insert(0, value)
        return ans

