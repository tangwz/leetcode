#
# @lc app=leetcode id=88 lang=python
#
# [88] Merge Sorted Array
#
class Solution(object):
    def merge(self, nums1, m, nums2, n):
        """
        :type nums1: List[int]
        :type m: int
        :type nums2: List[int]
        :type n: int
        :rtype: None Do not return anything, modify nums1 in-place instead.
        """
        m -= 1
        n -= 1
        index = m + n + 1
        while m >= 0 or n >= 0:
            if m >= 0 and n >= 0:
                if nums1[m] > nums2[n]:
                    nums1[index] = nums1[m]
                    m -= 1
                else:
                    nums1[index] = nums2[n]
                    n -= 1
            else:
                if m >= 0:
                    nums1[index] = nums1[m]
                    m -= 1
                if n >= 0:
                    nums1[index] = nums2[n]
                    n -= 1
            index -= 1
        return

