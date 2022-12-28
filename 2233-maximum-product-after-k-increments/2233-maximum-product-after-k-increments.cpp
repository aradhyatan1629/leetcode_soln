class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>> pq;
        int mod=pow(10,9)+7;
        for(auto x:nums)
        {
            pq.push(x);
        }
        while(k--)
        {
            int x=pq.top()+1;
            pq.pop();
            pq.push(x);
        }
        long long int ans=1;
        while(!pq.empty())
        {
            ans=(ans*pq.top())%mod;
            pq.pop();
        }
        return ans;
    }
};
