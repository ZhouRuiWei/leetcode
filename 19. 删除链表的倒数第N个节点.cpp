/*
给定一个链表，删除链表的倒数第 n 个节点，并且返回链表的头结点。

示例：

给定一个链表: 1->2->3->4->5, 和 n = 2.

当删除了倒数第二个节点后，链表变为 1->2->3->5.

说明：

给定的 n 保证是有效的。

进阶：

你能尝试使用一趟扫描实现吗？
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *p = head;
        ListNode *q = head;
        ListNode *pre = head;
        for(int i = 0; i != n; i++)
        {
            q = q->next;
        }
        if(!q)
            return head->next;
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



class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* end = head;
        ListNode* cur = head;
        for(int i = 1;i <= n;i++){
            end = end->next;
        }
        if(end == NULL)return head->next;
        while(end->next){
            end = end->next;
            cur = cur->next;
        }
        cur->next = cur->next->next;
        return head;
    }
}; 