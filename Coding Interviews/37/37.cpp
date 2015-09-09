/**
 * 数字在排序数组中出现的次数：http://www.nowcoder.com/practice/70610bf967994b22bb1c26f9ae901fa2?rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
 *
 * 统计一个数字在排序数组中出现的次数。
 */
class Solution {
public:
    int GetNumberOfK(vector<int> data ,int k) {
        return findLastK(data, k) - findFirstK(data, k) + 1;
    }
    
    int findFirstK(vector<int> data, int k){
        int left = 0, right = data.size() - 1;
        if(right < 0 || data[right] < k) return -1;
        if(data[0] == k) return 0;
        while(left + 1 < right){
            int mid = (right - left) / 2 + left;
            if(data[mid] >= k) right = mid;
            else left = mid;
        }
        return data[right] == k ? right : -1;
    }
    
    int findLastK(vector<int> data, int k){
        int left = 0, right = data.size() - 1;
        if(right < 0 || data[left] > k) return -2;
        if(data[right] == k) return right;
        while(left + 1 < right){
            int mid = (right - left) / 2 + left;
            if(data[mid] <= k) left = mid;
            else right = mid;
        }
        return data[left] == k ? left : -2;
    }
};