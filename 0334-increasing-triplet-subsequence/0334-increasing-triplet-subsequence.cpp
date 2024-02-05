class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n=nums.size();
        // vector<int> nsl,ngr;
        map<int,int> nsl,ngr;
        stack<int> st;
        for(int i=0;i<n;i++)
        {
            while(!st.empty() and st.top()>=nums[i])
                st.pop();
            if(!st.empty())
                nsl[i] = st.top();
            // else
            //     nsl.push_back(st.top());
            st.push(nums[i]);
        }
        while(!st.empty())
            st.pop();
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() and st.top()<=nums[i])
                st.pop();
            if(!st.empty())
                ngr[i] = st.top();
            // else
            //     ngr.push_back(st.top());
            st.push(nums[i]);
        }
        // reverse(ngr.begin(),ngr.end());
        for(int i=0;i<n;i++)
        {
            if(nsl.find(i)!=nsl.end() and ngr.find(i)!=ngr.end())
                return true;
        }
        return false;
    }
};