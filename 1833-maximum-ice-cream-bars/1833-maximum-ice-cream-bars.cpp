class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(),costs.end());
        int cnt=0;
        int flag=1;
        for(int i=0;i<costs.size();i++)
        {
            if(coins==0)
            {
                break;
            }
            else if(coins<0)
            {
                flag=-1;
                break;
            }
            else
            {
                cnt++;
                coins=coins-costs[i];
            }
        }
        if(coins<0)
        {
            flag=-1;
        }
        if(flag==-1)
        {
            cnt--;
        }
        return cnt;
    }
};
// 2 3 3 5 6 6 6 7 9 10











