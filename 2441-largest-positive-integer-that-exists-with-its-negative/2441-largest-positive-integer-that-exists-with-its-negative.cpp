class Solution {
public:
    int findMaxK(vector<int>& nums) {
        unordered_map<int,int> m;
        int mx = -1;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]>0 && m[-nums[i]]==1)
                mx=max(mx,nums[i]);
            if(nums[i]<0 && m[abs(nums[i])]==1)
                mx=max(mx,abs(nums[i]));
            m[nums[i]]=1;
        }
        return mx;
    }
};