class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char,int>> st;
        string ans;
        for(int i=0;i<s.size();i++)
        {
            if(st.empty() or st.top().first!=s[i])
            {
                st.push({s[i],1});
            }
            else 
            {
                auto prev=st.top();
                st.pop();
                st.push({s[i],prev.second+1});
            }
            if(st.top().second==k)
            {
                st.pop();
            }
        }
        while(!st.empty())
        {
            while(st.top().second!=0)
            {
                ans+=st.top().first;
                st.top().second--;
            }
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};