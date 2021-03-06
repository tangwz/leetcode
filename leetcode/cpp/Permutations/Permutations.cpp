class Solution {
public:
    /*
     * Backtracking(or Depth-first search)--like this:http://codevs.cn/problem/1294/
     *
     * How to write a Backtracking?
     * void dfs(int cur or gap,type* input, type *path, type* res){
     *     if(error input) return 0;
     *     if(cur == input.size()(or gap == 0)) res.push(path);
     *
     *     if(modify) return;
     *
     *     for(...){
     *         modify path;
     *         dfs(step++ or gap--, input, path, res);
     *         recovery path;
     *     }
     * }
     *
     * 
     */
    vector<vector<int> > res;

    void dfs(int i, vector<int>& nums){
        if(i == nums.size()) res.push_back(nums);
        for(int j = i; j < nums.size(); ++j){
            swap(nums[i],nums[j]);
            dfs(i + 1, nums);
            swap(nums[i],nums[j]);
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        dfs(0, nums);
        return res;
    }
};