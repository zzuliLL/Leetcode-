//四种情况，两负一正， 两正一负，三个0，一负一正一个0，map去下重

class Solution {
public:
    vector<vector<int>> ans;
    inline void work(vector<int> &s, int a, int b, int c){
        s.clear();
        s.push_back(a); s.push_back(b); s.push_back(c);
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<int> a, b, c, s;
        sort(nums.begin(), nums.end());
        unordered_map<int, int> mp;
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] < 0) a.push_back(nums[i]);
            else if(nums[i] == 0) b.push_back(nums[i]);
            else c.push_back(nums[i]);
            mp[nums[i]] = 1;
        }
        int len1 = a.size(), len2 = b.size(), len3 = c.size();
        if(len2 >= 3)
        {
            vector<int> s; work(s, 0, 0, 0); ans.push_back(s);
        }
        unordered_map<long long, int> mp1;
        long long now;
        for(int i = 0; i < len1; i++)
        {
            now = a[i]*1000000;
            if(!mp1[now] && mp[-a[i]] && len2)
            {
                work(s, a[i], 0, -a[i]);
                mp1[now] = 1;
                ans.push_back(s);
            }
            for(int j = i + 1; j < len1; j++)
            {
                int cur = a[i] + a[j];
                now = a[i]*1000000+a[j];
                if(mp[-cur] && !mp1[now])
                {
                    work(s, a[i], a[j], -cur);
                    mp1[now] = 1;
                    ans.push_back(s);
                }
            }
        }
        for(int i = 0; i < len3; i++)
        {
            for(int j = i + 1; j < len3; j++)
            {
                int cur = c[i] + c[j];
                now = c[i]*1000000+c[j];
                if(mp[-cur] && !mp1[now])
                {
                    work(s, -cur, c[i], c[j]);
                    mp1[now] = 1;
                    ans.push_back(s);
                }
            }
        }
        return ans;
    }
};


//法2：dml学长写的，枚举一个找另外两个和为target的数(leetcode第一题)

class Solution {
public:
    vector<vector<int>> ans;
    inline void work(vector<int> &s, int a, int b, int c) {
        s.clear();
        s.push_back(a); s.push_back(b); s.push_back(c);
    }
    void Two_sum(int l, int r, int target, vector<int> &nums) {
        vector<int> s;
        while(l < r)
        {
            if(nums[l] + nums[r] == -nums[target])
            {
                work(s, nums[target], nums[l], nums[r]);
                ans.push_back(s);
                while(l < r && nums[l+1] == nums[l]) l++;
                while(l < r && nums[r-1] == nums[r]) r--;
                l++;
                r--;
            }
            else if(nums[l] + nums[r] < -nums[target]) l++;
            else r--;
        }
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        if(nums.size() < 3) return ans;
        for(int i = 0; i < nums.size(); i++)
        {
            if(i > 0 && nums[i] == nums[i-1]) continue;
            Two_sum(i+1, nums.size()-1, i, nums);
        }
        return ans;
    }
};
