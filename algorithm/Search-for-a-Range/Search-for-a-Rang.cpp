
/* Attention: Your algorithm's runtime complexity must be in the order of O(log n). */
class Solution {
public:
    /*
     * 题目要求我们时间复杂度必须为O(log n).
     * 自然想到使用二分查找，但是这里是一个range.
     * 所以我们使用进行了小小的修改的二分查找来完成。
     */
    vector<int> searchRange(vector<int>& nums, int target) {
        int left =BinarySearchMin(nums, target);
        int right = BinarySearchMax(nums, target);
        return vector<int>{left,right};
    }
    
    int BinarySearchMin(vector<int>& nums, int target){
        int low = 0;
        int high = nums.size() - 1;
        while(low < high ){
            int mid = (high - low)/2 + low;
            if(nums[mid] == target){
                high = mid;
            }else if(nums[mid] > target){
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        return (nums[low] == target) ? low : -1;
    }
    
    int BinarySearchMax(vector<int>& nums, int target){
        int low = 0;
        int high = nums.size() - 1;
        while(low < high ){
            int mid = (high - low + 1)/2 + low;
            if(nums[mid] == target){
                low = mid;
            }else if(nums[mid] > target){
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        return (nums[low] == target) ? low : -1;
    }
    
    
};