/**
 * 包含min函数的栈：http://www.nowcoder.com/books/coding-interviews/4c776177d2c04c2494f2555c9fcc1e49?rp=1
 *
 * 定义栈的数据结构，请在该类型中实现一个能够得到栈最小元素的min函数。
 */
class Solution {
    stack<int> dataStack;
    stack<int> minStack;
public:
    void push(int value) {
        dataStack.push(value);
        
        if(minStack.empty() || value < minStack.top()){
            minStack.push(value);
        }
    }
    
    void pop() {
        if(dataStack.top() == minStack.top()) minStack.pop();
        dataStack.pop();
    }
    
    int top() {
        return dataStack.top();
    }
    
    int min() {
        return minStack.top();
    }
};