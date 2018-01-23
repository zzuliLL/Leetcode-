//简单dp
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = nums[0];
        int dp = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            if(dp + nums[i] < 0) dp = max(nums[i], 0);
            else dp += nums[i];
            if(dp) ans = max(ans, dp);
            else ans = max(ans, nums[i]);            
        }
        return ans;
    }
};
