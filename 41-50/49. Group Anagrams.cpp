//map的合理运用
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        string s;
        vector<string> cur;
        map<string, int> mp;
        int k = 0;
        for(int i = 0; i < strs.size(); i++)
        {
            s = strs[i];
            sort(s.begin(), s.end());
            if(!mp.count(s))
            {
                mp[s] = k++;
                cur.clear();
                cur.push_back(strs[i]);
                ans.push_back(cur);
            }
            else ans[mp[s]].push_back(strs[i]);
        }
        return ans;
    }
};