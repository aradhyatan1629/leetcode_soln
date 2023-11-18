class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_map<int,int> m;
        int i=0,j=0,n=nums.size();
        
        int mx=0,sum=0;
        
        while(j<n)
        {
            m[nums[j]]++;
            if(m[nums[j]]<=1)
            {
                sum+=nums[j];
                j++;
            }
            else
            {
                mx = max(mx,sum);
                while(m[nums[j]]>1)
                {
                    m[nums[i]]--;
                    sum-=nums[i];
                    i++;
                }
                sum+=nums[j];
                j++;
            }
        }
        mx=max(mx,sum);
        return mx;
    }
};