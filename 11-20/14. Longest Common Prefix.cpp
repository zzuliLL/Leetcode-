//暴力比较下就可以了
class Solution {
public:
    int get_pre(string &a, string &b, int len)
    {
        for(int i = 0; i < len; i++)
        {
            if(a[i] != b[i]) return i;
        }
        return len;
    }

    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0) return "";
        int res = 0;
        for(int i = 1; i < strs.size(); i++)
        {
            if(strs[res].length() > strs[i].length()) res = i;
        }
        int len = strs[res].length();
        for(int i = 0; i < strs.size(); i++)
        {
            if(i == res) continue;
            len = get_pre(strs[i], strs[res], len);
        }
        string ans = strs[res].substr(0, len);
        return ans;
    }
};
