/**
 * 和为S的两个数字：http://www.nowcoder.com/practice/390da4f7a00f44bea7c2f3d19491311b?rp=3&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
 * 
 * 输入一个递增排序的数组和一个数字S，
 * 在数组中查找两个数，是的他们的和正
 * 好是S，如果有多对数字的和等于S，输
 * 出两个数的乘积最小的。 
 */
class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> array,int sum) {
        vector<int> res;
        int len = array.size();
        int i = 0, j = len - 1;
        while(i < j){
            if(array[i] + array[j] == sum){
                res.push_back(array[i]);
                res.push_back(array[j]);
                break;
            }
            while(i < j && array[i] + array[j] > sum) --j;
            while(i < j && array[i] + array[j] < sum) ++i;
        }
        return res;
    }
};