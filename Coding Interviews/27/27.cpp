/**
 * 字符串的排列：http://www.nowcoder.com/practice/fe6b651b66ae47d7acce78ffdd9a96c7?rp=2&ru=/ta/coding-interviews
 *
 * 输入一个字符串,按字典序打印出该字符串中字符的所有排列。
 * 例如输入字符串abc,则打印出由字符a,b,c所能排列出来的所有字符串abc,acb,bac,bca,cab和cba。 
 */
class Solution {
public:
    // 回溯法，经典案例：八皇后问题
    void Permutation(string str, int idx,vector<string>& res) {
        if(idx == str.length() - 1) {
            res.push_back(str);
            return;
        }
 
        for(int i = idx; i < str.length(); i++) {
            // 加上if去重
            if(idx == i || str[idx] != str[i]) {
                swap(str[idx], str[i]);
                Permutation(str, idx+1,res);
                swap(str[idx], str[i]);
            }
        }
    }
    
    vector<string> Permutation(string str) {
        // 基本参数
        vector<string> res;
        Permutation(str, 0, res);
 
        // 按字典顺序输出
        sort(res.begin(), res.end());
        return res;
    }
};