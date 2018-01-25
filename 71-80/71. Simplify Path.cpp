//借鉴大佬博客：http://blog.csdn.net/makuiyu/article/details/44497901
//看完人家博客才知道题意，
class Solution {
public:
    string simplifyPath(string path) {
        string s;
        stack<string> st;
        int len = path.length(), i = 0;
        while(i < len)
        {
            while(i < len && path[i] == '/') i++;
            s.clear();
            while(i < len && path[i] != '/') s += path[i], i++;
            if(s == ".." && !st.empty()) st.pop();
            else if(s != "." && s != ".." && s != "") st.push(s);
        }
        if(st.empty()) return "/";
        s.clear();
        while(!st.empty())
        {
            s = '/'+st.top()+s;
            st.pop();
        }
        return s;
    }
};