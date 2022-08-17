class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mx = 0;
        int n = prices.size();
        vector<int> v(n,0);
        for(int i=n-1;i>=0;i--)
        {
            if(i==n-1)
            {
                v[i]=prices[n-1];
                continue;
            }
            if(prices[i]>v[i+1])
            {
                v[i]=prices[i];
            }
            else
            {
                v[i]=v[i+1];
            }
        }
        for(int i=0;i<n;++i)
        {
            int temp = abs(prices[i]-v[i]);
            if(temp>=mx)
            {
                mx=temp;
            }
        }
        return mx;
    }
};