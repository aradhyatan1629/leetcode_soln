class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        int n=nums.size();
        vector<long long> pre(n,0);
        pre[0]=nums[0];
        int index=n,mn=INT_MAX;
        for(int i=1;i<nums.size();i++)
        {
            pre[i]=pre[i-1]+nums[i];
        }
        for(int i=0;i<nums.size();i++)
        {
            long long avg_first=0,avg_last=0;
            avg_first = pre[i]/(i+1);
            if(i==n-1)
            {
                avg_last=0;
            }
            else
            {
                avg_last = (pre[n-1]-pre[i])/(n-i-1);
            }
            long long avg_diff = abs(avg_first-avg_last);
            if(avg_diff<mn)
            {
                index=i;
                mn=avg_diff;
            }
        }
        return index;
    }
};