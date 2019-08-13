#
# @lc app=leetcode id=16 lang=python3
#
# [16] 3Sum Closest
#
class Solution:
    def threeSumClosest(self, nums: List[int], target: int) -> int:
        nums.sort()
        ans = None
        for i in range(len(nums)-2):
            l, r = i+1, len(nums)-1
            while l < r:
                sum = nums[l] + nums[r] + nums[i]
                if ans is None or abs(ans-target) > abs(sum-target):
                    ans = sum
                if sum < target:
                    l += 1
                else:
                    r -= 1
        return ans
