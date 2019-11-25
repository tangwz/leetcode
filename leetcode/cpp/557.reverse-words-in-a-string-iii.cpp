/*
 * @lc app=leetcode id=557 lang=cpp
 *
 * [557] Reverse Words in a String III
 */

// @lc code=start
class Solution {
public:
    string reverseWords(string s) {
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != ' ') {
                int j = i;
                for (; j < s.size() && s[j] != ' '; j++) {}
                reverse(s.begin() + i, s.begin() + j);
                i = j;
            }
        }
        return s;
    }
};
// @lc code=end

