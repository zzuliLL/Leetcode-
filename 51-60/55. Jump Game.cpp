//简单遍历下
class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size() <= 1) return true;
        int s = 0, n = nums.size()-1;
        while(true)
        {
            int l, r;
            l = s; r = s+nums[s];
            if(l == r) return false;
            if(r >= n) return true;
            for(int i = l+1; i <= r; i++) s = s+nums[s] > i+nums[i] ? s : i;
        }
    }
};