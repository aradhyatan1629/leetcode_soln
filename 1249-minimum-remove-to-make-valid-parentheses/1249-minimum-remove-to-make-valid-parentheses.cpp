class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> st;
        for(int i=0;i<s.size();i++)
        {
            if(st.empty() and (s[i]=='(' or s[i]==')'))
                st.push(i);
            else if(!st.empty() and (s[st.top()]=='(' and s[i]==')'))
                st.pop();
            else if(s[i]=='(' or s[i]==')')
                st.push(i);
        }
        while(!st.empty())
            s[st.top()]='#',st.pop();
        string ans;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]!='#')
                ans+=s[i];
        }
        return ans;
    }
};