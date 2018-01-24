//模拟大整数加法
class Solution {
public:
    string addBinary(string a, string b) {
        string ans;
        int r = a.length()-1, rr = b.length()-1;
        int p = 0;
        while(r >= 0 && rr >= 0)
        {
            int cur = a[r]+b[rr]+p-'0'-'0';
            ans += cur % 2 + '0';
            p = cur/2;
            r--;
            rr--;
        }
        while(r >= 0)
        {
            int cur = a[r] + p - '0';
            ans += cur % 2 + '0';
            p = cur/2;
            r--;
        }
        while(rr >= 0)
        {
            int cur = b[rr] + p - '0';
            ans += cur % 2 + '0';
            p = cur/2;
            rr--;
        }
        if(p) ans += p + '0';
        reverse(ans.begin(), ans.end());
        return ans;
    }
};