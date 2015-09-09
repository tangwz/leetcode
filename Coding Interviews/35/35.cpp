/**
 * 数组中的逆序对：http://www.nowcoder.com/practice/96bd6684e04a44eb80e6a68efc0ec6c5?rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
 * 
 * 在数组中的两个数字，如果前面一个数字大于后面的数字，
 * 则这两个数字组成一个逆序对。输入一个数组，求出这个
 * 数组中的逆序对的总数。
 */
class Solution {
public:
    int InversePairs(vector<int> data) {
        int len = data.size();
        return mergeSort(data, 0, len - 1);
    }
    
    int mergeSort(vector<int>& data, int start, int end){
        // 递归终止条件
        if(start >= end){
            return 0;
        }
        
        int mid = (start + end) / 2;
        int leftCounts = mergeSort(data, start, mid);
        int rightCounts = mergeSort(data, mid+1, end);
        
        vector<int> copy(data); // 数组副本，用于归并排序
        int foreIdx = mid;      // 前半部分的指标
        int backIdx = end;      // 后半部分的指标
        int counts = 0;         // 记录本次逆序对数
        int idxCopy = end;      // 辅助数组的下标
        while(foreIdx >= start && backIdx >= mid+1) {
            if(data[foreIdx] > data[backIdx]) {
                copy[idxCopy--] = data[foreIdx--];
                counts += backIdx - mid;
            } else {
                copy[idxCopy--] = data[backIdx--];
            }
        }
        while(foreIdx >= start) {
            copy[idxCopy--] = data[foreIdx--];
        }
        while(backIdx >= mid+1) {
            copy[idxCopy--] = data[backIdx--];
        }
        for(int i = start; i <= end; i++) {
            data[i] = copy[i];
        }
 
        return (leftCounts + rightCounts + counts);
    }
};