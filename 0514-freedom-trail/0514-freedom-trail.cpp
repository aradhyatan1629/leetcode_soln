class Solution {
public:
    int countSteps(int ringIndex,int i,int n)
    {
        int dist = abs(i-ringIndex);
        int wrapAround = n-dist;
        return min(dist,wrapAround);
    }
    
    int solve(int ringIndex,int keyIndex,string &ring,string &key,vector<vector<int>> &dp)
    {
        if(keyIndex == key.size())
            return 0;
        
        if(dp[ringIndex][keyIndex]!=-1)
            return dp[ringIndex][keyIndex];
        
        int ans = 1e8;
        for(int i=0;i<ring.size();i++)
        {
            if(ring[i] == key[keyIndex])
            {
                int totalSteps = 1 + countSteps(ringIndex,i,ring.size()) + solve(i,keyIndex+1,ring,key,dp);
                ans = min(ans,totalSteps);
            }
        }
        return dp[ringIndex][keyIndex] = ans;
    }
    
    int findRotateSteps(string ring, string key) {
        int m = ring.size();
        int n = key.size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        return solve(0,0,ring,key,dp);
    }
};