#
# @lc app=leetcode id=229 lang=python3
#
# [229] Majority Element II
#
class Solution:
    def majorityElement(self, nums: List[int]) -> List[int]:
        # n / 3 最多存在两个众数
        candidate1 = candidate2 = None
        count1 = count2 = 0
        for n in nums:
            if n == candidate1:
                count1 += 1
            elif n == candidate2:
                count2 += 1
            elif count1 == 0:
                candidate1 = n
                count1 = 1
            elif count2 == 0:
                candidate2 = n
                count2 = 1
            else:
                count1 -= 1
                count2 -= 1

        # 无法确认候选人是否真的大于 n / 3    
        # 再遍历一次进行计算    
        count1, count2 = nums.count(candidate1), nums.count(candidate2)
        ans = []
        if count1 > len(nums) // 3:
            ans.append(candidate1)
        if count2 > len(nums) // 3:
            ans.append(candidate2)
        return ans

