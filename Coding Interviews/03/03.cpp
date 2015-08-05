/*
 * 矩形覆盖：http://www.nowcoder.com/books/coding-interviews/72a5a919508a4251859fb2cfb987a0e6?rp=1
 * 我们可以用2*1的小矩形横着或者竖着去覆盖更大的矩形。
 * 请问用n个2*1的小矩形无重叠地覆盖一个2*n的大矩形，总共有多少种方法？
 */
class Solution {
public:
    /*
     * 讨论横着放和竖着放，其实就是一个斐波那契问题。
     */
    int rectCover(int number) {
        if(number == 0){
            return 1;
        }else if(number == 1){
            return 1;
        }else if(number == 2){
            return 2;
        }else{
            return rectCover(number - 1) + rectCover(number - 2);
        }
    }
};