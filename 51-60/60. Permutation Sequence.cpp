//法1： STL
class Solution {
public:
    string getPermutation(int n, int k) {
        string s;
        for(int i = 1; i <= n; i++) s += i+'0';
        int cur = 0;
        do
        {
            cur++;
        }while(cur != k && next_permutation(s.begin(), s.end()) );
        return s;
    }
};
//手写的dfs， 跑的很慢，不知道人家怎么跑那么快
class Solution {
public:
    string ans;
    void dfs(int cur, int n, string &s, int &n_k, int &k)
    {
        if(cur == n)
        {
            n_k++;
            if(n_k == k) ans = s;
            return ;
        }
        string ss = s;
        for(int i = cur; i < n; i++)
        {
            ss[cur] = s[i];
            for(int j = cur+1; j <= i; j++) ss[j] = s[j-1];
            dfs(cur+1, n, ss, n_k, k);
            if(ans.length()) return ;
        }
    }
    string getPermutation(int n, int k) {
        string s;
        for(int i = 1; i <= n; i++) s += i+'0';
        int n_k = 0;
        dfs(0, n, s, n_k, k);
        return ans;
    }
};