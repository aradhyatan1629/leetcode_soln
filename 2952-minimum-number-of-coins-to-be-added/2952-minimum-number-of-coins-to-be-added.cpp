class Solution {
public:
    int minimumAddedCoins(vector<int>& coins, int target) {
        int n = coins.size();
        sort(coins.begin(),coins.end());
       
        
        int j = 0;
        int currSum = 0;
        int cnt = 0;

        for(int i=1;i<=target;i=currSum+1)
        {
            if(j<n && (i == coins[j]))
            {
                currSum += i;
                j++;
            }
            else if(j<n && i>coins[j])
            {
                currSum += coins[j];
                j++;
            }
            else
            {
                cnt++;
                currSum += i;
            }
        }
        return cnt;
    }
};


/*

1,4,10

1,2,4,10
















*/