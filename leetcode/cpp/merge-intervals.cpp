/*
 * @lc app=leetcode id=56 lang=cpp
 *
 * [56] Merge Intervals
 */
class Solution {
public:
    static bool cmp(vector<int> v1, vector<int> v2) {
        if (v1[0] != v2[0]) return v1[0] < v2[0];
        return v1[1] < v2[1];
    }

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size() == 0) return vector<vector<int>>();
        sort(intervals.begin(), intervals.end(), cmp);
        vector<vector<int>> ans;
        vector<int> now = intervals[0];
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] > now[1]) {
                ans.push_back(now);
                now = intervals[i];
            } else if (intervals[i][1] > now[1]) {
                now[1] = intervals[i][1];
            }
        }
        ans.push_back(now);
        return ans;
    }
};

