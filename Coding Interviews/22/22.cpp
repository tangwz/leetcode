/**
 * 从上往下打印二叉树：http://www.nowcoder.com/books/coding-interviews/7fe2212963db4790b57431d9ed259701?rp=1
 *
 * 从上往下打印出二叉树的每个节点，同层节点从左至右打印。
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
    vector<int> PrintFromTopToBottom(TreeNode *root) {
        vector<int> res;
        if(!root)
            return res;
        vector<TreeNode *> tmp;
        tmp.push_back(root);
        int p = 0;
        while(p < tmp.size()){
            TreeNode *t = tmp[p++];
            if(t->left) tmp.push_back(t->left);
            if(t->right) tmp.push_back(t->right);
            res.push_back(t->val);
        }
        return res;
    }
};


// 也可以使用队列实现
class Solution {
public:
    vector<int> PrintFromTopToBottom(TreeNode *root) {
        vector<int> res;
        if(!root)
            return res;
        deque<TreeNode *> d;
        d.push_back(root);
        while(d.size()){
            TreeNode *t = d.front();
            d.pop_front();
            if(t->left) d.push_back(t->left);
            if(t->right) d.push_back(t->right);
            res.push_back(t->val);
        }
        return res;
    }
};