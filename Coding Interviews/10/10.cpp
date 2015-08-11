/*
 * 斐波那契数列：http://www.nowcoder.com/books/coding-interviews/c6c7742f5ba7442aada113136ddea0c3?rp=1
 * 
 * 大家都知道斐波那契数列，现在要求输入一个整数n，请你输出斐波那契数列的第n项。
 */
class Solution {
public:
	/* 递归求解可能会陷入堆栈太深的问题 */
    int Fibonacci(int n) {
    	/* 迭代法 */
        int first = 0;
        int second = 1;
        while(n--){
            second = first + second;
            first = second - first;
        }
        return first;
    }
};