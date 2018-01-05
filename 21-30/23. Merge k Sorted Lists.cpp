//多个有序链表的合并，这个题貌似是zy学长在吃饭的时候教会我的，刚好用到这个题，复杂度O(n*log(k))，用优先队列去维护，这样贼快
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
    typedef pair<int, int> P;
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<P, vector<P>, greater<P> > q;
        int n = lists.size();
        for(int i = 0; i < n; i++)
        {
            if(lists[i])
            q.push(make_pair(lists[i]->val, i));
        }
        ListNode *L = new ListNode(0), *p;
        p = L;
        while(!q.empty())
        {
            P cur = q.top(); q.pop();
            int i = cur.second;
            p->next = lists[i];
            p = lists[i];
            lists[i] = lists[i]->next;
            if(lists[i]) q.push(make_pair(lists[i]->val, i));
        }
        return L->next;                
    }
};
