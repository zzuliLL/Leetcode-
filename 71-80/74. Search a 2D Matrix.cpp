//注意搜索范围即可
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for(int i = 0; i < matrix.size(); i++)
        {
            int l, r;
            l = 0;
            r = matrix[i].size()-1;
            if(r < 0) return false;
            if(matrix[i][l] <= target && target <= matrix[i][r])
            {
                int k = lower_bound(matrix[i].begin(), matrix[i].end(), target) - matrix[i].begin();
                if(matrix[i][k] == target) return true;
                return false;
            }
        }
        return false;
    }
};
