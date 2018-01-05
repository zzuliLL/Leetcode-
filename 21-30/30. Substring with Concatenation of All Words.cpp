//check()函数有点乱，而且超级暴力
class Solution {
public:
    bool check(string &s, int l, int r, vector<string> &words)
    {
        int len = words[0].length();
        map<int, int> mp;
        for(int i = 0; i < words.size(); i++)
        {
            int k = s.find(words[i], l);
            while(mp[k] && k != -1)
            {
                k = s.find(words[i], k+len);
            }
            while((k - l) % len != 0 && k < r && k != -1)
            {
                int nx = k+len-((k-l)%len);
                k = s.find(words[i], nx);
                while(mp[k] && k != -1) k = s.find(words[i], k+len);
            }
            if(k == r && len != 1) return false;
            if(k == -1 || k > r ) return false;
            mp[k] = 1;
        }
        return true;
    }
    vector<int> findSubstring(string s, vector<string>& words) {
        int len = s.length(), x = words[0].length()*words.size();
        vector<int> ans;
        for(int i = 0; i + x - 1 < len; i++)
        {
            if(check(s, i, i+x-1, words)) ans.push_back(i);
        }
        return ans;
    }
};