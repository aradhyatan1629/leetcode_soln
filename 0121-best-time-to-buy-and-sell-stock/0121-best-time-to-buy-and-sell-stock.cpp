class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mn = INT_MAX;
        int mxProfit = 0;
        for(int i=0;i<prices.size();i++)
        {
            mn = min(mn,prices[i]);
            mxProfit = max(mxProfit,prices[i]-mn);
        }
        return mxProfit;
    }
};