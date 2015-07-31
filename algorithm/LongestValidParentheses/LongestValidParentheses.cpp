class Solution {
public:
	/*
	 * 一种特殊的动态规划，依靠栈来判断括弧；
	 */
    int longestValidParentheses(string s) {
        stack<int> stk;
        stk.push(-1);
        int maxL = 0;
        for(int i = 0; i < s.size(); ++i){
            int t = stk.top();
            if(t != -1 && s[i] == ')' && s[t] == '(')
            {
                stk.pop();
                //DP思想
                maxL = max(maxL, i - stk.top());
            }else{
                stk.push(i);
            }
        }
        return maxL;
    }
};