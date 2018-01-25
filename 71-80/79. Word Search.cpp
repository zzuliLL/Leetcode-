//根据题意进行搜索
class Solution {
public:
    int vis[509][509];
    int nx[4] = {-1, 0, 0, 1};
    int ny[4] = {0, -1, 1, 0};
    int m, n;
    bool dfs(int i, int j, int l, int &r, string &word, vector<vector<char>> &board)
    {
        if(l == r) return true;
        for(int k = 0; k < 4; k++)
        {
            int x = i + nx[k];
            int y = j + ny[k];
            if(x < 0 || x >= m || y < 0 || y >= n) continue;
            if(vis[x][y]) continue;
            if(board[x][y] != word[l]) continue;
            vis[x][y] = 1;
            if(dfs(x, y, l+1, r, word, board)) return true;
            vis[x][y] = 0;
        }
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        if(board.size() == 0) return false;
        if(word.length() == 0) return true;
        m = board.size();
        n = board[0].size();
        int len = word.length();
        memset(vis, 0, sizeof(vis));
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(board[i][j] == word[0])
                {
                    vis[i][j] = 1;
                    if(dfs(i, j, 1, len, word, board)) return true;
                    vis[i][j] = 0;
                }
            }
        }
        return false;
    }
};