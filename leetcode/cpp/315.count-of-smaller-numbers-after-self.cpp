/*
 * @lc app=leetcode id=315 lang=cpp
 *
 * [315] Count of Smaller Numbers After Self
 */

// @lc code=start
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 0);
        vector<pair<int, int>> p(n);
        for (int i = 0; i < n; i++) p[i] = make_pair(i, nums[i]);
        mergeSort(p, ans, 0, n);
        return ans;
    }

    void mergeSort(vector<pair<int, int>>& p, vector<int>& ans, int left, int right) {
        if (left + 1 < right) {
            int mid = left + right >> 1;
            mergeSort(p, ans, left, mid);
            mergeSort(p, ans, mid, right);
            merge(p, ans, left, mid, right);
        }
        return;
    }

    void merge(vector<pair<int, int>>& p, vector<int>& ans, int left, int mid, int right) {
        auto it_left = p.begin() + left;
        auto it_mid = p.begin() + mid;
        auto it_right = p.begin() + right;

        vector<pair<int, int>> l(it_left, it_mid), r(it_mid, it_right);
        int i = 0, j = 0, k = 0;
        while (i < l.size() && j < r.size()) {
            if (l[i].second <= r[j].second) {
                ans[l[i].first] += j;
                p[left+k] = l[i];
                ++i;
                ++k;
            } else {
                p[left+k] = r[j];
                ++j;
                ++k;
            }
        }

        while (i < l.size()) {
            ans[l[i].first] += j;
            p[left+k] = l[i];
            ++i;
            ++k;
        }

        while (j < r.size()) {
            p[left+k] = r[j];
            ++j;
            ++k;            
        }

    }
};
// @lc code=end

