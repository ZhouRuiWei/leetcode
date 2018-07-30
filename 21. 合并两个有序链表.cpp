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
};




class Solution {
public:
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
};