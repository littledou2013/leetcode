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
    bool isBalanced(TreeNode *root) {
        /*
         * 最笨的方法：比较左右子树的高度，首先需要计算左右子树的高度
         * 个人认为这种方法存在重复计算，时间复杂度为O(nlogn)。
         */
        if (root == NULL)
            return true;
        if (abs(getHeight(root->left) - getHeight(root->right)) > 1)
            return false;
        else
            return(isBalanced(root->left) && isBalanced(root->right));
        
        
    }
    int getHeight(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        else
            return max(getHeight(root->left), getHeight(root->right)) + 1;
    }
    
};
