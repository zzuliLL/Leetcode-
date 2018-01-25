//暴力写的，这里需要注意remove和erase的区别，erase是真的删除，而remove是把要删除的元素放在了最前面
class Solution {
public:
    vector<vector<int>> ans;
    void dfs(int cur, int n, int k, vector<int> &x)
    {
        if(x.size() == k)
        {
            ans.push_back(x);
            return ;
        }
        for(int i = cur+1; i <= n; i++)
        {
            x.push_back(i);
            dfs(i, n, k, x);
            x.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> x;
        dfs(0, n, k, x);
        return ans;
    }
};