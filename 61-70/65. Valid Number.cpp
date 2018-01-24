//WA了十万发，终于给A了，需要判断的地方有很多
// . + - ' ' e E等
class Solution {
public:
    bool isNumber(string s) {
        int len = s.length();

        int falg = 0, i = 0;
        while(i < len && s[i] == ' ') i++;
        if(len == i) return false;
        while(i < len)
        {
            if(isdigit(s[i])) i++;
            else if((s[i] == 'e' || s[i] == 'E') && falg != 2)
            {
                if(i == 0 || s[i-1] == ' ') return false;
                if(((i+1 < len) && isdigit(s[i+1])) || ((i+2 < len)&&((s[i+1] == '-'||s[i+1]=='+') && isdigit(s[i+2])))) i += 2;
                else return false;
                falg = 2;
            }
            else if(s[i] == '-' || s[i] == '+')
            {
                if(i - 1 >= 0 && isdigit(s[i-1])) return false;
                if((i+1 < len && isdigit(s[i+1])) || (i+2 < len && s[i+1] == '.' && isdigit(s[i+2]))) i += 2;
                else return false;
            }
            else if(s[i] == '.' && !falg)
            {
                i++;
                if(i < len && isdigit(s[i])) i++;
                else if(i - 2 >= 0 && isdigit(s[i-2])) ;
                else return false;
                falg = 1;
            }
            else if(s[i] == ' ')
            {
                while(i < len && s[i] == ' ') i++;
                if(i == len) return true;
                return false;
            }
            else return false;
        }
        return true;
    }
};