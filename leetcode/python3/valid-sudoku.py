#
# @lc app=leetcode id=36 lang=python3
#
# [36] Valid Sudoku
#
class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        def isValid(line):
            line = [x for x in line if x != "."]
            print(line)
            print(len(set(line)) == len(line))
            return len(set(line)) == len(line)

        for i in range(9):
            if not isValid(board[i]):
                return False
        line = []
        for i in range(9):
            for j in range(9):
                line.append(board[j][i])
            if not isValid(line):
                return False
            line = []
            
        for i in (0, 3, 6):
            for j in (0, 3, 6):
                line = [board[x][y] for x in range(i, i+3) for y in range(j, j+3)]
                if not isValid(line):
                    return False
        return True
        
        


