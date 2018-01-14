//先按照对角线翻转，然后再翻转每一行可以达到旋转90度的效果
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        for(int i = 0; i < matrix.size(); i++)
        {
            for(int j = 0; j < i; j++)
            {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        for(int i = 0; i < matrix.size(); i++) reverse(matrix[i].begin(), matrix[i].end());
    }
};