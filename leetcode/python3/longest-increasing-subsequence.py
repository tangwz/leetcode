#
# @lc app=leetcode id=300 lang=python
#
# [300] Longest Increasing Subsequence
#
class Solution(object):
    def lengthOfLIS(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        # if not nums:
        #     return 0
        # l = [1 for _ in range(len(nums))]
        # for i in range(1, len(nums)):
        #     for j in range(i):
        #         if nums[j] < nums[i]:
        #             l[i] = max(l[i], l[j]+1)
        # return max(l)   
        if not nums:
            return 0
        lst = [nums[0]]
        for n in nums[1:]:
            if n > lst[-1]:
                lst.append(n)
                continue
                
            left, right = 0, len(lst)-1
            while left < right:
                mid = (left + right) >> 1
                if lst[mid] >= n:
                    right = mid
                else:
                    left = mid + 1
            lst[left] = n
        return len(lst)     

