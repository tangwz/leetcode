# -*- coding: utf-8 -*-


class Solution(object):
    """ The easiest way is merging the two lists and find the median number.
        But this way need time complexity O(m+n).
        We need the overall run time complexity should be O(log(m+n)). So we
        must search efficiently such as using binary search.
    """
    def findMedianSortedArrays(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: float
        """
        l = len(nums1) + len(nums2)
        if l % 2 == 1:
            return self.findKth(nums1, nums2, l / 2 + 1)
        else:
            return (self.findKth(nums1, nums2, l / 2) + self.findKth(nums1, nums2, l / 2 + 1)) / 2.0

    # If we can find the kth in the tow sorted arrays, we can easily find the median.
    # We can modify the binary search for tow sorted arrays. Firstly we find k/2, if
    # the length of A and B are bigger than k/2, we can compare A[k/2] to B[k/2]. If
    # A[k/2] > B[k/2], the B[0 -> k/2] must be a part of (A+B)[k/2]. And we can delete
    # this part of B and continue finding. Similarly if A[k/2] < B[k/2] we can delete
    # a part of A. If A[k/2] = B[k/2] that we find the kth element. Specifically, if
    # k = 1, we return the minimal of A and B.
    def findKth(self, A, B, k):
        if not A:
            return B[k - 1]
        if not B:
            return A[k - 1]
        if k == 1:
            return min(A[0], B[0])

        a = A[k / 2 - 1] if len(A) >= k / 2 else None
        b = B[k / 2 - 1] if len(B) >= k / 2 else None

        if b is None or (a is not None and a < b):
            return self.findKth(A[k/2:], B, k - k/2)
        else:
            return self.findKth(A, B[k/2:], k - k/2)


if __name__ == '__main__':
    test1_nums1 = [1, 3]
    test1_nums2 = [2]

    test2_nums1 = [1, 2]
    test2_nums2 = [3, 4]

    s = Solution()
    assert s.findMedianSortedArrays(test1_nums1, test1_nums2) == 2.0
    assert s.findMedianSortedArrays(test2_nums1, test2_nums2) == 2.5
