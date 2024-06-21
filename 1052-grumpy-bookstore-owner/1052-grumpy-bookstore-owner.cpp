class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = customers.size();
        int ans = 0;
        for(int i=0;i<customers.size();i++)
        {
            if(grumpy[i]==0)
                ans += customers[i];
        }
        
        int i=0,j=0,k = minutes;
        int mx = ans;
        int more = 0,cnt1=0;
        while(j<n)
        {
            more += (grumpy[j]==1) ? customers[j] : 0;
            if(j-i+1 < k)
            {
                j++;
            }
            else if(j-i+1 == k)
            {
                mx = max(mx,ans+more);
                if(grumpy[i] == 1)
                    more -= customers[i];
                i++,j++;
            }
        }
        return mx;
    }
};