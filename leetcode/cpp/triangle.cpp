/*
 * @lc app=leetcode id=120 lang=cpp
 *
 * [120] Triangle
 */
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> dp(triangle[n-1].begin(), triangle[n-1].end());
        for (int i = n-2; i >= 0; i--) {
            for (int j = 0; j < triangle[i].size(); j++) {
                dp[j] = triangle[i][j] + min(dp[j], dp[j+1]);
            }
        }
        return dp[0];
    }
};

