//单纯的处理每一行，每一列，只申请了两个栈的空间，就是题目中的第二种情况，O(m+n)
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        stack<int> r, l;
        int m = matrix.size();
        int n = matrix[0].size();
        for(int i = 0; i < m; i++)
        {
            bool f = false;
            for(int j = 0; j < n; j++)
            {
                if(matrix[i][j]) continue;
                f = true;
                l.push(j);
            }
            if(f) r.push(i);
        }
        while(!l.empty())
        {
            int v = l.top(); l.pop();
            for(int i = 0; i < m; i++) matrix[i][v] = 0;
        }
        while(!r.empty())
        {
            int u = r.top(); r.pop();
            for(int j = 0; j < n; j++) matrix[u][j] = 0;
        }
    }
};

//借鉴大牛博客：http://blog.csdn.net/u014654002/article/details/51524134
//空间复杂度为常数(2)
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int f, ff; f = ff = false;
        for(int i = 0; i < m; i++)
        {
            if(matrix[i][0]) continue;
            f = true;
        }
        for(int j = 0; j < n; j++)
        {
            if(matrix[0][j]) continue;
            ff = true;
        }
        for(int i = 1; i < m; i++)
        {
            for(int j = 1; j < n; j++)
            {
                if(matrix[i][j]) continue;
                matrix[i][0] = matrix[0][j] = 0;
            }
        }
        for(int i = 1; i < m; i++)
        {
            if(matrix[i][0]) continue;
            for(int j = 0; j < n; j++) matrix[i][j] = 0;
        }
        for(int j = 1; j < n; j++)
        {
            if(matrix[0][j]) continue;
            for(int i = 0; i < m; i++) matrix[i][j] = 0;
        }
        if(f) for(int i = 0; i < m; i++) matrix[i][0] = 0;
        if(ff) for(int j = 0; j < n; j++) matrix[0][j] = 0;
    }
};