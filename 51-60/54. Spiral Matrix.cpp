//模拟下
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if(matrix.size() == 0) return {};
        int l, r, ll, rr;
        r = matrix.size()-1;
        rr = matrix[0].size()-1;
        l = ll = 0;
        vector<int> ans;
        while(l <= r && ll <= rr)
        {
            for(int j = ll; j <= rr; j++) ans.push_back(matrix[l][j]);
            if(l < r) for(int i = l+1; i <= r; i++) ans.push_back(matrix[i][rr]);
            if(l < r) for(int j = rr-1; j >= ll; j--) ans.push_back(matrix[r][j]);
            if(ll < rr)for(int i = r-1; i > l; i--) ans.push_back(matrix[i][ll]);
            ll++; rr--;
            l++; r--;
        }
        return ans;
    }
};
