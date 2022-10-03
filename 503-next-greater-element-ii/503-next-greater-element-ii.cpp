class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> ans;
        int i=0;
        while(i<nums.size()-1)
        {
            int j=0;
            for(j=i+1;j<nums.size();j++)
            {
                if(nums[j]>nums[i])
                {
                    ans.push_back(nums[j]);
                    break;
                }
            }
            if(j==nums.size())
            {
                int flag=-1;
                for(j=0;j<i;j++)
                {
                    if(nums[j]>nums[i])
                    {
                        flag=1;
                        ans.push_back(nums[j]);
                        break;
                    }
                }
                if(flag==-1)
                {
                    ans.push_back(-1);
                }
            }
            i++;
        }
        int temp=-1;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]>nums[nums.size()-1])
            {
                temp=1;
                ans.push_back(nums[i]);
                break;
            }
        }
        if(temp==-1)
        {
            ans.push_back(-1);
        }
        return ans;
    }
};