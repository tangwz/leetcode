#
# @lc app=leetcode id=240 lang=python3
#
# [240] Search a 2D Matrix II
#
class Solution:
    def searchMatrix(self, matrix, target):
        """
        :type matrix: List[List[int]]
        :type target: int
        :rtype: bool
        """
        if len(matrix) == 0 or len(matrix[0]) == 0:
            return False
        col = 0
        row = len(matrix) - 1
        while col < len(matrix[0]) and row >= 0:
            if matrix[row][col] == target:
                return True
            elif matrix[row][col] > target:
                row -= 1
            else:
                col += 1
        return False


