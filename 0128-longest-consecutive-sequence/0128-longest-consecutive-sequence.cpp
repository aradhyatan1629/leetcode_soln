class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0)
        {
            return 0;
        }
        sort(nums.begin(),nums.end());
        int len=1;
        int cnt = 1;
        
        for(int i=0;i<nums.size()-1;i++)
        {
            if(nums[i]!=nums[i+1] and nums[i]==nums[i+1]-1)
            {
                cnt++;
            }
            else if(nums[i]!=nums[i+1])
            {
                len = max(len,cnt);
                cnt=1;
            }
        }
        len = max(len,cnt);
        return len;
    }
};