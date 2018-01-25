//标记一下就可以了，由于懒，没有用map，尺取法
class Solution {
public:
    string minWindow(string s, string t) {
        int vis[201], res[201];
        memset(vis, 0, sizeof(vis));
        memset(res, 0, sizeof(res));
        int len = t.length();
        for(int i = 0; i < len; i++)
        {
            vis[(int)t[i]]++;
        }
        int x = 0, xx = 0;
        for(int i = 0; i < 200; i++) if(vis[i]) x++;
        string ans = "";
        int l = 0, r = 0;
        len = s.length();
        while(r < len)
        {
            int cur = s[r];
            res[cur]++;
            if(res[cur] == vis[cur]) xx++;
            if(xx == x)
            {
                while(l < r)
                {
                    cur = s[l];
                    res[cur]--;
                    if(res[cur] < vis[cur]) break;
                    l++;
                }
                xx--;
                int L = ans.length();
                if(L == 0 || L > (r-l+1))
                    ans = s.substr(l, r-l+1);
                l++;
            }
            r++;
        }
        return ans;
    }
};
