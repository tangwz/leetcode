/**
 * 连续子数组的最大和：http://www.nowcoder.com/practice/459bd355da1549fa8a49e350bf3df484?rp=2&ru=/ta/coding-interviews
 * 
 */
class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        if(array.empty()) return 0;
    	int ans = array[0];
        int end = ans;
        for(int i = 1; i < array.size(); ++i){
            end = max(array[i] + end, array[i]);
            ans = max(end, ans);
        }
        return ans;
    }
};