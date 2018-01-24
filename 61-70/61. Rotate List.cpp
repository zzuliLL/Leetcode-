//如果k大于链表长度时，应该旋转 k%len
//一个快指针，一个慢指针，快的指针比慢的先走k个，这样当快的指针走到NULL时，慢的刚好是倒数第k个
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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next) return head;
        ListNode *p, *q;
        p = q = head;
        int len = 0;
        while(p)
        {
            p = p->next;
            len++;
        }
        k %= len;
        if(k == 0) return head;
        p = head;
        while(p && k--)
        {
            p = p->next;
        }
        if(!p) return head;
        while(p->next)
        {
            p = p->next;
            q = q->next;
        }
        ListNode *cur = q->next;
        q->next = NULL;
        p->next = head;
        return cur;
    }
};