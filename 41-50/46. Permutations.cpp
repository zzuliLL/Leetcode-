//STL
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        do
        {
            ans.push_back(nums);
        }while(next_permutation(nums.begin(), nums.end()));
        return ans;
    }
};

//手敲的dfs
class Solution
{
public:
    void dfs(vector<int> &nums, int cur, int n)
    {
        if(cur == n) 
        {
            ans.push_back(nums);
            return ;
        }
        for(int i = cur; i <= n; i++)
        {
            swap(nums[i], nums[cur]);
            dfs(nums, cur+1, n);
            swap(nums[i], nums[cur]);
        }
    }
    vector<vector<int>> ans;
    vector<vector<int>> permute(vector<int>& nums)
    {
        sort(nums.begin(), nums.end());
        dfs(nums, 0, nums.size()-1);
        return ans;
    }
};