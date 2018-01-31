//注意没有前导0
class Solution {
public:
    vector<string> ans;
    void dfs(string &s, string cur, int l, int r, int x)
    {
        if(l == r && x == -1)
        {
            ans.push_back(cur);
            return ;
        }
        string now = "";
        if(!x)
        {
            if(r - l > 3) return ;
            now = s.substr(l, r-l);
            if((r-l == 3 && now > "255") || (now[0] == '0' && r-l>1)) return ;
            dfs(s, cur+now, r, r, -1);
            return ;
        }
        for(int i = l; i + x < r; i++)
        {
            now += s[i];
            if(i-l+1 > 3) return ;
            else if(i-l+1 == 3 && now > "255") return ;
            dfs(s, cur+now+'.', i+1, r, x-1);
            if(now[0] == '0') return ;
        }
    }
    vector<string> restoreIpAddresses(string s) {
        int len = s.length();
        if(len > 12 || len < 4) return {};
        string cur;
        dfs(s, cur, 0, len, 3);
        return ans;
    }
};
