/*
 * @lc app=leetcode id=131 lang=cpp
 *
 * [131] Palindrome Partitioning
 */

// @lc code=start
class Solution {
public:
    vector<vector<string>> res;
    vector<string> path;

    vector<vector<string>> partition(string s) {
        dfs("", 0, s);
        return res;
    }

    bool check(string now) {
        if (now.size() == 0) return false;
        for (int i = 0, j = now.size()-1; i < j; i++, j--) {
            if (now[i] != now[j]) return false;
        }
        return true;
    }

    void dfs(string now, int i, string s) {
        if (i == s.size()) {
            if (check(now)) {
                path.push_back(now);
                res.push_back(path);
                path.pop_back();
            }
            return;
        }

        if (check(now)) {
            path.push_back(now);
            dfs("", i, s);
            path.pop_back();
        }

        dfs(now+s[i], i+1, s);
    }
};
// @lc code=end

