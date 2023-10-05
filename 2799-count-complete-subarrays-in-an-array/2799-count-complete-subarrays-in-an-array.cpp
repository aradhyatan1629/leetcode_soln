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
    
    int countCompleteSubarrays(vector<int>& nums) {
        unordered_set<int> st(nums.begin(),nums.end());
        return atMostK(nums,st.size()) - atMostK(nums,st.size()-1);
    }
};