//换一下啊
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
        ListNode *p, *q, *nx, *pre = new ListNode(0), *L;
        pre->next = head;
        L = pre;
        while(pre->next && pre->next->next)
        {
            p = pre->next;
            q = p->next;
            nx = q->next;
            pre->next = q;
            q->next = p;
            p->next = nx;
            pre = p;
        }
        head = L->next;
        free(L);
        return head;
    }
};