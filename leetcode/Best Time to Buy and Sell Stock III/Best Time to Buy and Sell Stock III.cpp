class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty())  
            return 0;  
        int n = prices.size();  
        vector<int> pre(n,0);  
        vector<int> post(n,0);  
        int curMin = prices[0];  
        int curMax = prices[n-1];  
        int result = 0;
		
        for(int i=1; i<n; i++)  
        {  
            curMin = curMin < prices[i] ? curMin : prices[i];  
            int diff = prices[i]-curMin;  
            pre[i] = pre[i-1] > diff ? pre[i-1] : diff;  
        }  
		
        for(int i=n-2; i>=0; i--)  
        {  
            curMax = curMax > prices[i] ? curMax : prices[i];  
            int diff = curMax-prices[i];  
            post[i] = post[i+1] > diff ? post[i+1] : diff;  
        }
		
        for(int i=1; i<n; i++)  
        {  
            result = result > (pre[i]+post[i]) ? result : (pre[i]+post[i]);  
        }  
        return result; 
    }
};