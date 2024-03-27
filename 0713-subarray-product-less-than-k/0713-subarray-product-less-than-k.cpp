class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n=nums.size(),cnt=0;
        for(int i=0;i<n;i++)
        {
            long long p=1;
            for(int j=i;j<n;j++)
            {
                p*=nums[j];
                if(p>=k)
                    break;
                cnt++;
            }
        }
        return cnt;
    }
};