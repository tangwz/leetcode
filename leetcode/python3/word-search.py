#
# @lc app=leetcode id=79 lang=python
#
# [79] Word Search
#
class Solution(object):
    def exist(self, board, word):
        """
        :type board: List[List[str]]
        :type word: str
        :rtype: bool
        """
        is_visited = [[False for _ in range(len(board[0]))] for _ in range(len(board))]
        def dfs(grid, i, j, w):
            if not w:
                return True
            if not 0 <= i < len(grid) or not 0 <= j < len(grid[0]) or grid[i][j] != w[0]:
                return False
            if is_visited[i][j]:
                return False
            is_visited[i][j] = True
            res = dfs(grid, i+1, j, w[1:]) or dfs(grid, i-1, j, w[1:]) or dfs(grid, i, j+1, w[1:]) or dfs(grid, i, j-1, w[1:])
            is_visited[i][j] = False
            return res
        
        for i in range(len(board)):
            for j in range(len(board[0])):
                if board[i][j] == word[0]:
                    if dfs(board, i, j, word):
                        return True
        return False        

