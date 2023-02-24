class Solution {
public:
    bool findSubarrays(vector<int>& nums) {
        unordered_map<int,int> m;
        int i=0,j=0,n=nums.size();
        int sum=0;
        while(j<n)
        {
            sum+=nums[j];
            if(j-i+1<2)
            {
                j++;
            }
            else if(j-i+1==2)
            {
                if(m[sum]==1)
                {
                    return true;
                }
                m[sum]=1;
                sum-=nums[i];
                i++;
                j++;
            }
        }
        return false;
    }
};