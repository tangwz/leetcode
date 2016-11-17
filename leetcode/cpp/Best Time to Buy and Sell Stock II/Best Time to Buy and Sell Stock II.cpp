class Solution {
public:
	//无论如何，假设prices[m]-prices[n]最大，也等于(prices[m]-prices[x])+(prices[x]-prices[n])
	//即，只要不是负数，“皆可抛”~
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        for(int i = 1; i < prices.size(); ++i){
            ans += max(prices[i] - prices[i-1], 0);
        }
        return ans;
    }
};