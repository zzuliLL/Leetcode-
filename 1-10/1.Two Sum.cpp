//O(n^2)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> s;
        for(int i = 0; i < nums.size(); i++)
        {
            for(int j = i + 1; j < nums.size(); j++)
                if(nums[i] + nums[j] == target)
                {
                    s.push_back(i);
                    s.push_back(j);
                    break;
                }
            if(s.size()) break;
        }
        return s;
    }
};

//O(n*log(n))
//通过map进行二分
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> s;
        map<int, int> mp;
        for(int i = 0; i < nums.size(); i++)
        {
            if(mp.find(target - nums[i]) != mp.end())
            {
                s.push_back(mp[target - nums[i]]);
                s.push_back(i);
                break;
            }
            mp[nums[i]] = i;
        }
        return s;
    }
};
