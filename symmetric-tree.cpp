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
    bool isSymmetric(TreeNode *root) {
        /* 左中右和有种做的中序遍历是一样的结果
         *
         */
        if (root == NULL)
            return true;
        else 
            return isS(root->left, root->right);
        
    }
    bool isS(TreeNode *left, TreeNode *right)
    {
        if (left == NULL && right == NULL)
            return true;
        else if (left == NULL || right == NULL)
            return false;
        else if (left->val != right->val)
            return false;
        else
            return (isS(left->left, right->right) && isS(left->right, right->left));
        
    }
};
