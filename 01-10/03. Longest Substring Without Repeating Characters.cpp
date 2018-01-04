//复杂度O(n),简单尺取法

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l, r, ans = 0;
        l = r = 0;
        int len = s.length();
        map<char, bool> mp;
        while(r < len)
        {
            if(mp[s[r]])
            {
                ans = max(ans, r - l);
                while(l < r && s[l] != s[r])
                {
                    mp[s[l]] = false;
                    l++;
                }
                l++;
            }
            mp[s[r]] = true;
            r++;
        }
        ans = max(ans, r - l);
        return ans;
    }
};
