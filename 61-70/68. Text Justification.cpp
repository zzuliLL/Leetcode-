/**
*1.注意一行只有一个单词的
*2.特殊处理最后一行
*3.空格不能均匀放置时，尽量把剩余的空格均匀放置前面的单词之间
*/
class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int len = words.size(), i = 0;
        int sum, num;
        vector<string> ans;
        string s;
        while(i < len)
        {
            sum = num = 0;
            int j = i;
            while(j < len)
            {
                sum += words[j].length();
                if(sum >= maxWidth) break;
                sum++;
                j++;
            }
            if(j < len && sum == maxWidth)
            {
                s.clear();
                for(int k = i; k <= j; k++)
                {
                    s += words[k];
                    if(k != j) s += ' ';
                }
                i = j + 1;
            }
            else if(j == len)
            {
                s.clear();
                for(int k = i; k < j; k++)
                {
                    s += words[k];
                    if(k != j - 1) s += ' ';
                }
                sum--;
                for(int k = 1; k <= maxWidth-sum; k++) s += ' ';
                i = j;
            }
            else
            {
                sum -= words[j].length();
                s.clear();
                int num = j - i;
                sum -= num;
                int kg = maxWidth - sum, p;
                if(num == 1) p = 0;
                else
                {
                    p = kg % (num-1);
                    kg = kg / (num-1);
                }
                string cur;
                for(int k = 0; k < kg; k++) cur += ' ';
                for(int k = i; k < j; k++)
                {
                    s += words[k];
                    if(k != j - 1 || num == 1) s += cur;
                    if(k < i + p) s += ' ';
                }
                i = j;
            }
            ans.push_back(s);
        }
        return ans;
    }
};