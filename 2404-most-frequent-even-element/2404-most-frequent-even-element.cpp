class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        if(nums.size()==1)
        {
            int x=nums[0];
            if(x%2==0)
            {
                return x;
            }
            return -1;
        }
        unordered_map<int,int> m;
        for(auto x:nums)
        {
            if(x%2==0)
            {
                m[x]++;
            }
        }
        int mx=0;
        int ans=-1;
        for(auto x:m)
        {
            if(x.second>mx)
            {
                mx=x.second;
                ans=x.first;
            }
            else if(x.second==mx)
            {
                ans=min(ans,x.first);
            }
        }
        return ans;
    }
};