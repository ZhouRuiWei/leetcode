/*删除链表中等于给定值 val 的所有节点。

示例:

输入: 1->2->6->3->4->5->6, val = 6
输出: 1->2->3->4->5

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
    ListNode* removeElements(ListNode* head, int val) {
        while(head != NULL&&head->val == val)
            head = head->next;
        if(head == NULL) 
            return head;
        ListNode* p = head;
        while(p->next != NULL)
        {
            if(p->next->val == val) 
                p->next = p->next->next;
            else
                p = p->next;
        }
        return head;
    }
};