//借鉴博客：http://blog.csdn.net/geekmanong/article/details/50419323
class Solution {
public:
    TreeNode *mistake1, *mistake2, *pre;
    void dfs(TreeNode *root)
    {
        if(!root) return ;
        dfs(root->left);
        if(pre && pre->val > root->val)
        {
            if(mistake1 == NULL)
            {
                mistake1 = pre;
                mistake2 = root;
            }
            else mistake2 = root;
        }
        pre = root;
        dfs(root->right);
    }
    void recoverTree(TreeNode* root) {
        mistake1 = mistake2 = NULL;
        dfs(root);
        if(mistake1 && mistake2) swap(mistake1->val, mistake2->val);
    }
};