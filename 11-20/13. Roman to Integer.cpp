class Solution {
public:
    int romanToInt(string s) {
        map<string, int> mp;
        mp["I"] = 1;  mp["IV"] = 4; mp["V"] = 5; mp["IX"] = 9;
        mp["X"] = 10; mp["XL"] = 40; mp["L"] = 50; mp["XC"] = 90;
        mp["C"] = 100; mp["CD"] = 400; mp["D"] = 500; mp["CM"] = 900;
        mp["M"] = 1000;
        int ans = 0;
        int i = 0, len = s.length();
        while(i < len)
        {
            while(i < len && s[i] == 'M') ans += 1000, i++;
            if(i + 1 < len && s[i] == 'C' && s[i+1] == 'M') ans += 900, i += 2;
            if(i < len && s[i] == 'D') ans += 500, i++;
            if(i+1 < len && s[i] == 'C' && s[i+1] == 'D') ans += 400, i += 2;
            while(i < len && s[i] == 'C') ans += 100, i++;
            if(i + 1 < len && s[i] == 'X' && s[i+1] == 'C') ans += 90, i += 2;
            if(i < len && s[i] == 'L') ans += 50, i++;
            if(i+1 < len && s[i] == 'X' && s[i+1] == 'L') ans += 40, i += 2;
            while(i < len && s[i] == 'X') ans += 10, i++;
            if(i + 1 < len && s[i] == 'I' && s[i+1] == 'X') ans += 9, i += 2;
            if(i < len && s[i] == 'V') ans += 5, i++;
            if(i+1 < len && s[i] == 'I' && s[i+1] == 'V') ans += 4, i += 2;
            while(i < len && s[i] == 'I') ans++, i++;
        }
        return ans;
    }
};
