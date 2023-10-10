class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> s(nums.begin(),nums.end());
        nums.assign(s.begin(),s.end());
        sort(nums.begin(),nums.end());
        
        int m=nums.size();
        int mn=INT_MAX;
        int j=0;
        for(int i=0;i<m;i++)
        {
            while(j<m and nums[j]<nums[i]+n)
            {
                j++;
            }
            mn = min(mn,n-j+i);
        }
        return mn;
    }
};

