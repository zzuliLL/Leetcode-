//全排列公式扫一下就可以了，不会用STL的，可以手写dfs实现全排列
class Solution {
public:
    bool check(string &s)
    {
        stack<char> st;
        int len = s.length();
        for(int i = 0; i < len; i++)
        {
            if(s[i] == '(') st.push(s[i]);
            else
            {
                if(st.empty()) return false;
                if(st.top() == '(') st.pop();
                else return false;
            }
        }
        return true;
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string s = "";
        for(int i = 1; i <= n; i++) s += "()";
        sort(s.begin(), s.end());
        do
        {
            if(check(s)) ans.push_back(s);
        }
        while(next_permutation(s.begin(), s.end()));
        return ans;
    }
};