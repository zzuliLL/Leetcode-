//简单DP，注意初始化哈
//dp[i][j]表示第一个串前i个字符和第2个串前j个匹配的最小编辑距离
//dp[i][j] = dp[i-1][j]+1   dp[i][j-1]+1   dp[i-1][j-1]+1 分别为插入 删除 替换
class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.length(), n = word2.length();
        if(m == 0 || n == 0) return max(m, n);
        int dp[m+1][n+1];
        dp[0][0] = 0;
        for(int i = 1; i <= m; i++) dp[i][0] = i;
        for(int i = 1; i <= n; i++) dp[0][i] = i;
        for(int i = 1; i <= m; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                if(word1[i-1] == word2[j-1]) dp[i][j] = dp[i-1][j-1];
                else dp[i][j] = min(dp[i][j-1], min(dp[i-1][j-1], dp[i-1][j]))+1;
            }
        }
        return dp[m][n];
    }
};
