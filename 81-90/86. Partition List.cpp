//思路就是把链表中 >= x 的节点拉出来，然后再合并
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if(!head || !head->next) return head;
        ListNode *p = new ListNode(0), *q, *dx = new ListNode(0), *L, *dxx;
        L = p;
        p->next = q = head;
        dxx = dx;
        while(q)
        {
            if(q->val >= x)
            {
                dx->next = q;
                dx = q;
                q = q->next;
                p->next = q;
                dx->next = NULL;
                continue;
            }
            p = q;
            q = q->next;
        }
        p->next = dxx->next;
        head = L->next;
        free(dxx);
        free(L);
        return head;
    }
};