//刚开始没能理解题意，然后看别人博客，原来是统计上一个字符串数字的个数
class Solution {
public:
    string countAndSay(int n) {
        string s = "1", e;
        for(int i = 2; i <= n; i++)
        {
            int j = 0, len = s.length();
            e = "";
            while(j < len)
            {
                int k = j;
                while(s[j] == s[k]) k++;
                e += k-j+'0';
                e += s[j];
                j = k;
            }
            s = e;
        }
        return s;
    }
};