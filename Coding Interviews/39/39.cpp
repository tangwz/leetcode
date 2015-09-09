/**
 * 平衡二叉树：http://www.nowcoder.com/practice/8b3b95850edb4115918ecebdf1b4d222?rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
 *
 * 输入一棵二叉树，判断该二叉树是否是平衡二叉树。
 */
class Solution {
public:
    bool IsBalanced_Solution(TreeNode* pRoot) {
        int depth = 0;
        return isBalanced(pRoot, &depth);
    }
    
    bool isBalanced(TreeNode* pRoot, int* depth){
        if(pRoot == NULL){
            *depth = 0;
            return true;
        }
        
        int left, right;
        if(isBalanced(pRoot->left, &left) && isBalanced(pRoot->right, &right)){
            int diff = left - right;
            if(diff <= 1 && diff >= -1){
                *depth = 1 + (left > right ? left : right);
                return true;
            }
        }
        
        return false;
    }
};