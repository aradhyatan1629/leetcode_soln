class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int mx=0;
        for(auto x:nums)
            mx = max(mx,x);
        
        int i=0,j=0,n=nums.size();
        long long int ans = 0;
        unordered_map<int,int> m;
        
        while(j<n)
        {
            m[nums[j]]++;
            while(m[mx]>=k)
            {
                ans += (n-j);
                m[nums[i]]--;
                i++;
            }
            j++;
        }
        return ans;
    }
};
