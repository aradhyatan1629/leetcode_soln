class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n=nums.size();
        long long sum = 0;
        for(int i=0;i<nums.size();i++)
        {
            int mx=nums[i];
            int mn=nums[i];
            for(int j=i;j<nums.size();j++)
            {
                mx=max(mx,nums[j]);
                mn=min(mn,nums[j]);
                sum+=(mx-mn);
            }
        }
        return sum;
    }
};