/*
 * 用两个栈实现队列：http://www.nowcoder.com/books/coding-interviews/54275ddae22f475981afa2244dd448c6?rp=1
 *
 * 用两个栈来实现一个队列，完成队列的Push和Pop操作。 
 * 队列中的元素为int类型。
 */
class Solution
{
public:
    // 第一个栈用于进队列
    void push(int node) {
        stack1.push(node);
    }
    
	// 第二个栈用于出队列，栈2不空则先输出栈2
    // 栈2空则把栈1数据“倒”如栈2
    int pop() {
        if(stack2.empty()){
            while(!stack1.empty()){
                int data = stack1.top();
                stack1.pop();
                stack2.push(data);
            }
        }           
        int res = stack2.top();
        stack2.pop();
        
        return res;
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};