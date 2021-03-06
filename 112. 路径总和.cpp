/*给定一个二叉树和一个目标和，判断该树中是否存在根节点到叶子节点的路径，这条路径上所有节点值相加等于目标和。

说明: 叶子节点是指没有子节点的节点。

示例: 
给定如下二叉树，以及目标和 sum = 22，

              5
             / \
            4   8
           /   / \
          11  13  4
         /  \      \
        7    2      1

返回 true, 因为存在目标和为 22 的根节点到叶子节点的路径 5->4->11->2。
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
    bool hasPathSum(TreeNode* root, int sum) {
        TreeNode *p;
        queue<TreeNode*> q;
        if(root = NULL)
            return false;
        q.push(root);
        while(!q.empty())
        {
            p = q.front();
            q.pop();
            if(p && p->val == sum && !p->left && !p->right)
                return true;

            if(p && p->left)
            {

                p->left->val = p->left->val + p->val;
                q.push(p->left);
            }
            if(p && p->right)
            {
                p->right->val = p->right->val + p->val;
                q.push(p->right);
            }

        }
        return false;

        
    }
};



//
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        TreeNode *p;
        queue<TreeNode*> q;
        if(!root)
            return false;
        if(!root->left && root->val==sum && !root->right)
            return true;
        return hasPathSum(root->left,sum-root->val) || hasPathSum(root->right,sum-root->val);
    }
};

