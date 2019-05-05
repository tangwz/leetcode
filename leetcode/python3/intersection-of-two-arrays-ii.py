#
# @lc app=leetcode id=350 lang=python3
#
# [350] Intersection of Two Arrays II
#
class Solution:
    def intersect(self, nums1: List[int], nums2: List[int]) -> List[int]:
        d1 = dict()
        d2 = dict()
        for i in nums1:
            if i in d1:
                d1[i] += 1
            else:
                d1[i] = 1
        for j in nums2:
            if j in d2:
                d2[j] += 1
            else:
                d2[j] = 1
                
        ans = []
        for k1 in d1:
            for k2 in d2:
                if k1 == k2:
                    ans.extend([k1]*min(d1[k1], d2[k2]))
        return ans

