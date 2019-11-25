/*
 * @lc app=leetcode id=47 lang=cpp
 *
 * [47] Permutations II
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        helper(nums, 0);
        return ans;
    }

    void helper(vector<int>& nums, int pos) {
        if (pos == nums.size()-1) {
            ans.push_back(nums);
            return;
        }
        for (int i = pos; i < nums.size(); i++) {
            if (i != pos && nums[i] == nums[i-1]) continue;
            swap(nums[i], nums[pos]);
            helper(nums, pos+1);
        }
    }
};
// @lc code=end

