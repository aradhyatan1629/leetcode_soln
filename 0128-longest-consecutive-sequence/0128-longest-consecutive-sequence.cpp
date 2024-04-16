class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0)
            return 0;
        sort(nums.begin(),nums.end());
        int mx = 1;
        int len = 1;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]!=nums[i-1] && nums[i]-nums[i-1]>1)
                mx=max(mx,len),len=1;
            else if(nums[i]!=nums[i-1] && nums[i]-nums[i-1]==1)
                len++;
        }
        mx = max(mx,len);
        return mx;
    }
};