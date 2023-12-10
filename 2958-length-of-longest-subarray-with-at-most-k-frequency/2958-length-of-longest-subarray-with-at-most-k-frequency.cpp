class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int mx=0;
        int i=0,j=0,n=nums.size();
        
        unordered_map<int,int> m;
        
        while(j<n)
        {
            m[nums[j]]++;
            if(m[nums[j]]<=k)
            {
                mx = max(mx,j-i+1);
            }
            else
            {
                while(m[nums[j]]>k)
                {
                    m[nums[i]]--;
                    i++;
                }
            }
            j++;
        }
        return mx;
    }
};