//简单模拟下就好了，在纸上画画就出来了
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *p = new ListNode(0), *c, *q, *s;
        p->next = c = head;
        s = p;
        if(c&&c->next) q = c->next;
        else return head;
        p->next = NULL;
        while(q)
        {
            if(c->val == q->val)
            {
                while(q && c->val == q->val)
                {
                    free(c);
                    c = q;
                    q = q->next;
                }
                free(c);
                c = q;
            }
            else
            {
                p->next = c;
                p = c;
                p->next = NULL;
                c = q;
            }
            if(c) q = c->next;
        }
        if(c) p->next = c;
        return s->next;
    }
};