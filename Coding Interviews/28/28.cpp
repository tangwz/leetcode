/**
 * 数组中出现次数超过一半的数字：http://www.nowcoder.com/practice/e8a1b01a2df14cb2b228b30ee6a92163?rp=2&ru=/ta/coding-interviews
 *
 * 数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。
 * 例如输入一个长度为9的数组{1,2,3,2,2,2,5,4,2}。由于数字2在数组
 * 中出现了5次，超过数组长度的一半，因此输出2。
 */
class Solution {
public:
    // 直接O(N)，相同加1，不同减1
    int MoreThanHalfNum_Solution(vector<int> numbers) {
    	int n = numbers.size();
        if (n == 0) return 0;
        
        int num = numbers[0], count = 1;
        for(int i = 0; i < n; ++i){
            if(numbers[i] == num) count++;
            else count--;
            if(count == 0){
                num = numbers[i];
                count = 1;
            }
        }
        
        // Verify
        count = 0;
        for (int i = 0; i < n; i++) {
            if (numbers[i] == num) count++;
        }
        if (count * 2 > n) return num;
        return 0;
    }
};