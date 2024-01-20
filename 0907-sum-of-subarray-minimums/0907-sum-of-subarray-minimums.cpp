class Solution {
public:
    vector<int> nsl(vector<int> &arr)
    {
        int n=arr.size();
        vector<int> v;
        stack<int> st;
        for(int i=0;i<n;i++)
        {
            while(!st.empty() and arr[st.top()]>arr[i])
                st.pop();
            if(st.empty())v.push_back(-1);
            else v.push_back(st.top());
            st.push(i);
        }
        return v;
    }
    
    vector<int> nsr(vector<int> &arr)
    {
        int n=arr.size();
        vector<int> v;
        stack<int> st;
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() and arr[st.top()]>=arr[i])
                st.pop();
            if(st.empty())v.push_back(n);
            else v.push_back(st.top());
            st.push(i);
        }
        reverse(v.begin(),v.end());
        return v;
    }
    
    int sumSubarrayMins(vector<int>& arr) {
        vector<int> NSL = nsl(arr);
        vector<int> NSR = nsr(arr);
        
        long long sum=0;
        int m = 1e9+7,n=arr.size();
        
        for(int i=0;i<n;i++)
        {
            int ls = i-NSL[i];
            int rs = NSR[i]-i;
            long long totalWays = ls*rs;
            long long tSum = totalWays*arr[i];
            sum = (sum+tSum)%m;
        }
        
        return sum;
        
        
        
    }
};
