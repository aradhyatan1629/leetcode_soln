class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n=nums.size(),cnt=0;
        vector<long long> pre(n,0);
        vector<long long> suf(n,0);
        pre[0]=nums[0];
        suf[0]=nums[n-1];
        for(int i=1;i<pre.size();++i)
        {
            pre[i]=pre[i-1]+nums[i];
        }
        for(int i=1;i<suf.size();i++)
        {
            suf[i]=suf[i-1]+nums[n-i-1];
        }
        for(int i=0;i<nums.size()-1;i++)
        {
            if(pre[i]>=suf[n-i-2])
            {
                cnt++;
            }
        }
        return cnt;
    }
};