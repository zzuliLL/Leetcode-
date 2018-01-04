//借鉴dml学长博客：http://littleblank.net/archives/1045/
class Solution {
public:
    bool check(string s, int i, string p, int j)
    {
        if(i == -1 && j == -1) return true;
        if(j == -1) return false;
        if(i == -1)
        {
            if(!(j&1)) return false;
            for(int k = 0; k <= j; k++)
            {
                if(k&1)
                {
                    if(p[k] != '*') return false;
                }
            }
            return true;
        }

        if(p[j] == '*')
        {
            if(p[j-1] == s[i] || p[j-1] == '.')
            {
                if(check(s, i-1, p, j)) return true;
            }
            return check(s, i, p, j-2);
        }
        if(s[i] == p[j] || p[j] == '.') return check(s, i-1, p, j-1);
        return false;
    }
    bool isMatch(string s, string p) {
        return check(s, s.length()-1, p, p.length()-1);
    }
};
