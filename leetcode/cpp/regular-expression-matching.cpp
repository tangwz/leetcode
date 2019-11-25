/*
 * @lc app=leetcode id=10 lang=cpp
 *
 * [10] Regular Expression Matching
 */

// @lc code=start
class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        vector<vector<bool>> dp(m+1, vector<bool>(n+1, false));
        dp[0][0] = true;
        for (int j = 1; j <= n; j++) {
            if (p[j-1] == '*') dp[0][j] = j > 1 && dp[0][j-2];
        }

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                // if (p[j-1] != '*')
                //     dp[i][j] = dp[i-1][j-1] && (s[i-1] == p[j-1] || p[j-1] == '.');
                // else
                //     // p[0] cannot be '*' so no need to check "j > 1" here
                //     dp[i][j] = dp[i][j-2] || (s[i-1] == p[j-2] || p[j-2] == '.') && dp[i-1][j];
                if (p[j-1] != '*') {
                    dp[i][j] = dp[i-1][j-1] && (s[i-1] == p[j-1] || p[j-1] == '.');
                } else {
                    dp[i][j] = dp[i][j-2] || (s[i-1] == p[j-2] || p[j-2] == '.') && dp[i-1][j];
                }
            }
        }
        return dp[m][n];
    }
};
// @lc code=end
