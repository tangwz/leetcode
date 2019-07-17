#
# @lc app=leetcode id=73 lang=python3
#
# [73] Set Matrix Zeroes
#
class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        """
        # 使用额外辅助空间
        R = len(matrix)
        C = len(matrix[0])
        cols = set()
        rows = set()
        for i in range(R):
            for j in range(C):
                if matrix[i][j] == 0:
                    rows.add(i)
                    cols.add(j)

        for i in range(R):
            for j in range(C):
                if i in rows or j in cols:
                    matrix[i][j] = 0
        """

        # 遍历整个矩阵，如果 cell[i][j] == 0 就将第 i 行和第 j 列的第一个元素标记。
        # 第一行和第一列的标记是相同的，都是 cell[0][0]，所以需要一个额外的变量告知第一列是否被标记
        R = len(matrix)
        C = len(matrix[0])
        is_col = False
        for i in range(R):
            if matrix[i][0] == 0:
                is_col = True
            for j in range(1, C):
                if matrix[i][j] == 0:
                    matrix[0][j] = 0
                    matrix[i][0] = 0
        
        for i in range(1, R):
            for j in range(1, C):
                if not matrix[i][0] or not matrix[0][j]:
                    matrix[i][j] = 0
        
        if matrix[0][0] == 0:
            for j in range(C):
                matrix[0][j] = 0

        if is_col:
            for i in range(R):
                matrix[i][0] = 0

