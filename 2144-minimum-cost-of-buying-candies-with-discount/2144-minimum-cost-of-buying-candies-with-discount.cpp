class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(),cost.end());
        int n = cost.size();
        int c=0;
        int cnt=0;
        for(int i=n-1;i>=0;i--)
        {
            cnt++;
            if(cnt==3)
            {
                cnt=0;
                continue;
            }
            else
            {
                c+=cost[i];
            }
        }
        return c;
    }
};

//2,2,5,6,7,9