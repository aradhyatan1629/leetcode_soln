class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<long long> v;
        long long ans=0;
        for(int i=0;i<n;i++)
        {
            long long sum=0;
            for(int j=i;j<n;j++)
            {
                sum+=nums[j];
                v.push_back(sum);
            }
        }
        sort(v.begin(),v.end());
        ans=0;
        int mod=1e9+7;
        for(int i=left-1;i<right;i++)
        {
            ans+=v[i];
            // cout<<ans<<endl;
        }
        return ans%mod;
    }
};