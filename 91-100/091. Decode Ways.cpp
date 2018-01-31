//暴力搜索哈
class Solution {
public:
    int my_numDecodings(string &s, int l, int r)
    {
        if(r - l <= 1)
        {
            if(l < r && s[l] == '0') return 0;
            return 1;
        }
        if(s[l] == '0') return 0;
        if(s[l] == '1')
        {
            if(s[l+1] == '0') return my_numDecodings(s, l+2, r);
            return my_numDecodings(s, l+1, r)+my_numDecodings(s, l+2, r);
        }
        if(s[l] == '2')
        {
            if(s[l+1] == '0' || s[l+1] > '6') return my_numDecodings(s, l+2, r);
            return my_numDecodings(s, l+1, r)+my_numDecodings(s, l+2, r);
        }
        return my_numDecodings(s, l+1, r);
    }
    int numDecodings(string s) {
        int len = s.length();
        if(!len) return 0;
        return my_numDecodings(s, 0, len);
    }
};

//上面的递归可以刚写成下面的DP，或者把上面的递归改成记忆化搜索，也可以降低时间，
//看到别人跑那么快就好奇百度了下，可以换成dp
//借鉴博客：http://blog.csdn.net/jmspan/article/details/51473562
class Solution {
public:
    int numDecodings(string s) {
        int len = s.length();
        if(!len) return 0;
        vector<int> dp(len+1, 0);
        if(s[0] != '0') dp[0] = 1;
        for(int i = 1; i <= len; i++)
        {
            if(s[i-1] != '0') dp[i] += dp[i-1];
            if(i > 1 && s[i-2] == '1') dp[i] += dp[i-2];
            if(i > 1 && s[i-2] == '2' && s[i-1] >= '0' && s[i-1] <= '6') dp[i] += dp[i-2];
        }
        return dp[len];
    }
};