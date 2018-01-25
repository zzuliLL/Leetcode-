//同上一题，直接暴力搜索下即可
class Solution {
public:
    vector<vector<int>> ans;
    void dfs(int cur, int n, vector<int> &nums, vector<int> x)
    {
        if(cur == n)
        {
            ans.push_back(x);
            return ;
        }
        dfs(cur+1, n, nums, x);
        x.push_back(nums[cur]);
        dfs(cur+1, n, nums, x);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> x;
        dfs(0, nums.size(), nums, x);
        return ans;
    }
};