/**
 * 二叉树的镜像：http://www.nowcoder.com/books/coding-interviews/564f4c26aa584921bc75623e48ca3011?rp=1
 *
 * 操作给定的二叉树，将其变换为源二叉树的镜像。 
 * 输入描述:
 * 二叉树的镜像定义：源二叉树 
 *           8
 *          /  \
 *         6   10
 *        / \  / \
 *       5  7 9 11
 *       镜像二叉树
 *           8
 *          /  \
 *         10   6
 *        / \  / \
 *       11 9 7  5
 */

/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};*/
class Solution {
public:
    void Mirror(TreeNode *pRoot) {
        if(pRoot == NULL)
            return;
        if(pRoot->left == NULL && pRoot->right == NULL)
            return;
        
        /* 
         * 常规方法，使用递归
        TreeNode* tmp = pRoot->right;
        pRoot->right = pRoot->left;
        pRoot->left = tmp;
        
        if(pRoot->left)
            Mirror(pRoot->left);
        if(pRoot->right)
            Mirror(pRoot->right);
        */
        /* 不使用递归的解法 */
        stack<TreeNode *> s;
        TreeNode * tmp;
        s.push(pRoot);
        while(!s.empty()){
            TreeNode* pRoot = s.top();
            s.pop();
            tmp = pRoot->right;
            pRoot->right = pRoot->left;
            pRoot->left = tmp;
            if(pRoot->right)
                s.push(pRoot->right);
            if(pRoot->left)
                s.push(pRoot->left);
        }
    }
};