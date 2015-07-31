/*
 * ѧϰ���ݽṹӦ�ö���Ӵ���һ���⣬�ܼ򵥣�ʹ��ջ����ɡ�
*/
class Solution {
public:
    bool isValid(string s) {
        if(s.size() <= 1) return false;
        stack<char> mystack;
        size_t len = s.size();
        for(size_t i = 0; i < len; ++i)
        {
            if(s[i] == '(' || s[i] == '[' || s[i] == '{')
            {
                mystack.push(s[i]);
            }
            else{
                if(mystack.empty())
                    return false;
                if(s[i] == ')' && mystack.top() != '(')
                    return false;
                if(s[i] == ']' && mystack.top() != '[')
                    return false;
                if(s[i] == '}' && mystack.top() != '{')
                    return false;

                mystack.pop();
            }
        }
        return mystack.empty();
    }
};