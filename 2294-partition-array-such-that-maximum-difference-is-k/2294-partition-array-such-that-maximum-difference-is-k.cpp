class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        int i=0;
        sort(nums.begin(),nums.end());
        int cnt=0;
        int min=nums[0];
        int flag=1;
        if(nums.size()==1)
        {
            return 1;
        }
        for(i=0;i<nums.size();i++)
        {
            int max=nums[i];
            if(max-min<=k)
            {
                continue;
            }
            else
            {
                flag=0;
                cnt++;
                min=nums[i];
            }
        }
        return cnt+1;
    }
};