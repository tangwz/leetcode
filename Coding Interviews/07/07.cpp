/******************************************************************************
 * 重建二叉树：http://www.nowcoder.com/books/coding-interviews/8a19cbe657394eeaac2f6ea9b0f6fcf6?rp=1
 *
 * 输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。
 * 假设输入的前序遍历和中序遍历的结果中都不含重复的数字。
 * 例如输入前序遍历序列{1,2,4,7,3,5,6,8}和中序遍历序列{4,7,2,1,5,3,8,6}，
 * 则重建二叉树并返回。
 */

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    struct TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> in) {
        int inLen = in.size();
        if(inLen == 0){
            return NULL;
        }
        //首先，根节点肯定是前序遍历的第一个数
        TreeNode* root = new TreeNode(pre[0]);
        //找到中序遍历根节点所在位置,存放于变量rootValue中
        int rootInorder = 0;
        for(int i = 0; i < inLen; ++i){
            if(in[i] == pre[0]){
                rootInorder = i;
                break;
            }
        }
        //对于中序遍历，根节点左边的节点位于二叉树的左边，根节点右边的节点位于二叉树的右边
        //利用上述这点，对二叉树节点进行递归
        vector<int> left_pre,right_pre,left_in,right_in;
        for(int i=0;i < rootInorder; i++)
        {
            left_in.push_back(in[i]);
            left_pre.push_back(pre[i+1]);//前序第一个为根节点
        }
        for(int i = rootInorder + 1; i < inLen; i++)
        {
            right_in.push_back(in[i]);
            right_pre.push_back(pre[i]);
        }
        root->left=reConstructBinaryTree(left_pre,left_in);
        root->right=reConstructBinaryTree(right_pre,right_in);
        return root;
        
    }
};