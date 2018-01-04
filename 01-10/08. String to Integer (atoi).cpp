//这个题虽然简单，但需要注意读题，很坑啊

class Solution {
public:
    int myAtoi(string str) {
        int len = str.length(), i = 0;
        vector<int> x;
        int f = 0;
        while(i < len)
        {
            if(str[i] == ' ')
            {
                if(f) break;
                i++;
                continue;
            }

            if(str[i] == '+')
            {
                if(f == 0) f = 1;
                else break;
            }
            else if(str[i] == '-')
            {
                if(f == 0) f = -1;
                else break;
            }
            else if(isdigit(str[i]))
            {
                if(f == 0) f = 1;
                x.push_back(str[i] - '0');
            }
            else break;
            i++;
        }
        long long ans = 0, s = 1ll<<31;
        for(int i = 0; i < x.size(); i++)
        {
            ans = ans*10+x[i];
            if(ans >= s) break;
        }

        ans *= f;
        if(ans >= s) return (int)(s-1);
        if(ans < -s) return (int)(-s);
        return (int)ans;
    }
};
