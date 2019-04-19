#
# @lc app=leetcode id=670 lang=python3
#
# [670] Maximum Swap
#
# https://leetcode.com/problems/maximum-swap/description/
#
# algorithms
# Medium (39.36%)
# Total Accepted:    34.6K
# Total Submissions: 87.6K
# Testcase Example:  '2736'
#
# 
# Given a non-negative integer, you could swap two digits at most once to get
# the maximum valued number. Return the maximum valued number you could get.
# 
# 
# Example 1:
# 
# Input: 2736
# Output: 7236
# Explanation: Swap the number 2 and the number 7.
# 
# 
# 
# Example 2:
# 
# Input: 9973
# Output: 9973
# Explanation: No swap.
# 
# 
# 
# 
# Note:
# 
# The given number is in the range [0, 10^8]
# 
# 
#
class Solution:
    def maximumSwap(self, num: int) -> int:
        """
        # Complexity: O(n2)
        nums = list(map(int, str(num)))
        n = len(nums)
        for i in range(n):
            pivot = nums[i]
            ans = -1
            for j in range(i+1, n):
                if nums[j] > pivot or (nums[j] == pivot != nums[i]):
                    ans = j
                    pivot = nums[j]
            if ans > -1:
                nums[i], nums[ans] = nums[ans], nums[i]
                break
        total = 0
        for i in nums:
            total = 10 * total + i
        return total
        """
        nums = list(map(int, str(num)))
        last = {x: i for i, x in enumerate(nums)}
        for i, x in enumerate(nums):
            for d in range(9, x, -1):
                if last.get(d, -1) > i:
                    nums[i], nums[last[d]] = nums[last[d]], nums[i]
                    return int("".join(map(str, nums)))
        return num

