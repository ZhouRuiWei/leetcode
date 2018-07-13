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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* l3 =NULL,*t,*p = l1,*q=l2;
        while(p || q)
        {
            if(!l3)
            {
                l3=t=(ListNode*)malloc(sizeof(ListNode));// create new node
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
};