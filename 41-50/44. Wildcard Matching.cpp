//只记录最后一个*的位置，因为前面都匹配过了，如果所有的*都递归一遍，会超时
class Solution {
public:
    bool isMatch(string s, string p) {
        int ss, pp = -1;
        int r = s.length(), rr = p.length();
        int l, ll;
        l = ll = 0;
        while(l < r)
        {
            if(s[l] == p[ll] || p[ll] == '?') l++, ll++;
            else if(p[ll] == '*') ss = l, pp = ll++;
            else if(pp != -1) l = ++ss, ll = pp+1;
            else return false;
        }
        while(ll < rr && p[ll] == '*') ll++;
        return ll == rr;
    }
};

//dp[i][j] 就是s串前i个与p串前j个匹配
class Solution {
public:
    bool isMatch(string s, string p) {
        int r = s.length(), rr = p.length();
        int dp[r+1][rr+1];
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1;
        for(int i = 0; i < rr; i++)
        {
            if(p[i] == '*') dp[0][i+1] = 1;
            else break;
        }
        for(int i = 1; i <= r; i++)
        {
            for(int j = 1; j <= rr; j++)
            {
                if((s[i-1] == p[j-1] || p[j-1] == '?') && dp[i-1][j-1])
                    dp[i][j] = 1;
                else if(p[j-1] == '*') dp[i][j] |= dp[i][j-1]|dp[i-1][j]|dp[i-1][j-1];
            }
        }
        return dp[r][rr];
    }
};