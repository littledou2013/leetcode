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
    bool isSameTree(TreeNode *p, TreeNode *q) {
        /*
            跟判断是否对称树是一样的做法
        */
        if (p == NULL && q == NULL)
            return true;
        else if (p == NULL || q == NULL)
            return false;
        else if (p->val != q->val)
            return false;
        else 
            return (isSameTree(p->left, q->left) && isSameTree(p->right, q->right));
    }
};
