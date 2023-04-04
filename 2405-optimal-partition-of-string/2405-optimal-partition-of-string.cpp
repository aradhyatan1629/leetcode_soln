class Solution {
public:
    int partitionString(string s) {
        unordered_set<char> st;
        int ans=0,cnt=0;
        int i=0,j=0,n=s.size();
        while(j<n)
        {
            if(st.find(s[j])==st.end())
            {
                st.insert(s[j]);
            }
            else
            {
                ans++;
                st.clear();
                st.insert(s[j]);
            }
            j++;
        }
        if(st.size()!=0)
        {
            ans++;
        }
        return ans;
    }
};