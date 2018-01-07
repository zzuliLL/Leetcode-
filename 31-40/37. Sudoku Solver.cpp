//暴力
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board, int i, int j) {
        for(int k = 0; k < 9; k++)
        {
            if(k == i) continue;
            if(board[k][j] == board[i][j]) return false;
        }
        for(int k = 0; k < 9; k++)
        {
            if(k == j) continue;
            if(board[i][k] == board[i][j]) return false;
        }
        for(int k = i/3*3; k < i/3*3+3; k++)
        {
            for(int kk = j/3*3; kk < j/3*3+3; kk++)
            {
                if(k != i && kk != j && board[k][kk] == board[i][j]) return false;
            }
        }
        return true;
    }
    bool solveSudoku(vector<vector<char>>& board) {
        for(int i = 0; i < 9; i++)
        {
            for(int j = 0; j < 9; j++)
            {
                if(board[i][j] == '.')
                {
                    for(int k = 1; k <= 9; k++)
                    {
                        board[i][j] = k+'0';
                        if(isValidSudoku(board, i, j) && solveSudoku(board)) return true;
                        board[i][j] = '.';
                    }
                    return false;
                }
            }
        }
        return true;
    }

};

