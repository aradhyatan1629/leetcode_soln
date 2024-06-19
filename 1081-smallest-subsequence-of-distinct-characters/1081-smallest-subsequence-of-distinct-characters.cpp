class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int> lastIndex(26,-1);
        vector<int> vis(26,0);
        for(int i=0;i<s.size();i++)
        {
            lastIndex[s[i]-'a'] = i;
        }
        stack<char> st;
        for(int i=0;i<s.size();i++)
        {
            if(vis[s[i]-'a']==1)
                continue;
            while(!st.empty() && s[i]<st.top() && lastIndex[st.top()-'a']>i)
            {
                vis[st.top()-'a'] = 0;
                st.pop();
            }
            vis[s[i]-'a']=1;
            st.push(s[i]);
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