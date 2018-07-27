/*
给定一个二叉树，判断它是否是高度平衡的二叉树。

本题中，一棵高度平衡二叉树定义为：

    一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过1。

示例 1:

给定二叉树 [3,9,20,null,null,15,7]

    3
   / \
  9  20
    /  \
   15   7

返回 true 。

示例 2:

给定二叉树 [1,2,2,3,3,null,null,4,4]

       1
      / \
     2   2
    / \
   3   3
  / \
 4   4

返回 false 。
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

// cut the rest of judgements if one of its child is not balance and return -1
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(!root)
            return 0;
        int m = maxDepth(root->left);
        if(m == -1)
            return -1;
        int n = maxDepth(root->right);
        if(n == -1)
            return -1;
        if(abs(m-n) > 1)
            return -1;
        return max(m,n)+1;
    }

    bool isBalanced(TreeNode* root) {
        if(!root)
            return true;
        if(maxDepth(root) == -1)
            return false;
        else
            return true;
    }
};