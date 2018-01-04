//һ����ָ�룬һ����ָ�룬�ÿ������n-1�£�Ȼ������ָ��һ���ܣ���ָ��Ϊ���һ��ʱ����ָ�����Ҫɾ����Ԫ�ع���ע��߽�Ϳ���AC��

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
