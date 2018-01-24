//同上一题，也可以DP
class Solution {
public:
    int vis[509][509];
    int dfs(int i, int j, int m, int n, vector<vector<int>>& grid)
    {
        if(vis[i][j] != 0x3f3f3f3f) return vis[i][j];
        if(i == m && n == j) return grid[m][n];
        if(i < m)
        {
            int k = dfs(i+1, j, m, n, grid);
            vis[i][j] = min(vis[i][j], k+grid[i][j]);
        }
        if(j < n)
        {
            int k = dfs(i, j+1, m, n, grid);
            vis[i][j] = min(vis[i][j], k+grid[i][j]);
        }
        return vis[i][j];
    }
    int minPathSum(vector<vector<int>>& grid) {
        if(grid.size() == 0) return 0;
        memset(vis, 0x3f, sizeof(vis));
        return dfs(0, 0, grid.size()-1, grid[0].size()-1, grid);
    }
};