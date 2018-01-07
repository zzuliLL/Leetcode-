//贼暴力的方法。。。
class Solution {
public:
    void dfs(int i, int len, vector<int> &nums, int target, int sum, vector<int> x)
    {
        if(i == len)
        {
            if(sum == target) ans.push_back(x);
            return ;
        }
        if(sum > target) return ;
        dfs(i+1, len, nums, target, sum, x);
        for(int j = 1; ; j++)
        {
            if(target < sum+nums[i]*j) break;
            x.push_back(nums[i]);
            dfs(i+1, len, nums, target, sum+nums[i]*j, x);
        }
    }
    vector<vector<int>> ans;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> x;
        dfs(0, candidates.size(), candidates, target, 0, x);
        return ans;
    }
};