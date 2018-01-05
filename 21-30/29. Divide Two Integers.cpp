//重复倍增减法
class Solution {
public:
    int divide(int dividend, int divisor) {
        int o = 1;
        if((dividend < 0 && divisor > 0) || (dividend >= 0 && divisor < 0)) o = -1;
        long long a, b, c;
        a = dividend; b = divisor;
        a = abs(a);
        b = abs(b);
        c = b;
        long long ans = 0, f = 1;
        while(a >= c)
        {
            b = c; f = 1;
            while(a >= b){a -= b;b += b;ans += f;f += f;}
        }
        ans *= o;
        if(ans >= (1ll<<31)) ans = (1ll<<31)-1;
        return ans;
    }
};