//去重
class Solution {
public:
    int numTrees(int n) {
        int f[21];
        f[0] = f[1] = 1;
        f[2] = 2;
        f[3] = 5;
        for(int i = 4; i <= n; i++)
        {
            f[i] = 0;
            for(int j = 1; j <= i; j++) f[i] += f[j-1] * f[i-j];
        }
        return f[n];
    }
};