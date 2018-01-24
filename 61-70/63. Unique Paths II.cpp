//同上一题
class Solution {
public:
    int vis[101][101];
    int dfs(int i, int j, int m, int n, vector<vector<int>>& obstacleGrid)
    {
        if(vis[i][j] != -1) return vis[i][j];
        if(i == m && n == j) return 1;
        int a, b;
        a = b = 0;

        if(i < m && !obstacleGrid[i+1][j]) a = vis[i+1][j] = dfs(i+1, j, m, n, obstacleGrid);
        if(j < n && !obstacleGrid[i][j+1]) b = vis[i][j+1] = dfs(i, j+1, m, n, obstacleGrid);
        return a + b;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid.size() == 0) return 0;
        memset(vis, -1, sizeof(vis));
        int m = obstacleGrid.size()-1;
        int n = obstacleGrid[0].size()-1;
        if(obstacleGrid[m][n] || obstacleGrid[0][0]) return 0;
        return dfs(0, 0, m, n, obstacleGrid);
    }
};
