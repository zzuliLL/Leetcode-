//遍历一遍就好了
class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size() <= 1) return 0;
        int ans = 1, d = 0, r;
        while(d + nums[d] < nums.size()-1)
        {
            r = -1;
            for(int i = d+1; i <= d+nums[d]; i++)
                if(r == -1 || r + nums[r] < i + nums[i]) r = i;
            d = r;
            ans++;
        }
        return ans;
    }
};