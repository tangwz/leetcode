/*
 * @lc app=leetcode id=221 lang=cpp
 *
 * [221] Maximal Square
 */

// @lc code=start
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        // int n = matrix.size();
        // if (n == 0) return 0;
        // int m = matrix[0].size();
        // vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        // int ans = 0;
        // for (int i = 1; i <= n; i++) {
        //     for (int j = 1; j <= m; j++) {
        //         if (matrix[i][j] == '1') {
        //             dp[i][j] = min(min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1]) + 1;
        //             ans = max(ans, dp[i][j]);
        //         }
        //     }
        // }
        // return ans;
        if (matrix.empty()) return 0;
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> dp(n+1, 0);
        int ans = 0, prev = 0;
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                int temp = dp[j];
                if (matrix[i-1][j-1] == '1') {
                    dp[j] = min(min(dp[j-1], prev), dp[j]) + 1;
                    ans = max(ans, dp[j]);
                } else {
                    dp[j] = 0;
                }
                prev = temp;
            }
        }
        return ans * ans;
    }
};
// @lc code=end

