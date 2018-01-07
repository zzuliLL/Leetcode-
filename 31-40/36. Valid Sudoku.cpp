//模拟，就是简单判断下有没有重复
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        map<char, int> mp;
        for(int i = 0; i < 9; i++)
        {
            mp.clear();
            for(int j = 0; j < 9; j++)
            {
                if(board[i][j] == '.') continue;
                mp[board[i][j]]++;
                if(mp[board[i][j]] == 2) return false;
            }
            mp.clear();
            for(int j = 0; j < 9; j++)
            {
                if(board[j][i] == '.') continue;
                mp[board[j][i]]++;
                if(mp[board[j][i]] == 2) return false;
            }
        }
        for(int i = 0; i < 9; i += 3)
        {
            for(int j = 0; j < 9; j += 3)
            {
                mp.clear();
                for(int k = i; k < i+3; k++)
                {
                    for(int kk = j; kk < j+3; kk++)
                    {
                        if(board[k][kk] == '.') continue;
                        mp[board[k][kk]]++;
                        if(mp[board[k][kk]] == 2) return false;
                    }
                }
            }
        }
        return true;
    }
};
