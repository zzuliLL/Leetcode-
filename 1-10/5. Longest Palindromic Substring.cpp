//暴力O(n^2)也能过，数据才1000，所以很简单，下面是manacher算法，复杂度O(n)

class Solution
{
public:
    string longestPalindrome(string s)
    {
        int len = s.length();
        char ss[(len+6)<<1];
        int dp[(len+6)<<1];
        for(int i = len; i >= 0; i--)
        {
            ss[i * 2 + 1] = s[i];
            ss[i * 2] = '#';
        }

        int mx, id, ans;
        ans = mx = id = 0;
        for(int i = 0; ss[i]; i++)
        {
            dp[i] = mx > i ? min(dp[2*id-i], mx - i) : 1;
            while(i - dp[i] >= 0 && ss[i - dp[i]] == ss[i + dp[i]]) dp[i]++;
            if(mx - i < dp[i])
            {
                mx = i + dp[i];
                id = i;
            }
            if(dp[ans] < dp[i]) ans = i;
        }

        string ans_s = "";
        for(int j = ans - dp[ans] + 1; j < ans + dp[ans]; j++)
            if(ss[j] != '#') ans_s += ss[j];

        return ans_s;
    }
};
