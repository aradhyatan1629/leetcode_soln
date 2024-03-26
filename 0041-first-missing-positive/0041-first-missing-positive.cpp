class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int i=0,n=nums.size();
        while(i<n and nums[i]<=0)
            i++;
        if(i<n and nums[i]!=1)
            return 1;
        while(i<n-1)
        {
            if(nums[i]!=nums[i+1] and nums[i+1]-nums[i] != 1)
                return nums[i]+1;
            i++;
        }
        if(nums[n-1]+1<=0)
            return 1;
        return nums[n-1]+1;
    }
};