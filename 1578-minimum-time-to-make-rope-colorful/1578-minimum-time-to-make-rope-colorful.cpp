class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        stack<pair<int,int>> st;  //{color,time}
        int n = neededTime.size();
        int ans=0;
        
        for(int i=0;i<n;i++)
        {
            if(st.empty())
            {
                st.push({colors[i],neededTime[i]});
            }
            else if(st.top().first != colors[i])
            {
                st.push({colors[i],neededTime[i]});
            }
            else
            {
                int mn = min(st.top().second,neededTime[i]);
                if(mn == st.top().second)
                {
                    ans+=mn;
                    st.pop();
                    st.push({colors[i],neededTime[i]});
                }
                else
                {
                    ans+=mn;
                }
            }
        }
        return ans;
    }
};