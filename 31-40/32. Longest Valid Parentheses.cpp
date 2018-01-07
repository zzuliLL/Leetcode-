//申请一个数组来存当前位置，如果当前位置是左括号，前一个位置是右括号，那么当前位置的最佳值就是前一个位置，否则为0；
//如果是右括号，看栈中是否为空，为空栈，当前位置为0，否则需要算到当前位置的最佳值 = 左括号前的最佳值 + 2 + 右括号前的最佳值。
//这样所有情况都给处理了。
class Solution {
public:

    int longestValidParentheses(string s) {
        int res = 0, ans = 0, len = s.length();
        int *f = (int*)malloc((len+1)*sizeof(int));
        f[0] = 0;
        stack<int> st;
        for(int i = 0; i < len; i++)
        {
            if(s[i] == '(')
            {
                if(i == 0 || s[i-1] == '(') f[i] = 0;
                else f[i] = f[i-1];
                st.push(f[i]);
            }
            else
            {
                if(!st.empty())
                {
                    int v = st.top(); st.pop();
                    f[i] = v + 2;
                    if(s[i-1] == ')') f[i] += f[i-1];
                }
                else f[i] = 0;
            }
            ans = max(ans, f[i]);
        }
        return ans;
    }
};