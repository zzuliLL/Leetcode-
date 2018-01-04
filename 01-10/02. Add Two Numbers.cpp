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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *l = new ListNode(0), *o;
        o = l;
        int p = 0;
        while(l1&&l2)
        {
            int cur = l1->val + l2->val + p;
            ListNode *now = new ListNode(cur%10);
            o->next = now;
            o = now;
            p = cur / 10;
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1)
        {
            int cur = l1->val + p;
            ListNode *now = new ListNode(cur%10);
            o->next = now;
            o = now;
            p = cur / 10;
            l1 = l1->next;
        }
        while(l2)
        {
            int cur = l2->val + p;
            ListNode *now = new ListNode(cur%10);
            o->next = now;
            o = now;
            p = cur / 10;
            l2 = l2->next;
        }
        if(p)
        {
            ListNode *now = new ListNode(p);
            o->next = now;
        }
        return l->next;
    }
};
