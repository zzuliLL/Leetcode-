//看了别人写的博客才知道，分以把整个图分解成每一行，每一行可以看做是求直方图的面积，借用84题函数
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> s;
        heights.push_back(0);
        int len = heights.size(), i = 0;
        int ans = 0;
        while(i < len)
        {
            if(s.empty() || heights[s.top()] < heights[i]) s.push(i);
            else
            {
                while(!s.empty() && heights[s.top()] > heights[i])
                {
                    int id = s.top(); s.pop();
                    int w = s.empty() ? i : i - s.top()-1;
                    ans = max(ans, heights[id]*w);
                }
                s.push(i);
            }
            i++;
        }
        return ans;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.size() == 0) return 0;
        vector<int> h(matrix[0].size(), 0);
        int ans = 0;
        for(int i = 0; i < matrix.size(); i++)
        {
            for(int j = 0; j < matrix[i].size(); j++)
            {
                h[j] = matrix[i][j] == '1' ? h[j]+1 : 0;
            }
            ans = max(ans, largestRectangleArea(h));
        }
        return ans;
    }
};