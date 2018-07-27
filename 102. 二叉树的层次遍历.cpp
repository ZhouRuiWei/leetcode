/*
给定一个二叉树，返回其按层次遍历的节点值。 （即逐层地，从左到右访问所有节点）。

例如:
给定二叉树: [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7

返回其层次遍历结果：

[
  [3],
  [9,20],
  [15,7]
]


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

// like the bfs, but need two queues
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        std::vector<std::vector<int> > result;
        std::vector<int> tmp;
        queue<TreeNode *> cur;
        queue<TreeNode *> next;
        if(!root)
            return result;
        cur.push(root);
        while(!cur.empty() || !next.empty())
        {
            TreeNode*p = cur.front();
            tmp.push_back(p->val);
            cur.pop();
            if(p->left)
                next.push(p->left);
            if(p->right)
                next.push(p->right);
            if(cur.empty())
            {
                cur = next;
                queue<TreeNode*> empty;
                std::swap(next, empty );
                result.push_back(tmp);
                tmp.erase(tmp.begin(),tmp.end());
            }
        }


    return result; 
    }
};


/*
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
        return level_num;
    }
};