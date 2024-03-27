class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int i=0,j=0,prod=1,n=nums.size();
        int cnt=0;
        if(k<=1)return 0;
        while(j<n)
        {
            prod*=nums[j];
            while(prod>=k)
            {
                prod/=nums[i];i++;
            }
            cnt += j-i+1;
            j++;
        }
        return cnt;
    }
};