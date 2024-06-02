class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> vis(26,0);
        vector<int> lastIndex(26,-1);
        stack<char> st;
        int n = s.size();
        
        for(int i=0;i<n;i++)
            lastIndex[s[i]-'a'] = i;
        
        for(int i=0;i<n;i++)
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
            ans+=st.top(),st.pop();
        reverse(ans.begin(),ans.end());
        return ans;
    }
};