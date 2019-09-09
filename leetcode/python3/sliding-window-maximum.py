#
# @lc app=leetcode id=239 lang=python3
#
# [239] Sliding Window Maximum
#
class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        # if not nums:
        #     return []
        # ans = []
        # begin, end = 0, k
        # while end <= len(nums):
        #     tmp = nums[begin:end]
        #     ans.append(max(tmp))
        #     begin += 1
        #     end += 1
        # return ans
        from collections import deque

        queue = deque()
        ans = []
        for i in range(len(nums)):
            if queue and i - queue[0] + 1 > k:
                queue.popleft()
            while queue and nums[queue[-1]] <= nums[i]:
                queue.pop()
            queue.append(i)
            if i - k + 1 >= 0:
                ans.append(nums[queue[0]])
        return ans
        

            


