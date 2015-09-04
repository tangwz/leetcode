/**
 * 丑数：http://www.nowcoder.com/practice/6aa9e04fc3794f68acf8778237ba065b?rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
 *
 * 把只包含因子2、3和5的数称作丑数（Ugly Number）。
 * 例如6、8都是丑数，但14不是，因为它包含因子7。 习
 * 惯上我们把1当做是第一个丑数。求按从小到大的顺序的
 * 第N个丑数。
 */
class Solution {
public:
    int GetUglyNumber_Solution(int index) {
    	if(index <= 0)
            return 0;
        
        vector<int> uglyNum(index, 1);
        int index2 = 0;
        int index3 = 0;
        int index5 = 0;
        int nextUglyIndex = 1;
        
        while(nextUglyIndex < index){
            int uglyNumber = min(uglyNum[index2]*2, uglyNum[index3]*3);
            uglyNumber = min(uglyNumber, uglyNum[index5]*5);
            uglyNum[nextUglyIndex] = uglyNumber;
            while(uglyNum[index2] * 2 <= uglyNum[nextUglyIndex])
                index2++;
            while(uglyNum[index3] * 3 <= uglyNum[nextUglyIndex]) {
                index3++;
            }
            while(uglyNum[index5] * 5 <= uglyNum[nextUglyIndex]) {
                index5++;
            }
            nextUglyIndex++;
        }
        
        return uglyNum[index - 1];
    }
};