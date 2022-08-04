class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        long mx = INT_MIN;
        long diff = -1;
        for(int i=0;i<nums.size()-1;i++)
        {
            for(int j=i+1;j<nums.size();j++)
            {
                if(nums[i]<nums[j])
                {
                    diff = nums[j]-nums[i];
                    mx = max(mx,diff);
                }
            }
        }
        if(diff==-1)
        {
            return -1;
        }
        return mx;
    }
};