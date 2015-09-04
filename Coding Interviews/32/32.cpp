/**
 * 把数组排成最小的数：http://www.nowcoder.com/practice/8fecd3f8ba334add803bf2a06af1b993?rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
 *
 * 输入一个正整数数组，把数组里所有数字拼接起来排成一个数，打印
 * 能拼接出的所有数字中最小的一个。例如输入数组{3，32，321}，则
 * 打印出这三个数字能排成的最小数字为321323。
 */
class Solution {
public:
    // 注意大数处理
    static bool compare(const string& str1, const string& str2){
    	string s1 = str1 + str2;
        string s2 = str2 + str1;
        return s1 < s2;
    }
    
    string PrintMinNumber(vector<int> numbers) {
        string res;
        if(numbers.size() <= 0)
            return res;
        vector<string> strNum;
        for(int i=0;i<numbers.size();i++ ){
            stringstream ss;
            ss << numbers[i];
            string s = ss.str();
            strNum.push_back(s);
        }
        sort(strNum.begin(),strNum.end(),compare);
        
        for(int i=0;i<strNum.size();i++){
            res.append(strNum[i]);
        }
        return res;       
    }
};
