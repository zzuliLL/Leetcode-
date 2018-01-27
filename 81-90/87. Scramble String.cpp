//暴力写就可以了，借鉴博客：https://www.cnblogs.com/ganganloveu/p/4148000.html
class Solution {
public:
    bool isScramble(string s1, string s2) {
        if(s1 == s2) return true;
        int len1 = s1.length(), len2 = s2.length();
        if(len1 != len2) return false;
        vector<int> s(129, 0);
        for(int i = 0; i < len1; i++)
        {
            s[s1[i]]--;
            s[s2[i]]++;
        }
        for(int i = 0; i <= 128; i++) if(s[i]) return false;
        for(int i = 1; i < len1; i++)
        {
            if((isScramble(s1.substr(0, i), s2.substr(0, i)) && isScramble(s1.substr(i), s2.substr(i))) ||
              (isScramble(s1.substr(0, i), s2.substr(len1-i)) && isScramble(s1.substr(i), s2.substr(0, len1-i)))) return true;
        }
        return false;
    }
};