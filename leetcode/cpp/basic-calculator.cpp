/*
 * @lc app=leetcode id=224 lang=cpp
 *
 * [224] Basic Calculator
 */

// @lc code=start
class Solution {
public:
    int calculate(string s) {
        stack<int> stk;
        int ans = 0, tmp = 0;
        char sign = '+';
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            if (isdigit(c)) tmp = 10*tmp + c-'0';

            if (!isdigit(c) && c != ' ' || i == s.size()-1) {
                if (sign == '-')
                    stk.push(-tmp);
                else if (sign == '+')
                    stk.push(tmp);
                else {
                    int num;
                    if (sign == '*') num = stk.top() * tmp;
                    else num = stk.top() / tmp;
                    stk.pop();
                    stk.push(num);
                }
                sign = s[i];
                tmp = 0;
            }
        }

        while (!stk.empty()) {
            ans += stk.top();
            stk.pop();
        }
        return ans;
    }
};
// @lc code=end

