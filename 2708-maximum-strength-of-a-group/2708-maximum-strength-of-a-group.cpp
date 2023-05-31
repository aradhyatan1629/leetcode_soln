class Solution {
public:
    long long maxStrength(vector<int>& nums) {
        int cnt0=0;
        
        if(nums.size()==1)
        {
            return nums[0];
        }
        long long int ans = 1;
        vector<int> neg;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0)
            {
                cnt0++;
            }
            else if(nums[i]<0)
            {
                neg.push_back(nums[i]);
            }
        }
        if(neg.size()!=0 and neg.size()%2==0)
        {
            for(int i=0;i<nums.size();i++)
            {
                if(nums[i]!=0)
                {
                    ans*=nums[i];
                }
            }
            return ans;
        }
        sort(neg.begin(),neg.end());
        bool flag=false;
        
        if(neg.size()!=0 and neg.size()%2!=0)
        {
             for(int i=0;i<neg.size()-1;i++)
                {
                    flag=true;
                    ans*=neg[i];
                }
        }
       
        
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]>0)
            {
                flag=true;
                ans*=nums[i];
            }
        }
        
        if(!flag and cnt0>0)
        {
            return 0;
        }
        
        
        return ans;
    }
};