/*
 * 替换空格：http://www.nowcoder.com/books/coding-interviews/4060ac7e3e404ad1a894ef3e17650423?rp=1
 * 请实现一个函数，将一个字符串中的空格替换成“%20”。
 * 例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy
 */
class Solution {
public:
    /*
     * 一种简单的方法是从头到尾遍历，但是这样会覆盖后面的字符，所以不得不先后移后面的字符；
     * 这种方式的复杂度为O(n2)，不可取。
     * 于是选择从尾到头来修改。
     */
	void replaceSpace(char *str,int length) {
        if(length == 0){
            return ;
        }
        int i = 0;
        int space = 0;
        while(str[i] != '\0'){
            if(str[i] == ' '){
                ++space;
            }
            ++i;
        }
        int newLength = length + space * 2;
        
        int index1 = length - 1;
        int index2 = newLength - 1;
        while(index >= 0 && index2 > index1){
            if(str[index1] == ' '){
                str[index2--] = '0';
                str[index2--] = '2';
                str[index2--] = '%';
            }else{
                str[index2--] = str[index1];
            }
            --index1;
        }
        
	}
};