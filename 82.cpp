/*
给定一个排序链表，删除所有含有重复数字的节点，只保留原始链表中 没有重复出现 的数字。

示例 1:

输入: 1->2->3->3->4->4->5
输出: 1->2->5

示例 2:

输入: 1->1->1->2->3
输出: 2->3


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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head)
            return NULL;
        ListNode* p = NULL;
        ListNode*q = head->next;
        p = (ListNode*)malloc(sizeof(ListNode));
        p->next = head;
        ListNode*pre = p;// the node before head;
        int cnt = 1;
        while(q)
        {
            if(q->val == head->val)
            {
                cnt++;
                q = q->next;
            }
            else
            {
                if(cnt == 1)
                {
                    pre = head;
                    head = q;
                    q = q->next;
                    cnt = 1;
                }
                else
                {
                    pre->next = q;
                    head = q;
                    q = q->next;
                    cnt = 1;
                }

            }
        }
        if(cnt != 1)// be careful of the last node
            pre->next = NULL;
        return p->next;
    }
};

// use a map;
/*

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *p = NULL, *t;
        map<int,int> a;
        while(head)
        {
            auto ret = a.insert({head->val,1});
            if(!ret.second)// if val exists, then ++, else insert it into the map;
                (ret.first->second)++;
            head = head->next;
        }
        auto c = a.cbegin();
        while(c!= a.cend())
        {
            if(c->second == 1)
            {
                if(!p)
                {
                    p=t=(ListNode*)malloc(sizeof(ListNode));// create new node
                }
                else
                {
                    t=t->next=(ListNode*)malloc(sizeof(ListNode));
                }
                t->val = c->first;
                t->next = NULL;
            }
            c++;
        }
    return p;
    }
};

*/