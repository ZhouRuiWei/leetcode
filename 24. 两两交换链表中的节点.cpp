/*给定一个链表，两两交换其中相邻的节点，并返回交换后的链表。

示例:

给定 1->2->3->4, 你应该返回 2->1->4->3.

说明:

    你的算法只能使用常数的额外空间。
    你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。
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
    ListNode* swapPairs(ListNode* head) {
        if(!head)
            return NULL;
        if(!(head->next))
            return head;
        ListNode*t = head->next;
        head->next = t->next;
        t->next = head;
        head = t;
        t = t->next;// the first two node;

        if(!(t->next) || !(t->next->next))// the two node after t is the two we need to change;
            return head;
        while(t->next && t->next->next)
        {
            ListNode*tt = t->next;
            t->next = t->next->next;
            tt->next = t->next->next;
            t = t->next;
            t->next = tt;
            t = t->next;
        }
        return head;
    }
};