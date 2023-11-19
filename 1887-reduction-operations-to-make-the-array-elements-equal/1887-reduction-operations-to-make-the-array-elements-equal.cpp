class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        sort(nums.begin(),nums.end());        
        unordered_map<int,int> m;
        
        for(auto x:nums)
            m[x]++;
        if(m.size()==1)
            return 0;
        
        int ans=0;
        for(int i=nums.size()-1;i>0;i--)
        {
            if(nums[i]!=nums[i-1])
            {
                ans+=m[nums[i]];
                m[nums[i-1]]+=m[nums[i]];
                m[nums[i]]=0;
            }
        }
        return ans;
    }
};

