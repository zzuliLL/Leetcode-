//按照要求遍历一遍就好了，依次从m到n，把所有元素放到n的后面。
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(!head||!head->next) return head;
        int i = 1;
        ListNode *p = new ListNode(0), *M, *N, *nx, *L;
        p->next = M = N = head;
        L = p;
        while(i < n)
        {
            if(i < m)
            {
                p = M;
                M = M->next;
            }
            N = N->next;
            i++;
        }
        ListNode *nxx = N->next;
        while(M != N)
        {
            nx = M->next;
            M->next = nxx;
            nxx = M;
            M = nx;
        }
        M->next = nxx;
        p->next = M;
        head = L->next;
        free(L);
        return head;
    }
};