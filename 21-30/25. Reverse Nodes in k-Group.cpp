//栈的合理运用
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        stack<ListNode*> s;
        ListNode *L = new ListNode(0), *p, *q, *x;
        p = L;
        p->next = head;
        q = head;
        while(q)
        {
            x = q;
            for(int i = 1; i <= k; i++)
            {
                s.push(q);
                q = q->next;
                if(!q) break;
            }
            if(s.size() == k)
            {
                while(!s.empty())
                {
                    ListNode *cur = s.top();
                    s.pop();
                    p->next = cur;
                    p = cur;
                }
                p->next = NULL;
            }
            else
            {
                p->next = x;
                break;
            }
        }
        head = L->next;
        free(L);
        return head;
    }
};