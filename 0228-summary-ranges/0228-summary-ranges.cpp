class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        if(nums.size()==0)
        {
            return {};
        }
        vector<string> v;
        int i=0,j=1;
        while(j<nums.size())
        {
            if(long(nums[j])-long(nums[j-1])!=1)
            {
                if(i==j-1)
                {
                    v.push_back(to_string(nums[i]));
                }
                else
                {
                    v.push_back(to_string(nums[i])+"->"+to_string(nums[j-1]));
                }
                i=j;
            }
            j++;
        }
        if(i<nums.size()-1)
        {
            v.push_back(to_string(nums[i])+"->"+to_string(nums[nums.size()-1]));
        }
        if(i==nums.size()-1)
        {
            v.push_back(to_string(nums[i]));
        }
        return v;
        
    }
};