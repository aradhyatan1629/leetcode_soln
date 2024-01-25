class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0)return 0;
        sort(nums.begin(),nums.end());
        int len=1,mx=0;
        for(int i=0;i<nums.size()-1;i++)
        {
            if(abs(nums[i]-nums[i+1])>1)
            {
                mx = max(mx,len);
                len=1;
            }
            else if(abs(nums[i]-nums[i+1])==1)
            {
                len++;
            }
        }
        mx = max(mx,len);
        return mx;
    }
}; 
// tc - O(nlogn)
