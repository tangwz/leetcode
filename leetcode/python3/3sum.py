#
# @lc app=leetcode id=15 lang=python3
#
# [15] 3Sum
#
class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        """
        1、先排序，比较好去重
        2、当 nums[i] > 0 时，直接跳出，因为后面的所有数字都大于 0，不可能再找得到组合了
        3、当 i > 0 and nums[i] == nums[i-1] 时，跳过，去重
        4、l 和 r 设在 [i, len(nums)] 两端，根据 nums[l] + nums[r] + nums[i] 与 0 的
           关系向中间逼近，等于 0 则加入 ans。
        注意：移动 l 和 r 时需要跳过所有重复值
        """
        ans = []
        nums.sort()
        for i in range(len(nums)-2):
            if nums[i] > 0:
                break
            if i > 0 and nums[i] == nums[i-1]:
                continue
            l, r = i + 1, len(nums) - 1
            while l < r:
                target = nums[l] + nums[r] + nums[i]
                if target < 0:
                    l += 1
                    while l < r and nums[l] == nums[l-1]: l += 1
                elif target > 0:
                    r -= 1
                    while l < r and nums[r] == nums[r+1]: r -= 1
                else:
                    ans.append([nums[i], nums[l], nums[r]])
                    l += 1
                    r -= 1
                    while l < r and nums[l] == nums[l-1]: l += 1
                    while l < r and nums[r] == nums[r+1]: r -= 1
        return ans

