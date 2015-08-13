/**
 * 调整数组顺序使奇数位于偶数前面：http://www.nowcoder.com/books/coding-interviews/beb5aa231adc45b2a5dcc5b62c93f593?rp=1
 *
 * 输入一个整数数组，实现一个函数来调整该数组中数字的顺序，
 * 使得所有的奇数位于数组的前半部分，所有的偶数位于位于数组
 * 的后半部分，并保证奇数和奇数，偶数和偶数之间的相对位置不变。
 */
class Solution {
public:
    void reOrderArray(vector<int> &array) {
        //原书中的方法，类似于快排，但数字顺序被打乱
        /*int i=0;
        int j=array.length-1;
        while(i<j){
            while(i<j&&array[i]%2==1){
                i++;
            }
            while(i<j&&array[j]%2==0){
                j--;
            }
            int temp=array[j];
            array[j]=array[i];
            array[i]=temp;
        }*/

        // 类似插入排序，当前数是奇数，就往后找，遇到偶数就往它前面插       
        for(int i = 0; i < array.size(); ++i){
            if(array[i] % 2 == 1){
                int tmp = array[i];
                int j = i - 1;
                while(j >= 0 && array[j] % 2 == 0){
                    array[j+1] = array[j];
                    j--;
                }
                array[j+1] = tmp;
            }
        }
    }
};