class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size();
        int sum = 0;
        for(int i=0;i<m;i++)
            sum += rolls[i];
                
        int remSum = mean*(m+n) - sum;
        if(remSum<=0 || remSum<n || remSum > n*6)
            return {};
        
        vector<int> ans;
        int k = remSum/n;
        for(int i=0;i<n;i++)
        {
            ans.push_back(k);
            remSum -= k;
        }
        if(remSum > 0)
        {
            int i = 0;
            while(remSum > 0)
            {
                int x = 6 - ans[i];
                if(remSum >= x)
                {
                    ans[i] += x;
                    remSum -= x;
                }
                else
                {
                    ans[i] += remSum;
                    remSum = 0;
                }
                i++;
            }
        }
                
        return ans;
    }
};
/*

say you have 167 sum and you have to divide it among 40 nos such that each no. is b/w
[1,6] so do 167/40 = 4.16 something i.e
now 40*4 = 160
and then we are left with extra 7 sum
so we will again distribute this extra 7 sum 
*/

