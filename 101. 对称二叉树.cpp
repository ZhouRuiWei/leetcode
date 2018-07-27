/*
给定一个二叉树，检查它是否是镜像对称的。

例如，二叉树 [1,2,2,3,4,4,3] 是对称的。

    1
   / \
  2   2
 / \ / \
3  4 4  3

但是下面这个 [1,2,2,null,3,null,3] 则不是镜像对称的:

    1
   / \
  2   2
   \   \
   3    3
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool symmetric(TreeNode* p, TreeNode *q)
    {
        if((!p&&q) ||(!q&&p))
            return false;
        if(!p && !q)
            return true;
        if(p->val != q->val)
            return false;
        else
            return symmetric(p->left,q->right) && symmetric(p->right,q->left);
    }
    bool isSymmetric(TreeNode* root) {
        if(root == NULL)
            return true;
        return symmetric(root->left,root->right);

        
    }
};