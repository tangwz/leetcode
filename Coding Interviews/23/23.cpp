/**
 * 二叉搜索树的后序遍历序列：http://www.nowcoder.com/books/coding-interviews/a861533d45854474ac791d90e447bafd?rp=1
 *
 * 输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。
 * 如果是则输出Yes,否则输出No。假设输入的数组的任意两个数字都互不相同。
 */

class Solution {
    bool verify(vector<int>& a, int l, int r){
        if(l >= r) return true;
        int i = r;
        while(i > l && a[i - 1] > a[r]) --i;
        for(int j = i - 1; j >= l; --j) if(a[j] > a[r]) return false;
        return verify(a, l, i - 1) && verify(a, i, r - 1);
    }
    
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
        if(sequence.size() == 0) return false;
        return verify(sequence, 0, sequence.size() - 1);
    }
};