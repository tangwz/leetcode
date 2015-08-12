/*
 * 二进制中1的个数： http://www.nowcoder.com/books/coding-interviews/8ee967e43c2c4ec193b040ea7fbb10b8?rp=1
 *
 * 输入一个整数，输出该数二进制表示中1的个数。其中负数用补码表示
 */

class Solution {
public:
     int  NumberOf1(int n) {
         /* 普通的做法，需要注意负数即可。
         int res = 0;
         unsigned int flag = 1;
         while(flag){
             if(n & flag)
                 res++;
             
             flag = flag << 1;
         }
         return res;
         */
         
         /* 巧解，n有多少个1就可以进行多少次操作 */
         int res = 0;
         
         while(n){
             ++res;
             n = (n - 1) & n;
         }
         return res;
     }
};