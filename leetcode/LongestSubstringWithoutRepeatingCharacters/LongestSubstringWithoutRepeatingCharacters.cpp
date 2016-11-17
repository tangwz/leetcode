// Author : Tangwz
// Date   : 2015-02-2

/**********************************************************************************
*
*Given a string, find the length of the longest substring without repeating characters.
*For example, the longest substring without repeating letters for "abcabcbb" is "abc",
*which the length is 3. For "bbbbb" the longest substring is "b", with the length of 1.
*
*Tags: Hash Table | Two Pointers | String
**********************************************************************************/

#include <iostream>

using std::string;


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
    }
};

int lengthOfLongestSubstring(string s) {
    int len =0;
    int pre =0;
    for(int i = 0;i < s.length();i++){
        int cur = 1;
        for(int j = i - 1;j >= i- pre;j--){
            if(s[j] == s[i])
                break;
            else
                cur++;
        }
        if(cur>len)
            len = cur;
        pre = cur;
    }
    return len;
    }


int main()
{
    //teat data
    string s0 = "";
    string s1 = "bbbbb";
    string s2 = "abcabcbb";
    string s3 = "acd";
    string s4 = "abcdabce";
    string s5 = "cdd";
    std::cout<<"this string should print 0"<<lengthOfLongestSubstring(s0)<<std::endl;
    std::cout<<"this string should print 1"<<lengthOfLongestSubstring(s1)<<std::endl;
    std::cout<<"this string should print 3"<<lengthOfLongestSubstring(s2)<<std::endl;
    std::cout<<"this string should print 5"<<lengthOfLongestSubstring(s4)<<std::endl;
    std::cout<<"this string should print 2"<<lengthOfLongestSubstring(s5)<<std::endl;
}
