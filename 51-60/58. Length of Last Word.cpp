//题虽然简单，但有点坑，注意空格的位置哈
class Solution {
public:
    int lengthOfLastWord(string s) {
        int ans = 0, res = 0;
        int len = s.length();
        for(int i = 0; i < len; i++)
        {
            if(s[i] != ' ') res++;
            else if(res) ans = res, res = 0;
        }
        if(res) ans = res;
        return ans;
    }
};