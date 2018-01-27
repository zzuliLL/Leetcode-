//和82题差不多哈
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *p, *q, *c;
        p = head;
        if(p&&p->next) q = p->next;
        else return head;
        p->next = NULL;
        while(q)
        {
            if(p->val == q->val)
            {
                c = q;
                q = q->next;
                free(c);
            }
            else
            {
                p->next = q;
                p = q;
                q = q->next;
                p->next = NULL;
            }
        }
        return head;
    }
};