/*
 * 旋转数组的最小数字：http://www.nowcoder.com/books/coding-interviews/9f3231a991af4f55b95579b44b7a01ba?rp=1
 *
 * 把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。
 * 输入一个递增排序的数组的一个旋转，输出旋转数组的最小元素。例如
 * 数组{3,4,5,1,2}为{1,2,3,4,5}的一个旋转，该数组的最小值为1。
 */
class Solution {
public:
    /*
     * 传进去旋转数组，注意旋转数组的特性：
     * 1.包含两个有序序列
     * 2.最小数一定位于第二个序列的开头
     * 3.前序列的值都>=后序列的值
     *
     * 所以此题比较扯，随便给个解法即可。
     */
    int minNumberInRotateArray(vector<int> rotateArray) {
        if(rotateArray.size() == 0)
            return 0;
        
        int min = rotateArray[0];
        for(int i = 0; i < rotateArray.size() - 1; ++i){
            if(rotateArray[i] > rotateArray[i + 1])
                return rotateArray[i + 1];
        }
        return rotateArray[0];
    }
};