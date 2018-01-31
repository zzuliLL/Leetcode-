//二叉搜索树中序遍历是有序的
class Solution {
public:
    void my_judge(TreeNode *root, vector<int> &s)
    {
         if(root)
         {
             my_judge(root->left, s);
             s.push_back(root->val);
             my_judge(root->right, s);
         }
    }
    bool isValidBST(TreeNode* root) {
        if(!root) return true;
        vector<int> s;
        my_judge(root, s);
        for(int i = 1; i < s.size(); i++)
        {
            if(s[i] <= s[i-1]) return false;
        }
        return true;
    }
};