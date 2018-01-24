//暴力
class Solution {
public:
    int mySqrt(int x) {
        long long i = 0;
        for( ; i*i <= x; i++) ;
        return i-1;
    }
};

//二分
class Solution {
public:
    int mySqrt(int x) {
        long long l, r;
        l = 0; r = x;
        while(l <= r)
        {
            long long mid = (l+r)>>1;
            if(mid * mid > x) r = mid - 1;
            else l = mid + 1;
        }
        return l-1;
    }
};
