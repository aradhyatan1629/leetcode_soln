class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int totproduct=1;
        int zero=0;
        vector<int> ans;
        for(auto x:nums)
        {
            totproduct*=x;
            if(x==0)
            {
                zero++;
            }
        }
        if(totproduct!=0)
        {
            for(int i=0;i<nums.size();i++)
            {
                ans.push_back(totproduct/nums[i]);
            }
        }
        int totproduct2=1;
        for(auto x:nums)
        {
            if(x!=0)
            {
                totproduct2*=x;
            }
        }
        if(totproduct==0 and zero==1)
        {
            for(auto x:nums)
            {
                if(x==0)
                {
                    ans.push_back(totproduct2);
                }
                else
                {
                    ans.push_back(0);
                }
            }
        }
        if(totproduct==0 and zero>1)
        {
            for(auto x:nums)
            {
                ans.push_back(0);
            }
            return ans;
        }
        return ans;
    }
};

