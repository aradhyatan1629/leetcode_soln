class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        int mn1=INT_MAX,mn2=INT_MAX;
        for(int i=0;i<prices.size();i++)
        {
            if(prices[i] <= mn1)
            {
                mn2 = mn1;
                mn1 = prices[i];
            }
            else if(prices[i] < mn2)
            {
                mn2 = prices[i];
            }
        }
        if(mn1+mn2 > money)
            return money;
        return money - (mn1+mn2);
    }
};