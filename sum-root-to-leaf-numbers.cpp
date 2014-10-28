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
    int sumNumbers(TreeNode *root) {
        sum = 0;
        if (root != NULL)
            sumPath(root, 0);
        return sum;
    }
private:
    int sum;
    void sumPath(TreeNode *root, int path)
    {
        /*
         * 深度优先搜索，搜索过程中计算路径所表示的值
         */
        path = path * 10 + root->val;
        if (root->left == NULL && root -> right == NULL)
            sum += path;
        else
        {
            if (root->left != NULL)
                sumPath(root->left, path);
            if (root->right != NULL)
                sumPath(root->right, path);
           
        }
         path /= 10;
    }
};
