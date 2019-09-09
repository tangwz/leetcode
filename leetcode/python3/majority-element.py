#
# @lc app=leetcode id=169 lang=python3
#
# [169] Majority Element
#
class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        # import collections
        # d = collections.defaultdict(int)
        # for n in nums:
        #     d[n] += 1
        # for k, v in d.items():
        #     if v > len(nums) // 2:
        #         return k


        # nums.sort()
        # return nums[len(nums)//2]

        # Boyer-Moore Majority Voting Algorithm
        count = 0
        candidate = None
        for n in nums:
            if count == 0:
                candidate = n
            count += 1 if candidate == n else -1
        return candidate

