class Solution {
public:
    string reverseParentheses(string s) {
        stack<char> st;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]==')')
            {
                string x;
                while(st.top()!='(')
                {
                    x+=st.top();
                    st.pop();
                }
                st.pop();
                for(int i=0;i<x.size();i++)
                {
                    st.push(x[i]);
                }
            }
            else
            {
                st.push(s[i]);
            }
        }
        string ans;
        while(!st.empty())
        {
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};