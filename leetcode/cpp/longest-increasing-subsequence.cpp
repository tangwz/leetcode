/*
 * @lc app=leetcode id=300 lang=cpp
 *
 * [300] Longest Increasing Subsequence
 */

// @lc code=start
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if (n < 1) return 0;
        vector<int> tail;
        tail.push_back(nums[0]);
        for (int i = 1; i < n; i++) {
            if (nums[i] > tail.back()) {
                tail.push_back(nums[i]);
                continue;
            }

            int l = 0, r = tail.size()-1;
            while (l < r) {
                int mid = l + r >> 1;
                if (tail[mid] >= nums[i]) r = mid;
                else l = mid + 1;
            }
            tail[l] = nums[i];
        }
        return tail.size();
    }
};
// @lc code=end

