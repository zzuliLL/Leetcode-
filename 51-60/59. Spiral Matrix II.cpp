//同54. Spiral Matrix题 模拟下
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        if(n == 0) return {};
        int res[n][n];
        int l, r, ll, rr;
        l = ll = 0;
        r = rr = n-1;
        int k = 1;
        while(true)
        {
            for(int j = ll; j <= rr; j++) res[l][j] = k++;
            if(k > n*n) break;
            for(int i = l+1; i <= r; i++) res[i][rr] = k++;;
            if(k > n*n) break;
            for(int j = rr-1; j >= ll; j--) res[r][j] = k++;
            if(k > n*n) break;
            for(int i = r-1; i > l; i--) res[i][ll] = k++;
            if(k > n*n) break;
            l++; r--;
            ll++; rr--;
        }
        vector<vector<int>> ans;
        vector<int> cur;
        for(int i = 0; i < n; i++)
        {
            cur.clear();
            for(int j = 0; j < n; j++)
                cur.push_back(res[i][j]);
            ans.push_back(cur);
        }
        return ans;
    }
};
