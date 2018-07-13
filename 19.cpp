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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *p = head;
        ListNode *q = head;
        ListNode *pre = head;
        for(int i = 0; i != n; i++)
            q = q->next;
        while(q)
        {
            pre = p;
            p = p->next;
            q = q->next;
        }
        //important!! if n is just the length of the link
        // then head should move on
        if(pre == p)
            head = head->next;
        else
            pre->next = pre->next->next;

        return head;
    }
};