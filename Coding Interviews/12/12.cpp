/*
 * 数值的整数次方：http://www.nowcoder.com/books/coding-interviews/1a834e5e3e1a4b7ba251417554e07c00?rp=1
 *
 * 给定一个double类型的浮点数base和int类型的整数exponent。求base的exponent次方。
 */

class Solution {
public:
    /*
     * 分治法，将大指数减半处理；
     * 注意奇偶数和正负数即可。
     */
    double Power(double base, int exponent) {
    	if(exponent == 0)
            return 1;
        if(exponent == 1)
            return base;
        
        double res = Power(base, exponent / 2);
        
        if(exponent % 2 == 0){
            return res * res;
        }else if(exponent > 0){
            return res * res * base;
        }else{
            return res * res * 1/base;
        }
    }
};