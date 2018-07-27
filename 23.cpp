/*合并 k 个排序链表，返回合并后的排序链表。请分析和描述算法的复杂度。

示例:

输入:
[
  1->4->5,
  1->3->4,
  2->6
]
输出: 1->1->2->3->4->4->5->6
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* l3 =NULL,*t;//l3 is the result, t is the moving pointer of l3
        while(!lists.empty())
        // even if we have come to the last one, there is still a struct in the lists,so it is not empty
        {
            int m = 123456;
            auto min_itr = lists.begin();
            for(auto itr = lists.begin();itr != lists.end();)
            {
                if(!(*itr))
                {
                    itr = lists.erase(itr);
                    continue;
                }
                else
                {
                    if(m > (*itr)->val)
                    {
                        m = (*itr)->val;
                        min_itr = itr;
                    }
                    itr++;
                }
            }
            if(m==123456)// to address the last one
                break;
            if(!l3)
            {
            // create new node, t is the moving pointer,l3 is the result
                l3=t=(ListNode*)malloc(sizeof(ListNode));
            }
            else
            {
                t=t->next=(ListNode*)malloc(sizeof(ListNode));
            }
            t-> val = m;
            t->next = NULL;
            (*min_itr) = (*min_itr)?(*min_itr)->next:(*min_itr);
        }
    return l3;
    }
};



// another faster method
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* l3 =NULL,*t,*p = l1,*q=l2;
        while(p || q)
        {
            if(!l3)
            {
                // create new node, t is the moving pointer,l3 is the result
                l3=t=(ListNode*)malloc(sizeof(ListNode));
            }
            else
            {
                t=t->next=(ListNode*)malloc(sizeof(ListNode));
            }
            if(!p)
            {
                t->val = q->val;
                t->next=NULL; // must add here
                q = q?q->next:q;
                continue;
            }
            if(!q)
            {
                t->val = p->val;
                t->next=NULL;
                p = p?p->next:p;
                continue;
            }

            if(p->val < q->val)
            {
                t->val = p->val;
                t->next=NULL;
                p = p?p->next:p;
            }
            else
            {
                t->val = q->val;
                t->next=NULL;
                q = q?q->next:q;
            }
        }
        return l3;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists)
    {
        if(lists.size()==0)
        {                //如果lists为空，那么返回NULL；
            return NULL;
        }
        ListNode*ans=lists[0];
        for(int i=1;i<lists.size();i++)
        {
            ans = mergeTwoLists(ans,lists[i]);           //处理所有的链表
        }
        return ans;

    }