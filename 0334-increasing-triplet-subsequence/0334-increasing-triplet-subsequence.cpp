class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n=nums.size();
        vector<int> nsl(nums.size(),0),ngr(nums.size(),0);
        stack<int> st;
        for(int i=0;i<n;i++)
        {
            while(!st.empty() and st.top()>=nums[i])
                st.pop();
            if(!st.empty())
                nsl[i]=1;
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
                ngr[i]=1;
            // else
            //     ngr.push_back(st.top());
            st.push(nums[i]);
        }
        // reverse(ngr.begin(),ngr.end());
        for(int i=0;i<n;i++)
        {
            if(nsl[i]==1 and ngr[i]==1)
                return true;
        }
        return false;
    }
};