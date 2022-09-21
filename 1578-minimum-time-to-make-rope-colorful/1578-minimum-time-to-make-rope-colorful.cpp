class Solution {
public:
    int minCost(string colors, vector<int>& neededtime) {
        stack<pair<char,int>> st;
        int ans=0;
        for(int i=0;i<colors.size();i++)
        {
            if(st.empty())
            {
                st.push({colors[i],neededtime[i]});
            }
            else if(st.top().first==colors[i])
            {
                ans+=min(st.top().second,neededtime[i]);
                if(st.top().second<neededtime[i])
                {
                    st.top().second=neededtime[i];
                }
            }
            else
            {
                st.push({colors[i],neededtime[i]});
            }
        }
        return ans;
    }
};