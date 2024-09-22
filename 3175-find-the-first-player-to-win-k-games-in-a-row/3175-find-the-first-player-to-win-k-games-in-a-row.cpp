class Solution {
public:
    int findWinningPlayer(vector<int>& skills, int k) {
        int n = skills.size();
        int mxInd = 0;
        int mx = 0;
        
        for (int i = 0; i < n; i++) {
            if (skills[i] > mx) {
                mxInd = i;
                mx = skills[i];
            }
        }
        
        if (k >= n)
            return mxInd;
        
        int totalWins = 0;
        int playerIndex = 0;
        
        for(int i=1;i<n;i++){
            if(skills[playerIndex] > skills[i]){
                totalWins++;
            }
            else{
                totalWins = 1;
                playerIndex = i;
            }
            if(totalWins == k)
                return playerIndex;
        }
        return playerIndex;
    }
};
