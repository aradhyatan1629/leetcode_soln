class Solution {
public:
    bool isPossible(int day,int m,int k,vector<int> &bloomDay)
    {
        int cnt = 0;
        int noOfB = 0;
        for(int i=0;i<bloomDay.size();i++)
        {
            if(bloomDay[i]<=day)
            {
                cnt++;
            }
            else
            {
                noOfB += cnt/k;
                cnt = 0;
            }
        }
        noOfB += cnt/k;
        return noOfB >= m;
    }
    
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if((long long)(m) * (long long)(k) > n)
            return -1;
        
        int mn = INT_MAX;
        int mx = INT_MIN;
        for(int i=0;i<n;i++)
        {
            mn = min(mn,bloomDay[i]);
            mx = max(mx,bloomDay[i]);
        }
        
        int low = mn;
        int high = mx;
        
        while(low<=high)
        {
            int mid = low + (high-low)/2;
            if(isPossible(mid,m,k,bloomDay))
            {
                high = mid-1;
            }
            else
            {
                low = mid+1;
            }
        }
        return low;
    }
};
