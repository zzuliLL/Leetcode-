//������һֱû������ֻ�ðٶ����⣬ԭ���ǰڳ� _֮_ �ְ������

class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1) return s;
        int len = s.length(), i = 0, f = 0, h = 0;
        string ans[numRows];
        for(int i = 0; i < numRows; i++) ans[i] = "";
        while(i < len)
        {
            ans[h] += s[i];
            i++;
            if(!f) h++;
            else h--;
            if(h == numRows) f = !f, h -= 2;
            if(h == -1) f = !f, h += 2;
        }
        string res = "";
        for(int i = 0; i < numRows; i++) res += ans[i];
        return res;
    }
};
