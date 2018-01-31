//与96题很像，借鉴博客:http://blog.csdn.net/chilseasai/article/details/50083201
class Solution {
public:
    vector<TreeNode*> dfs(int l, int r)
    {
        if(l > r) return {NULL};
        vector<TreeNode*> res, L, R;
        for(int i = l; i <= r; i++)
        {
            L = dfs(l, i-1);
            R = dfs(i+1, r);
            for(auto lchild : L)
            {
                for(auto rchild : R)
                {
                    TreeNode *root = new TreeNode(i);
                    root->left = lchild;
                    root->right = rchild;
                    res.push_back(root);
                }
            }
        }
        return res;
    }
    vector<TreeNode*> generateTrees(int n) {
        if(n < 1) return {};
        return dfs(1, n);
    }
};