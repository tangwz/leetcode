/*
 * 变态跳台阶：http://www.nowcoder.com/books/coding-interviews/22243d016f6b47f2a6928b4313c85387?rp=1
 * 一只青蛙一次可以跳上1级台阶，也可以跳上2级……它也可以跳上n级。求该青蛙跳上一个n级的台阶总共有多少种跳法。
 */
class Solution {
public:
	/*
	 * f(n-1) = f(0) + f(1)+f(2)+f(3) + ... + f((n-1)-1) = f(0) + f(1) + f(2) + f(3) + ... + f(n-2)
     * f(n) = f(0) + f(1) + f(2) + f(3) + ... + f(n-2) + f(n-1) = f(n-1) + f(n-1)
     * 可以得出：
     * f(n) = 2*f(n-1)
	 */
    int jumpFloorII(int number) {
         if(number <=  0){
             return 0;
         }else if(number == 1){
             return 1;
         }else{
             return 2*jumpFloorII(number - 1);
         }
    }
};