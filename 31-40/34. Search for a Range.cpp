//STL lower_bound 和 upper_bound的运用哈~，找不到返回的是end()位置
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        ans.push_back(-1);
        ans.push_back(-1);
        int s = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        int e = upper_bound(nums.begin(), nums.end(), target) - nums.begin();
        if(s >= nums.size()) return ans;
        if(nums[s] == target)
        {
            ans.clear();
            ans.push_back(s);
            ans.push_back(e-1);
        }
        return ans;
    }
};