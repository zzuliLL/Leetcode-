//分类二分 6ms
class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.size() == 0) return -1;
        int k = -1;
        for(int i = 1; i < nums.size(); i++)
        {
            if(nums[i] > nums[i-1]) continue;
            k = i;
            break;
        }
        if(k == -1)
        {
            int s = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
            if(nums[s] == target) return s;
            return -1;
        }

        if(target < nums[0])
        {
            int s = lower_bound(nums.begin()+k, nums.end(), target) - nums.begin();
            if(nums[s] == target) return s;
            return -1;
        }
        int s = lower_bound(nums.begin(), nums.begin()+k, target)-nums.begin();
        if(nums[s] == target) return s;
        return -1;
    }
};

//暴力 9ms
class Solution {
public:
    int search(vector<int>& nums, int target) {
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] == target) return i;
        }
        return -1;            
    }
};
