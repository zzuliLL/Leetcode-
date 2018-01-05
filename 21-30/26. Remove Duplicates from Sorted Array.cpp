class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len = nums.size();
        if(len <= 1) return len;
        int p = 1;
        int v = 0;
        for(int i = 1; i < len; i++) 
        {
            if(nums[i] != nums[v])
            {
                v = i;
                nums[p++] = nums[i];
            }
        }
        nums.resize(p);
        return p;
    }
};

//法2: STL
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        return unique(nums.begin(), nums.end()) - nums.begin();
    }
};