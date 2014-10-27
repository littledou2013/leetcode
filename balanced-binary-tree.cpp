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
         * 个人认为这种方法存在重复计算，时间复杂度为O(nlogn)，对此进行优化。
         * 计算树的高度使用的深度优先的方式，也就是说最先算出高度的节点应该就是最低层的节点
         * 如果低层的节点都不满足平衡二叉树性质，那么上层节结点就绝对不会满足平衡二叉树性质。         
         */
        if (getHeight(root) == -1)
            return false;
        else
            return true;
        
        
    }
    int getHeight(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        int left = getHeight(root->left);
        if (left == -1)
            return -1;
        int right = getHeight(root->right);
        if (right == -1)
            return -1;
        else if (abs(left - right) > 1)
            return -1;
        else
            return max(left, right) + 1;
    }
    
};
