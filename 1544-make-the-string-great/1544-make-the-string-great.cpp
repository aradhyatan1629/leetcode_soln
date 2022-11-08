class Solution {
public:
    string makeGood(string s) {
        stack<char> st;
        string ans;
        for(int i=0;i<s.size();i++)
        {
            if(st.empty())
            {
                st.push(s[i]);
            }
            else
            {
                if(st.top()==s[i]+32 or st.top()==s[i]-32)
                {
                    st.pop();
                    continue;
                }
                else
                {
                    st.push(s[i]);
                }
            }
        }
        while(!st.empty())
        {
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};