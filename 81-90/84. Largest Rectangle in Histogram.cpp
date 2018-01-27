//模拟一个单调递增的栈
//借鉴博客：https://www.cnblogs.com/ganganloveu/p/4148303.html
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int s = -1;
        int len = heights.size(), i = 0;
        int ans = 0;
        while(i < len)
        {
            if(s == -1 || heights[s] <= heights[i]) s = i;
            else
            {
                while(s >= 0 && heights[s] > heights[i])
                {
                    ans = max(ans, heights[s]*(i-s));
                    heights[s] = heights[i];
                    s--;
                }
                s = i;
            }
            i++;
        }
        while(s >= 0)
        {
            ans = max(ans, heights[s]*(len-s));
            s--;
        }
        return ans;
    }
};

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
};