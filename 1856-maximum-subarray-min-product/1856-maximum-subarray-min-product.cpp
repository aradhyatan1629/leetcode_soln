class Solution {
public:
    int maxSumMinProduct(vector<int>& nums) {
        vector<int> nsr,nsl;
        int n=nums.size();
        stack<int> st;
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() and nums[st.top()]>=nums[i])
                st.pop();
            if(st.empty())nsr.push_back(n);
            else nsr.push_back(st.top());
            st.push(i);
        }
        reverse(nsr.begin(),nsr.end());
        while(!st.empty())st.pop();
        for(int i=0;i<n;i++)
        {
            while(!st.empty() and nums[st.top()]>=nums[i])
                st.pop();
            if(st.empty())nsl.push_back(-1);
            else nsl.push_back(st.top());
            st.push(i);
        }
        vector<long long> pre;
        pre.push_back(0);
        for(int i=0;i<n;i++)
        {
            pre.push_back(pre[i]+nums[i]);
        }
        
        long long ans=0,mod=1e9+7;
        for (int i = 0; i < nums.size(); i++) {
		long long t = (pre[nsr[i]] - pre[nsl[i] + 1]) * nums[i];
		ans = max(ans, t);
        }
        return ans%mod;
    }
};












