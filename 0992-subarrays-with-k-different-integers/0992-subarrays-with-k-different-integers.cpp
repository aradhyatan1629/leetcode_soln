class Solution {
public:
    
    int atMostK(vector<int> &nums,int k)
    {
        int i=0,j=0,n=nums.size();
        unordered_map<int,int> m;
        int cnt=0;
        while(j<n)
        {
            m[nums[j]]++;
            if(m.size()<=k)
            {
                cnt+=(j-i+1);
                j++;
            }
            else 
            {
                while(m.size()>k)
                {
                    m[nums[i]]--;
                    if(m[nums[i]]==0)
                    {
                        m.erase(nums[i]);
                    }
                    i++;
                }
                cnt+=(j-i+1);
                j++;
            }
        }
        return cnt;
    }
    
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMostK(nums,k) - atMostK(nums,k-1);
    }
};