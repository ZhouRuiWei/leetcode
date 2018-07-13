/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
    public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        int temp,x = 0,y = 0;
        int a = 1;
        int b = 1;
        while(!l1)
        {
            temp = l1->val;
            x = x + temp*a;
            l1 = l1->next;
            a = a*10;
        }
        while(!l2)
        {
            temp = l2->val;
            y = y + temp *b;
            l2 = l2->next;
            b = b*10;
        }
        int result = x + y;
        ListNode * l3 = (ListNode*)malloc(sizeof(ListNode));
        ListNode * l4 = l3;
        ListNode *s;
        while(result)
        {
            temp = result % 10;
            result = result/10;
            s = (ListNode*)malloc(sizeof(ListNode));
            s -> val = temp;
            l3->next = s;
            l3 = s;
        }
        l3->next = NULL;
        return l4;
    }
};
// leet code 
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *hn=NULL,*t,*p,*q;
        int cin=0,sum;

        //只要没有完全遍历完，就继续遍历
        for(p=l1,q=l2;p || q || cin;)// ||cin, in case of 99+1 = 100; then cin = 1, a longer size
        {

            sum=(p?p->val:0) + (q?q->val:0)+cin;
            cin=sum/10;//over 10,
            if(!hn)
            {
                hn=t=(ListNode*)malloc(sizeof(ListNode));// create new node
            }
            else
            {
                t=t->next=(ListNode*)malloc(sizeof(ListNode));
            }
            t->next=NULL;
            t->val=sum%10;// the result of this node

            p=p?p->next:p;// go to next 
            q=q?q->next:q;
        }

        return hn;
    }
};