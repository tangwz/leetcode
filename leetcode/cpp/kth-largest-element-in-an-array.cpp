/*
 * @lc app=leetcode id=215 lang=cpp
 *
 * [215] Kth Largest Element in an Array
 */

// @lc code=start
class Solution {
public: 
    int partition(vector<int>& nums, int left, int right) {
        int pivot = nums[left], l = left, r = right;
        while (l < r) {
            while (nums[r] <= pivot && l < r) r--;
            nums[l] = nums[r];
            while (nums[l] >= pivot && l < r) l++;
            nums[r] = nums[l];
        }
        nums[l] = pivot;
        return l;
    }

    int findKthLargest(vector<int>& nums, int k) {
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int p = partition(nums, left, right);
            if (p == k - 1) {
                return nums[p];
            }
            if (p < k - 1) {
                left = p + 1;
            } else {
                right = p - 1;
            }
        }
        return -1;
    }
};
// @lc code=end

