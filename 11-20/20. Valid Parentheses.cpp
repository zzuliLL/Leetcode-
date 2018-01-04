//单纯比较下就OK了
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        int len = s.length();
        for(int i = 0; i < len; i++)
        {
            if(s[i] == '(' || s[i] == '[' || s[i] == '{') st.push(s[i]);
            else
            {
                if(st.empty()) return false;
                if(s[i] == ')' && st.top() == '(') st.pop();
                else if(s[i] == ']' && st.top() == '[') st.pop();
                else if(s[i] == '}' && st.top() == '{') st.pop();
                else return false;
            }
        }
        if(!st.empty()) return false;
        return true;
    }
};
