//一个快指针，一个慢指针，让快的先跑n-1下，然后两个指针一起跑，快指针为最后一个时，慢指针就是要删除的元素哈，注意边界就可以AC了

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *low = head, *p = head, *fast = head;
        for(int i = 1; i < n; i++) fast = fast->next;
        while(fast->next)
        {
            fast = fast->next;
            p = low;
            low = low->next;
        }
        if(low == head)
        {
            head = head->next;
            free(p);
            return head;
        }
        if(n == 1)
        {
            p->next = NULL;
            free(fast);
            return head;
        }
        p->next = low->next;
        free(low);
        return head;
    }
};
