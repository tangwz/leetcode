/*
 * @lc app=leetcode id=46 lang=cpp
 *
 * [46] Permutations
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> ans;
    vector<int> path;
    vector<bool> used;
    vector<vector<int>> permute(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) used.push_back(false);
        dfs(nums);
        return ans;
    }

    void dfs(vector<int>& nums) {
        if (path.size() == nums.size()) {
            ans.push_back(path);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if(!used[i]) {
                used[i] = true;
                path.push_back(nums[i]);
                dfs(nums);
                used[i] = false;
                path.pop_back();
            }
        }
    }
};
// @lc code=end

