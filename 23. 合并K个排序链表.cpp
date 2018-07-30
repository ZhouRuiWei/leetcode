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
        if(l1==NULL || l2==NULL)
            return (l1==NULL ? l2: l1);
        if(l1->val < l2->val) 
        {
            l1->next=mergeTwoLists(l1->next, l2);
            return l1;
        }
        else
        {
            l2->next=mergeTwoLists(l1,l2->next);
            return l2;
        }
        
    }

    ListNode* mergeKLists(vector<ListNode*>& lists)
    {
        if(lists.size()==0)
            return NULL;
        ListNode*ans=lists[0];
        for(int i=1;i<lists.size();i++)
        {
            ans = mergeTwoLists(ans,lists[i]);           //处理所有的链表
        }
        return ans;

    }