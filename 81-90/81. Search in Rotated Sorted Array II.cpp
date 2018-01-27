//同33. Search in Rotated Sorted Array
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if(nums.size() == 0) return false;
        int p = 1, len = nums.size();
        while(p < len)
        {
            if(nums[p] < nums[p-1]) break;
            p++;
        }
        if(target >= nums[0] && target <= nums[p-1]) return *lower_bound(nums.begin(), nums.begin()+p, target) == target;
        if(p < len && target >= nums[p] && target <= nums[len-1]) return *lower_bound(nums.begin()+p, nums.end(), target) == target;
        return false;
    }
};