//模拟下，找第一个没有的正整数
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int *p = (int*)malloc(sizeof(int)*(nums.size()+1));
        memset(p, 0, sizeof(int)*(nums.size()+1));
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] <= 0 || nums[i] > nums.size()) continue;
            p[nums[i]] = 1;
        }
        for(int i = 1; i <= nums.size(); i++)
        {
            if(!p[i]) return i;
        }
        return nums.size()+1;
    }
};