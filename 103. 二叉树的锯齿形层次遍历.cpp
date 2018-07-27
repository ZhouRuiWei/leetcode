/*
给定一个二叉树，返回其节点值的锯齿形层次遍历。
（即先从左往右，再从右往左进行下一层遍历，以此类推，层与层之间交替进行）。
例如：
给定二叉树 [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7

返回锯齿形层次遍历如下：

[
  [3],
  [20,9],
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
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(!root) 
            return result;
        deque<TreeNode*> q;
        TreeNode* p;
        q.push(root);
        int i = 0;
        while(!q.empty())
        {
            int count = q.size();
            vector<int> single;
            i++;
            while(count--)
            {
                if(i%2 == 0)
                {
                    p = q.front();
                    single.push_back(p->val);
                    q.pop_front();
                    if(p->left)
                        q.push_back(p->left);
                    if(p->right)
                        q.push_back(p->right);
                }
                if(i%2 == 1)
                {
                    p = q.back();
                    single.push_back(p->val);
                    q.pop_back();
                    if(p->right)
                        q.push_front(p->right);
                    if(p->left)
                        q.push_front(p->left);
                }                
            }
            result.push_back(single);
        }
        return result;
    }
};


class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
       vector<vector<int>> res;
       if (!root) return res;

       queue<TreeNode *> que;
       que.push(root);
       bool left_to_right = 1;

       while (!que.empty()) {
           vector<int> tmp(que.size());

           size_t n = que.size();
           for (size_t i = 0; i < n; ++i) {
               TreeNode *cur = que.front(); que.pop();

               int index = left_to_right ? i : n - i - 1;
               tmp[index] = cur->val;

               if (cur->left) que.push(cur->left);
               if (cur->right) que.push(cur->right);
           }

           left_to_right = !left_to_right;
           res.push_back(std::move(tmp));
       }

       return res;        
    }
};