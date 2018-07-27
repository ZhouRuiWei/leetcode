/*
给定一个链表和一个特定值 x，对链表进行分隔，使得所有小于 x 的节点都在大于或等于 x 的节点之前。

你应当保留两个分区中每个节点的初始相对位置。

示例:

输入: head = 1->4->3->2->5->2, x = 3
输出: 1->2->2->4->3->5

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
    ListNode* partition(ListNode* head, int x) 
    {
        ListNode*hn=NULL;
        ListNode *p = head;
        ListNode*t;
        while(p)
        {
        if(p->val < x)
        {
            if(!hn)
            {
                hn=t=(ListNode*)malloc(sizeof(ListNode));// create new node
            }
            else
            {
                t=t->next=(ListNode*)malloc(sizeof(ListNode));
            }
            t->next=NULL;
            t->val = p->val;
        }
        p = p->next;
        }



        p = head;
        while(p)
        {
        if(p->val >= x)
        {
            if(!hn)
            {
                hn=t=(ListNode*)malloc(sizeof(ListNode));// create new node
            }
            else
            {
                t=t->next=(ListNode*)malloc(sizeof(ListNode));
            }
            t->next=NULL;
            t->val = p->val;
        }
        p = p->next;
        }

        return hn;
    }
};