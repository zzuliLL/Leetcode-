//遍历一遍就好了
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if((p&&!q) || (!p&&q)) return false;
        if(p == q) return true;
        if(p->val != q->val) return false;
        if(!isSameTree(p->left, q->left)) return false;
        return isSameTree(p->right, q->right);
    }
};
