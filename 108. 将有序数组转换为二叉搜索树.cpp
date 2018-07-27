/*
给定一个二叉树，返回其节点值自底向上的层次遍历。 （即按从叶子节点所在层到根节点所在的层，逐层从左向右遍历）

例如：
给定二叉树 [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7

返回其自底向上的层次遍历为：

[
  [15,7],
  [9,20],
  [3]
]

*/


class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> level_num;
        if(!root) return level_num;
        queue<TreeNode*> q;
        TreeNode* p;
        q.push(root);
        while(!q.empty()){
            int count = q.size();
            vector<int> single_num;
            while(count--){
                p = q.front();
                single_num.push_back(p->val);
                q.pop();
                if(p->left) q.push(p->left); 
                if(p->right) q.push(p->right); 
            }
            level_num.push_back(single_num);
        }
        reverse(level_num.begin(),level_num.end);
        return level_num;
    }
};