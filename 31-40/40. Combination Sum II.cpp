//详见39题
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
        int l = i, r = i;
        while(r < len && nums[l] == nums[r]) r++;
        dfs(r, len, nums, target, sum, x);
        for(int j = 1; j <= r - l; j++)
        {
            x.push_back(nums[i]);
            dfs(r, len, nums, target, sum+nums[i]*j, x);
        }
    }
    vector<vector<int>> ans;
     vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> x;
        dfs(0, candidates.size(), candidates, target, 0, x);
        return ans;
    }
};
