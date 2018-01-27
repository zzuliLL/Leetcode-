//搜的时候就是选与不选，需要注意重复的元素，是选择一个还是多个，前面有类似的题，也是选择多个，不能重复的题，可以回头看看总结下哈
class Solution {
public:
    vector<vector<int>> ans;
    void dfs(vector<int> &nums, int l, int n, vector<int> &a)
    {
        if(l == n)
        {
            ans.push_back(a);
            return ;
        }
        int r = l;
        while(r < n && nums[r] == nums[l]) r++;
        dfs(nums, r, n, a);
        for(int i = l; i < r; i++)
        {
            a.push_back(nums[l]);
            dfs(nums, r, n, a);
        }
        for(int i = l; i < r; i++) a.pop_back(); 
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> a;
        dfs(nums, 0, nums.size(), a);
        return ans;
    }
};