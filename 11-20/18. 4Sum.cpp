//详见3Sum
class Solution {
public:
    vector<vector<int>> ans;
    vector<int> cur;
    void two_sum(int l, int r, vector<int> &nums, int target, int i, int j)
    {
        while(l < r)
        {
            if(nums[i]+nums[j]+nums[l]+nums[r] == target)
            {
                cur.clear();
                cur.push_back(nums[i]); cur.push_back(nums[j]);
                cur.push_back(nums[l]); cur.push_back(nums[r]);
                ans.push_back(cur);
                while(l < r && nums[l+1] == nums[l]) l++;
                while(l < r && nums[r-1] == nums[r]) r--;
                l++;
                r--;
            }
            else if(nums[i]+nums[j]+nums[l]+nums[r] < target) l++;
            else r--;
        }
    }
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i++)
        {
            if(i > 0 && nums[i] == nums[i-1]) continue;
            for(int j = i+1; j < nums.size(); j++)
            {
                if(j > i+1 && nums[j] == nums[j-1]) continue;
                two_sum(j+1, nums.size()-1, nums, target, i, j);
            }
        }
        return ans;
    }
};
