/*
 * @lc app=leetcode id=179 lang=cpp
 *
 * [179] Largest Number
 */

// @lc code=start
class Solution {
public:
    static bool cmp(int x, int y) {
        string sx = to_string(x), sy = to_string(y);
        return sx+sy > sy+sx;
    }
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), cmp);
        string ans = "";
        for (const auto& n : nums)
            ans += to_string(n);

        for (int i = 0; i < ans.size(); i++)
            if (i == ans.size() - 1 || ans[i] != '0')
                return ans.substr(i, ans.size()-i);

        return ans;
    }
};
// @lc code=end

