//模拟哈，记录前面最大与最小的编号
class Solution {
public:
    int trap(vector<int>& height) {
        int mx, mi;
        mx = mi = 0;
        int ans = 0;
        for(int i = 1; i < height.size(); i++)
        {
            if(height[i] > height[mi] && height[mx] > height[mi])
            {
                int h = min(height[i], height[mx]);
                for(int j = mx+1; j < i; j++)
                {
                     if(h < height[j]) continue;
                     ans += h - height[j];
                     height[j] = h;
                }
            }
            mi = height[i] >= height[mi] ? mi : i;
            mx = height[i] >= height[mx] ? i : mx;
            if(mi < mx) mi = mx;
        }
        return ans;
    }
};