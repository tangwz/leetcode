class Solution {
public:
    //Dynamic Programming
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n == 0)
            return 0;
        int max = 0;
        int lowest = prices[0];
        for(int i = 0; i < n; ++i){
            int tmp = prices[i] - lowest;
            if(tmp > max){
                max = tmp;
            }
            if(prices[i] < lowest){
                lowest = prices[i];
            }
        }
        return max;
    }
};