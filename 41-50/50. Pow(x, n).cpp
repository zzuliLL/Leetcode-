//手写快速幂，注意范围
class Solution {
public:
    double q_mod(double a, long long b)
    {
        if(abs(a - 1) < 1e-8) return 1.0;
        double ans = 1.0;
        int f = 1;
        if(b < 0) f = -1;
        b = abs(b);
        while(b)
        {
            if(b&1) ans *= a;
            a *= a;
            b >>= 1;
        }
        if(f == -1) return 1.0/ans;
        return ans;
    }
    double myPow(double x, int n) {
        return q_mod(x, n);
    }
};