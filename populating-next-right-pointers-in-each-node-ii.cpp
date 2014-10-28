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
        /* 迷迷糊糊就按层次遍历得了
         */
        //首先找到root下层中第一个元素,找到在root层中第一个具有子节点的元素 
        if (root != NULL)
        {
            root -> next = NULL;
            con(root);
        }
    }
    void con(TreeLinkNode *root)
    {
        TreeLinkNode *parent = root;
        while (parent != NULL && (parent -> left == NULL && parent -> right == NULL))
            parent = parent -> next;
        if (parent == NULL)
            return;
        TreeLinkNode *first;
        if (parent -> left != NULL)
            first = parent -> left;
        else
            first = parent -> right;
        TreeLinkNode *next;
        while (parent != NULL)
        {
            if (parent -> left != NULL)
            {
                if (parent ->right != NULL)
                    parent -> left -> next = parent -> right;
                else
                {
                    next = parent->next;
                    while (next != NULL && (next -> left == NULL && next -> right == NULL))
                        next = next -> next;
                    parent -> left -> next = (next == NULL ? NULL : (next -> left == NULL ? next-> right : next -> left));
                }
            }
            if (parent -> right != NULL)
            {
                next = parent->next;
                while (next != NULL && (next -> left == NULL && next -> right == NULL))
                    next = next -> next;
                parent -> right -> next = (next == NULL ? NULL : (next -> left == NULL ? next-> right : next -> left));
            }
            parent = next;
        }
        con(first);
    }
        
        
        
};
