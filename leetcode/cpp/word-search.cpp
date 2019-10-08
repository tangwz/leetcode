/*
 * @lc app=leetcode id=79 lang=cpp
 *
 * [79] Word Search
 */

// @lc code=start
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); i++)
            for (int j = 0; j < board[i].size(); j++) {
                if (dfs(board, i, j, 0, word))
                    return true;
            }
        return false;
    }

    bool dfs(vector<vector<char>>& board, int i, int j, int u, string& word) {
        if (i < 0 || i >= board.size() || j < 0 || j >= board[i].size() || board[i][j] == ' ' || u >= word.size() || board[i][j] != word[u])
            return false;
        
        if (u == word.size()-1) return true;
        char c = board[i][j];
        board[i][j] = ' ';
        if (dfs(board, i+1, j, u+1, word) || dfs(board, i-1, j, u+1, word) ||
            dfs(board, i, j+1, u+1, word) || dfs(board, i, j-1, u+1, word))
            return true;
        board[i][j] = c;
        return false;
    }
};
// @lc code=end

