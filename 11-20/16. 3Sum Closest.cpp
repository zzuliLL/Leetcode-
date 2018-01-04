//和15一样的思路
class Solution {
public:
    int Two_sum(int l, int r, int target, vector<int> &nums, int i) {
        vector<int> s;
        int ans, f = 0;
        while(l < r)
        {
            if(nums[l] + nums[r] == target) return target + nums[i];
            else if(nums[l] + nums[r] < target)
            {
                if(!f || abs(target - nums[l] - nums[r]) < abs(target - ans)) f = 1, ans = nums[l] + nums[r];
                l++;
            }
            else
            {
                if(!f || abs(target - nums[l] - nums[r]) < abs(target - ans)) f = 1, ans = nums[l] + nums[r];
                r--;
            }
        }
        return ans + nums[i];
    }
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int ans, f = 0;
        for(int i = 0; i < nums.size()-2; i++)
        {
            if(i > 0 && nums[i] == nums[i-1]) continue;
            int cur = Two_sum(i+1, nums.size()-1, target - nums[i], nums, i);
            if(!f || abs(target - cur) < abs(target - ans)) f = 1, ans = cur;
        }
        return ans;
    }
};
