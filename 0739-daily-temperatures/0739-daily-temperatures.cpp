class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n=temperatures.size();
        vector<int> ngr;
        stack<int> st;
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() and temperatures[st.top()]<=temperatures[i])
                st.pop();
            if(st.empty())
                ngr.push_back(0);
            else
                ngr.push_back(st.top()-i);
            st.push(i);
        }
        reverse(ngr.begin(),ngr.end());
        return ngr;
    }
};