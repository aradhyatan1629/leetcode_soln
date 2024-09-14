class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int mx = *max_element(nums.begin(),nums.end());
        int ans = 1;
        int len = 1;
        
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i] == mx && nums[i+1] == mx)
            {
                len++;
                ans = max(ans,len);
            }
            else
                len = 1;
        }
        
        return ans;
    }
};