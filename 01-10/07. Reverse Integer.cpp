//求逆序数，注意范围为[-(1<<31), (1<<31)-1]

class Solution {
public:
    int reverse(long long x) {
        long long ans = 0;
        int f = x > 0 ? 1 : -1;
        x *= f;
        while(x)
        {
            ans = ans*10+x%10;
            x/=10;
        }
        long long s = 1ll<<31;
        ans *= f;
        if(ans >= s || ans < -s) return 0;
        return ans;
    }
};
