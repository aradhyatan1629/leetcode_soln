class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int j=nums.size()-1;
        int mx=INT_MIN;
        for(int i=0;i<nums.size()/2;i++)
        {
            mx=max(mx,nums[i]+nums[j]);
            j--;
        }
        return mx;
    }
};

