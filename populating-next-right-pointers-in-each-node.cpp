/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (root != NULL)
        {
            root -> next = NULL;
            con(root);
        }
    }
    /*
     * 感觉自己做这些题目都是晕乎乎的
     */
    void con(TreeLinkNode *root)
    {
        if (root -> left != NULL)
        {   
            root-> left -> next = root -> right;
            con(root->left);
        }
        if (root -> right != NULL)
        {
            root -> right -> next = (root->next != NULL ? root->next -> left : NULL);
            con(root->right);
        }
    }
};
