
/*
 * 我的做法参考了棋盘染色问题。
 */
class Solution {
public:

    vector<vector<int> > res;
    
    // [0,i-1] is permuted, [i,end] is going to permute
    // each time we swap begin with x belong to [0,i-1], and recursively
    // doing so with dfs(...,i+1)
    void dfs(int i, vector<int>& nums){
        if(i == nums.size()){
            res.push_back(nums);
            return;
        }
        
        dfs(i + 1, nums);
        for(int j = 0; j < i; ++j){
            int ok = 1;
            for(int k = j; k < i; ++k){
                if(nums[i] == nums[k])
                    ok = 0;
            }
            
            if(ok){
                swap(nums[i],nums[j]);
                dfs(i + 1, nums);
                swap(nums[i],nums[j]);
            }
        }
    }
    
    vector<vector<int> > permuteUnique(vector<int>& nums) {
        dfs(0, nums);
        return res;
    }
};