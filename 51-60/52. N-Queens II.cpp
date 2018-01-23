//同上一题
class Solution {
public:
    void dfs(int cur, int n, vector<string> &mp, int vis[])
    {
        if(cur >= n)
        {
            ans++;
            return ;
        }
        for(int i = 0; i < n; i++)
        {
            if(vis[i]) continue;
            int j = 1;
            while(cur - j >= 0 && i - j >= 0 && mp[cur-j][i-j] == '.') j++;
            if(cur - j >= 0 && i - j >= 0 && mp[cur-j][i-j] == 'Q') continue;
            j = 1;
            while(cur-j>=0&&i+j<n&&mp[cur-j][i+j]=='.') j++;
            if(cur-j>=0&&i+j<n&&mp[cur-j][i+j]=='Q') continue;
            vis[i] = 1;
            mp[cur][i] = 'Q';
            dfs(cur+1, n, mp, vis);
            vis[i] = 0;
            mp[cur][i] = '.';
        }
    }
    int ans;
    int totalNQueens(int n) {
        int vis[n];
        ans = 0;
        vector<string> mp;
        string s;
        for(int i = 0; i < n; i++) s += '.';
        for(int i = 0; i < n; i++) mp.push_back(s);
        memset(vis, 0, sizeof(vis));
        dfs(0, n, mp, vis);
        return ans;
    }
};