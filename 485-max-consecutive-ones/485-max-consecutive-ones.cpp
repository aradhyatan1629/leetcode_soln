class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        vector<int> v;
        int x=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==1)
            {
                x++;
            }
            else
            {
                v.push_back(x);
                x=0;
            }
        }
        v.push_back(x);
        return *max_element(v.begin(),v.end());
    }
};