//a,b,c分别存012的个数，就是桶排序
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int a, b, c; a = b = c = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] == 0) a++;
            else if(nums[i] == 1) b++;
            else c++;
        }
        nums.clear();
        while(a--) nums.push_back(0);
        while(b--) nums.push_back(1);
        while(c--) nums.push_back(2);
    }
};

//平移插入 借鉴博客：https://www.cnblogs.com/ganganloveu/p/3703746.html

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int a, b, c; a = b = c = -1;
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] == 0)
            {
                nums[++c] = 2;
                nums[++b] = 1;
                nums[++a] = 0;
            }
            else if(nums[i] == 1)
            {
                nums[++c] = 2;
                nums[++b] = 1;
            }
            else nums[++c] = 2;
        }
    }
};