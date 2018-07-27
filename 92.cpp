/*

反转从位置 m 到 n 的链表。请使用一趟扫描完成反转。

说明:
1 ≤ m ≤ n ≤ 链表长度。

示例:

输入: 1->2->3->4->5->NULL, m = 2, n = 4
输出: 1->4->3->2->5->NULL


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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode*pre,*p,*q,*qq = NULL;
        ListNode*r;

        pre = (ListNode*)malloc(sizeof(ListNode));
        pre->next = head;

        if(m == n)
            return head;
        if(!head)
            return NULL;
        ListNode*t = head;
        int i = 1;
        while(t)
        {
            if(i == m-1)// be careful of m = 1;
                pre = t;
            if(i == m)
            {
                p = t;            }
            if(i == n+1)
            {
                qq = t;
                break;
            }
            i++;
            t = t->next;
        }
        if(p)
        {
            q = p->next;
            p->next = qq;
        }
        while(q && q != qq)
        {
            r = q->next;
            q->next = p;
            p = q;
            q = r;
        }
        if(pre)
            pre->next = p;
        if(m==1)//be careful of m = 1;
            return pre->next;
        else
            return head;
    }
};