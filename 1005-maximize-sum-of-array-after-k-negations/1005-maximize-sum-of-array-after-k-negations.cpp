class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++)
        {
            if(k==0)
            {
                return accumulate(nums.begin(),nums.end(),0);
            }
            if(nums[i]<0)
            {
                nums[i] = -1*nums[i];
                k--;
            }
        }
        if(k%2==0)
        {
            return accumulate(nums.begin(),nums.end(),0);
        }
        int mn=INT_MAX;
        int index=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]<mn)
            {
                mn=min(mn,nums[i]);
                index=i;
            }
        }
        if(k%2==1)
        {
            nums[index]*=-1;
        }
        return accumulate(nums.begin(),nums.end(),0);
    }
};