/**
 * 栈的压入、弹出序列：http://www.nowcoder.com/books/coding-interviews/d77d11405cc7470d82554cb392585106?rp=1
 *
 * 输入两个整数序列，第一个序列表示栈的压入顺序，
 * 请判断第二个序列是否为该栈的弹出顺序。假设压入
 * 栈的所有数字均不相等。例如序列1,2,3,4,5是某栈
 * 的压入顺序，序列4，5,3,2,1是该压栈序列对应的一
 * 个弹出序列，但4,3,5,1,2就不可能是该压栈序列的
 * 弹出序列。
 */
class Solution {
public:
    // 《剑指offer》上的解也太复杂了。。。
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        if(pushV.size() == 0) return false;
        stack<int> s;
        int j = 0;
        for(int i = 0; i < pushV.size(); ++i){
            s.push(pushV[i]);
            while(j < popV.size() && s.top() == popV[j]){
                s.pop();
                j++;
            }
        }
        return s.empty();
    }
};