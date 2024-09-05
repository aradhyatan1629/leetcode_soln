class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size();
        int s = accumulate(rolls.begin(),rolls.end(),0);
        
        int remSum = mean*(m+n) - s;
        if(remSum<0 || remSum<n || remSum > n*6)
            return {};
        
        vector<int> ans;
        int k = remSum/n;
        int extra = remSum - k*n;
        
        for(int i=0;i<n;i++)
        {
            int t = k;
            if(extra > 0)
            {
                if(extra > 6-k)t += 6-k;
                else t += extra;
                extra -= (6-k);
            }
            ans.push_back(t);
        }
        return ans;
    }
};