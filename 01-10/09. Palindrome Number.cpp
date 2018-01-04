//负数不是回文数，注意溢出

class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        long long xx = 0,  xxx = x;
        while(x)
        {
            xx = xx*10+x%10;
            x/=10;
        }
        if(xx == xxx) return true;
        return false;
    }
};
