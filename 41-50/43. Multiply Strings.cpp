//模拟下乘法
class Solution {
public:
    string multiply(string num1, string num2) {
        int res[301];
        memset(res, 0, sizeof(res));
        int len1 = num1.length(), len2 = num2.length();
        int len = len1+len2;
        int cur, a, b, p;
        for(int i = len1-1; i >= 0; i--)
        {
            a = num1[i] - '0';
            p = 0;
            cur = len;
            for(int j = len2-1; j >= 0; j--)
            {
                b = num2[j] - '0';
                int w = a*b+p+res[cur];
                res[cur] = w%10;
                p = w/10;
                cur--;
            }
            if(p) res[cur] += p;
            len--;
        }
        int i = 1;
        len = len1+len2;
        while(i <= len && res[i] == 0) i++;
        string s;
        if(i > len) return "0";
        for(; i <= len; i++) s += res[i] + '0';
        return s;
    }
};