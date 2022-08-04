class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        vector<int> v;
        int sum=0;
        if(nums.size()==1)
        {
            return nums[0];
        }
        for(int i=0;i<nums.size()-1;i++)
        {
            sum=0;
            sum+=nums[i];
            for(int j=i+1;j<nums.size();j++)
            {
                if(nums[j]>nums[j-1])
                {
                    sum+=nums[j];
                }
                else
                {
                    break;
                }
            }
            v.push_back(sum);
        }
        return *max_element(v.begin(),v.end());
    }
};
