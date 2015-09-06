/**
 * 第一个只出现一次的字符：http://www.nowcoder.com/practice/1c82e8cf713b4bbeb2a5b31cf5b0417c?rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
 *
 * 在一个字符串(1<=字符串长度<=10000，全部由字母组成)中找到第一个只出现一次的字符的位置。若为空串，返回-1
 */
class Solution {
public:
    int FirstNotRepeatingChar(string str) {
        if(str.empty()) return -1;
        // 打表计数
        int tab[2*26] ;
        int c = 0;
        // tab初始化为-1
        memset(tab,-1,2*26*sizeof(int));
        
        for(int i = 0; i < str.size(); ++i){
            c = str.at(i) - 65;
            // 下标存储的数值为字符在str中第一次出现的位置
            if(tab[c] == -1 ) tab[c] = i;
            // 如果第二次（及以上）出现则置为-2
            else tab[c] = -2;
        }
        // 再从tab中查找存储着下标的值
        int ind = -1,min = str.size();
        for(int i = 0; i< 2*26; i++){
            if(tab[i] >= 0){
                if(tab[i] < min){
                    min = tab[i];
                    ind = i;
                }
            }
        }
        if(ind == -1)return -1;
        else
            return min;
    }
};