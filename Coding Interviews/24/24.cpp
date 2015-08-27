/**
 * 二叉树中和为某一值的路径: http://www.nowcoder.com/books/coding-interviews/b736e784e3e34731af99065031301bca?rp=1
 *
 * 输入一颗二叉树和一个整数，打印出二叉树中结点值的和为输入整数的所有路径。
 * 路径定义为从树的根结点开始往下一直到叶结点所经过的结点形成一条路径。
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
    vector<vector<int>> res;
    vector<int> tmp;
    void dfs(TreeNode* node, int leave){
        tmp.push_back(node->val);
        // 叶子节点，且路径和恰为所求
        if(leave - node->val == 0 && !node->left && !node->right)
            res.push_back(tmp);
        else{
            if(node->left) dfs(node->left, leave - node->val);
            if(node->right) dfs(node->right, leave - node->val);
        }
        tmp.pop_back();
    }
public:
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
        if(root){
            dfs(root, expectNumber);
        }
        return res;
    }
};