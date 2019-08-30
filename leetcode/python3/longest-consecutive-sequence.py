#
# @lc app=leetcode id=128 lang=python3
#
# [128] Longest Consecutive Sequence
#
class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        ans = 0
        s = set(nums)
        
        for num in nums:
            if num-1 not in s:
                current = 1
                tmp = num
                while tmp + 1 in s:
                    current += 1
                    tmp += 1
                
                ans = max(current, ans)
        return ans

