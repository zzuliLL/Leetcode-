//dfs下，记得判断所有不合法的情况
class Solution {
public:
    void dfs(int cur, int n, vector<string> &mp, int vis[], vector<vector<string>> &ans)
    {
        if(cur >= n)
        {
            ans.push_back(mp);
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
            dfs(cur+1, n, mp, vis, ans);
            vis[i] = 0;
            mp[cur][i] = '.';
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        int vis[n];
        vector<string> mp;
        vector<vector<string>> ans;
        string s;
        for(int i = 0; i < n; i++) s += '.';
        for(int i = 0; i < n; i++) mp.push_back(s);
        memset(vis, 0, sizeof(vis));
        dfs(0, n, mp, vis, ans);
        return ans;
    }
};

//左上为x-y 右上角 x+y
class Solution {
public:
    void dfs(int cur, int n, vector<string> &mp, int vis[][20], vector<vector<string>> &ans)
    {
        if(cur >= n)
        {
            ans.push_back(mp);
            return ;
        }
        for(int i = 0; i < n; i++)
        {
            if(vis[0][i] || vis[1][n+cur-i] || vis[2][cur+i]) continue;
            vis[0][i] = vis[1][n+cur-i] = vis[2][cur+i] = 1;
            mp[cur][i] = 'Q';
            dfs(cur+1, n, mp, vis, ans);
            vis[0][i] = vis[1][n+cur-i] = vis[2][cur+i] = 0;
            mp[cur][i] = '.';
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        int vis[3][20];
        vector<string> mp;
        vector<vector<string>> ans;
        string s;
        for(int i = 0; i < n; i++) s += '.';
        for(int i = 0; i < n; i++) mp.push_back(s);
        memset(vis, 0, sizeof(vis));
        dfs(0, n, mp, vis, ans);
        return ans;
    }
};

