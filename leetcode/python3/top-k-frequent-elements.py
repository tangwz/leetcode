#
# @lc app=leetcode id=347 lang=python3
#
# [347] Top K Frequent Elements
#
class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        count = collections.Counter(nums)   
        return heapq.nlargest(k, count.keys(), key=count.get) 

