#
# @lc app=leetcode id=74 lang=python3
#
# [74] Search a 2D Matrix
#
class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        # if not matrix:
        #     return False
        # row = len(matrix) - 1
        # col = 0
        # while col < len(matrix[0]) and row >= 0:
        #     if matrix[row][col] == target:
        #         return True
        #     elif matrix[row][col] > target:
        #         row -= 1
        #     else:
        #         col += 1
        # return False
        m = len(matrix)
        if m == 0:
            return False
        n = len(matrix[0])
        l, r = 0, m*n-1
        while l <= r:
            mid = (l + r) >> 1
            pivot = matrix[mid//n][mid%n]
            if pivot == target:
                return True
            elif pivot > target:
                r = mid-1
            else:
                l = mid+1
        return False

