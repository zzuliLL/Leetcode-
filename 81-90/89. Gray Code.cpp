//倒着变化，从最低位开始，借鉴博客：https://www.cnblogs.com/jdneo/p/5228780.html
class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> ans(1<<n, 0);
        int k = 1, l = 1<<n;
        while(k < l)
        {
            int s = k;
            for(int i = k-1; i >= 0; i--)
            {
                ans[s++] = ans[i] + k;
            }
            k <<= 1;
        }
        return ans;
    }
};