/**
 * 左旋转字符串：http://www.nowcoder.com/practice/12d959b108cb42b1ab72cef4d36af5ec?rp=3&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
 *
 * 汇编语言中有一种移位指令叫做循环左移（ROL），现在有个简单的任务，
 * 就是用字符串模拟这个指令的运算结果。对于一个给定的字符序列S，请
 * 你把其循环左移K位后的序列输出。例如，字符序列S=”abcXYZdef”,要求
 * 输出循环左移3位后的结果，即“XYZdefabc”。是不是很简单？OK，搞定它！
 */
class Solution {
public:
	// 一种巧妙的设计，胜过《剑指offer》
    string LeftRotateString(string str, int n) {
        int len = str.length();
        if(len == 0) return "";
        int k = n % len;
        str += str;
        return str.substr(k, len);
    }
};

/**
 * 一种也还可以的设计
 */
/**
char *LeftRotateString(char *str, int n) {
 
    char *tmp;
 
    tmp = (char *)malloc((n + 1)*sizeof(char));
    if (!tmp)
    {
        /* code */
        printf("allocate memory failed!.\n");
        exit(1);
    }
 
    memcpy(tmp, str, n);
    *(tmp + n) = '\0';
 
    memcpy(str, str + n, strlen(str) - n);
    *(str + strlen(str) - n) = '\0';
 
    strcat(str, tmp);
    free(tmp);
 
    return str;
}
*/