class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        stack<int> st;
        vector<int> v;
        for(int i=n-1;i>=0;i--)
        {
            if(st.empty())
            {
                v.push_back(0);
            }
            else if(!st.empty() and temperatures[st.top()]>temperatures[i])
            {
                v.push_back(st.top()-i);
            }
            else if(!st.empty() and temperatures[st.top()]<=temperatures[i])
            {
                while(!st.empty() and temperatures[st.top()]<=temperatures[i])
                {
                    st.pop();
                }
                if(st.empty())
                {
                    v.push_back(0);
                }
                else
                {
                    v.push_back(st.top()-i);
                }
            }
            st.push(i);
        }
        reverse(v.begin(),v.end());
        return v;
    }
};