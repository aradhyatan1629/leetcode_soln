class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> ans;
        int i=0,j=0;
        while(i<nums.size() or j<nums.size())
        {
            while(i<nums.size() and nums[i]<0)
            {
                i++;
            }
            if(i<nums.size())
            {
                ans.push_back(nums[i]);
            }
            while(j<nums.size() and nums[j]>0)
            {
                j++;
            }
            if(j<nums.size())
            {
                ans.push_back(nums[j]);
            }
            i++;
            j++;
        }
        return ans;
    }
};