/**
 * 数组中只出现一次的数字：http://www.nowcoder.com/practice/e02fdb54d7524710a7d664d082bb7811?rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
 *
 * 一个整型数组里除了两个数字之外，其他的数字都出现了两次。请写程序找出这两个只出现一次的数字。
 */
class Solution {
public:
    // 经典的异或使用
    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
        int len = data.size();
        *num1 = *num2 = 0;
        if(len < 2)
            return;
        int s = 0, p = 1;
        for(int i = 0; i < len; ++i)
            s ^= data[i];
        while(!(s & p))
            p <<= 1;
        for(int i = 0; i < len; ++i) 
            ((data[i] & p) ? *num1 : *num2) ^= data[i];
    }
};