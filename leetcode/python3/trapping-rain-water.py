#
# @lc app=leetcode id=42 lang=python3
#
# [42] Trapping Rain Water
#
class Solution:
    def trap(self, height: List[int]) -> int:
        ans = 0
        l = 0
        r = len(height) - 1
        left_max = right_max = 0
        while l < r:
            if height[l] < height[r]:
                if height[l] > left_max:
                    left_max = height[l]
                else:
                    ans += left_max - height[l]
                l += 1
            else:
                if height[r] > right_max:
                    right_max = height[r]
                else:
                    ans += right_max - height[r]
                r -= 1
        return ans


