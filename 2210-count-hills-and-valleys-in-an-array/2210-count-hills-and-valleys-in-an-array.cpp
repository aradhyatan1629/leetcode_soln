class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int right=0;
        int left=0;
        int ans=0;
        for(int i=1;i<nums.size()-1;i++)
        {
            for(int j=i+1;j<nums.size();j++)
            {
                if(nums[j]==nums[i])
                {
                    continue;
                }
                else
                {
                    right=nums[j];
                    break;
                }
            }
            for(int k=i-1;k>=0;k--)
            {
                if(nums[k]==nums[i])
                {
                    continue;
                }
                else
                {
                    left=nums[k];
                    break;
                }
            }
            if(nums[i]==nums[i-1])
            {
                continue;
            }
            if(nums[i]>right and nums[i]>left)
            {
                ans++;
            }
            if(nums[i]<right and nums[i]<left)
            {
                ans++;
            }
            // cout<<left<<" "<<nums[i]<<" "<<right<<" "<<ans<<endl;
        }
        return ans;
    }
};