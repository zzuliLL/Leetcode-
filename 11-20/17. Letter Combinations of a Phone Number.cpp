//dfs
class Solution {
public:
    string s[11] = {" ", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> ans;
    void dfs(string &p, int cur, int len, string &digits)
    {
        if(cur == len)
        {
            ans.push_back(p);
            return ;
        }
        int x = digits[cur] - '0';
        for(int i = 0; i < s[x].size(); i++)
        {
            p += s[x][i];
            dfs(p, cur+1, len, digits);
            p = p.substr(0, p.length()-1);
        }
    }
    vector<string> letterCombinations(string digits) {
        int len = digits.length();
        if(len == 0) return ans;
        string str = "";
        dfs(str, 0, len, digits);
        return ans;
    }
};
