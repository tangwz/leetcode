/**
 * 二叉树的深度：http://www.nowcoder.com/practice/435fb86331474282a3499955f0a41e8b?rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
 *
 * 输入一棵二叉树，求该树的深度。从根结点到叶结点
 * 依次经过的结点（含根、叶结点）形成树的一条路径，
 * 最长路径的长度为树的深度。
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
    int TreeDepth(TreeNode* pRoot)
    {
    	if(pRoot == NULL)
            return 0;
        // 不是我想用这种拙劣的变量名，而是nLeft这样的OJ都不给过
        int zuo = TreeDepth(pRoot->left);
        int you = TreeDepth(pRoot->right);
        
        return (zuo > you) ? (zuo + 1) : (you + 1);
    }
};