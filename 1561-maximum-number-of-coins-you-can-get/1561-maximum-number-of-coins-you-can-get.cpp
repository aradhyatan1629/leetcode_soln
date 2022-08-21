class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(),piles.end());
        int n=piles.size();
        int cnt=0;
        for(int i=n/3;i<n;i+=2)
        {
            cnt+=piles[i];
        }
        return cnt;
    }
};

// 1 2 2 4 7 8 
// 2 4 5
// 9,8,7,6,5,1,2,3,4
// 1 2 3 4 5 6 7 8 9
