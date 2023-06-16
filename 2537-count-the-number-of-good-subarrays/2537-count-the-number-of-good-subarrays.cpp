class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        long long ans = 0;
        unordered_map<int,int> m;
        int i=0,j=0,n=nums.size();
        int pair=0;
        
        while(j<n)
        {
            m[nums[j]]++;
            pair+=m[nums[j]]-1;
            if(pair<k)
            {
                j++;
            }
            else if(pair>=k)
            {
                while(pair>=k)
                {
                    ans+=n-j;
                    pair-=m[nums[i]]-1;
                    m[nums[i]]--;
                    i++;
                }
                j++;
            }
        }
        return ans;
    }
};