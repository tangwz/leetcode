#
# @lc app=leetcode id=4 lang=python3
#
# [4] Median of Two Sorted Arrays
#
class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        l = len(nums1) + len(nums2)
        if l % 2 == 1:
            return self.findKth(nums1, nums2, l//2+1)
        else:
            return (self.findKth(nums1, nums2, l//2) + self.findKth(nums1, nums2, l//2+1)) / 2
        
    def findKth(self, A, B, k):
        if not A:
            return B[k-1]
        if not B:
            return A[k-1]
        if k == 1:
            return min(A[0], B[0])

        a = A[k//2-1] if len(A) >= k//2 else None
        b = B[k//2-1] if len(B) >= k//2 else None

        if b is None or (a is not None and a < b):
            return self.findKth(A[k//2:], B, k-k//2)
        else:
            return self.findKth(A, B[k//2:], k-k//2)
            


