//题意就是给你一个数，让你加1返回，看了谈论区才看懂题意
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> ans;
        int len = digits.size();
        int p = 1;
        for(int i = len-1; i >= 0; i--)
        {
            int cur = p + digits[i];
            ans.push_back(cur%10);
            p = cur/10;
        }
        if(p) ans.push_back(p);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};