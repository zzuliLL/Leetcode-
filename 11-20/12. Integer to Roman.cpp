class Solution {
public:
    string intToRoman(int num) {
        map<int, string> mp;
        mp[1] = "I";  mp[4] = "IV"; mp[5] = "V"; mp[9] = "IX";
        mp[10] = "X"; mp[40] = "XL";mp[50] = "L"; mp[90] = "XC";
        mp[100] = "C"; mp[400] = "CD"; mp[500] = "D"; mp[900] = "CM";
        mp[1000] = "M";
        string ans = "";

        while(num >= 1000) num -= 1000, ans += mp[1000];
        while(num >= 900) num -= 900, ans += mp[900];
        while(num >= 500) num -= 500, ans += mp[500];
        while(num >= 400) num -= 400, ans += mp[400];
        while(num >= 100) num -= 100, ans += mp[100];
        while(num >= 90) num -= 90, ans += mp[90];
        while(num >= 50) num -= 50, ans += mp[50];
        while(num >= 40) num -= 40, ans += mp[40];
        while(num >= 10) num -= 10, ans += mp[10];
        while(num >= 9) num -= 9, ans += mp[9];
        while(num >= 5) num -= 5, ans += mp[5];
        while(num >= 4) num -= 4, ans += mp[4];
        while(num >= 1) num -= 1, ans += mp[1];
        return ans;
    }
};
