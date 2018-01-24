//记忆化搜索，暴力搜索会超时，动态规划也可以写，其实记忆化搜索就是变相的DP
class Solution {
public:
    int vis[101][101];
    int dfs(int i, int j, int m, int n)
    {
        if(vis[i][j]) return vis[i][j];
        if(i == m && n == j) return 1;
        int a, b;
        a = b = 0;

        if(i < m) a = vis[i+1][j] = dfs(i+1, j, m, n);
        if(j < n) b = vis[i][j+1] = dfs(i, j+1, m, n);
        return a + b;
    }
    int uniquePaths(int m, int n) {
        memset(vis, 0, sizeof(vis));
        return dfs(1, 1, m, n);
    }
};