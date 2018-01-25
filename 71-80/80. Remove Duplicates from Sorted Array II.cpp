//同 26.Remove Duplicates from Sorted Array，加个特判就好了，O(n)遍历下
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len = nums.size();
        if(len <= 1) return len;
        int p = 0, v = 1, f = 0;
        while(v < len)
        {
            if(nums[p] == nums[v])
            {
                if(!f) f = 1;
                else
                {
                    v++;
                    continue;
                }
            }
            else if(nums[p] != nums[v]) f = 0;
            nums[++p] = nums[v];
            v++;
        }
        p++;
        nums.resize(p);
        return p;
    }
};