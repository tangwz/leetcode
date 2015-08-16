/**
 * 树的子结构：http://www.nowcoder.com/books/coding-interviews/6e196c44c7004d15b1610b9afca8bd88?rp=1
 *
 * 输入两颗二叉树A，B，判断B是不是A的子结构。
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
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
        bool res = false;
        
        if(pRoot1 != NULL && pRoot2 != NULL){
            if(pRoot1->val == pRoot2->val)
                res = DoesSubTree(pRoot1, pRoot2);
            if(!res)
                res = HasSubtree(pRoot1->left, pRoot2);
            if(!res)
                res = HasSubtree(pRoot1->right, pRoot2);
        }
        
        return res;
    }
    
    bool DoesSubTree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
        /* 这个边界情况值得注意！ */
        if(pRoot2 == NULL)
            return true;
        
        if(pRoot1 == NULL)
            return false;
        
        if(pRoot1->val != pRoot2->val)
            return false;
        
        return DoesSubTree(pRoot1->left, pRoot2->left) && DoesSubTree(pRoot1->right, pRoot2->right);
    }
};

/***************************************
网上看到的更有的解法，确实比书上好太多！

class Solution {
    bool isSubtree(TreeNode* pRootA, TreeNode* pRootB) {
        if (pRootB == NULL) return true;
        if (pRootA == NULL) return false;
        if (pRootB->val == pRootA->val) {
            return isSubtree(pRootA->left, pRootB->left)
                && isSubtree(pRootA->right, pRootB->right);
        } else return false;
    }
public:
    bool HasSubtree(TreeNode* pRootA, TreeNode* pRootB)
    {
        if (pRootA == NULL || pRootB == NULL) return false;
        return isSubtree(pRootA, pRootB) ||
            HasSubtree(pRootA->left, pRootB) ||
            HasSubtree(pRootA->right, pRootB);
    }
};
***************************************/