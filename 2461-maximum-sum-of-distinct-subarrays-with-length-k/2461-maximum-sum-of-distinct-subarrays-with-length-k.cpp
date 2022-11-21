class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long sum=0;
        long long mx=0;
        int i=0,j=0,n=nums.size();
        unordered_map<int,int> m;
        while(j<n)
        {
            m[nums[j]]++;
            sum+=nums[j];
            if(j-i+1<k)
            {
                j++;
            }
            else if(j-i+1==k)
            {
                if(m.size()==k)
                {
                    mx=max(mx,sum);
                    sum-=nums[i];
                    // m.erase(nums[i]);
                    m[nums[i]]--;
                    if(m[nums[i]]==0)
                    {
                        m.erase(nums[i]);
                    }
                    i++;
                    j++;
                }
                else
                {
                    m[nums[i]]--;
                    sum-=nums[i];
                    if(m[nums[i]]==0)
                    {
                        m.erase(nums[i]);
                    }
                    i++;
                    j++;
                }
            }
        }
        return mx;
//         1,5,5,4,2,9,9,9
    }
};