class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int l=0,h=0;
        vector<int> v;
        int sum=accumulate(nums.begin(),nums.end(),0);
        if(sum==nums.size())
        {
            return nums.size()-1;
        }
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0 and i==0)
            {
                l=0;
                int j=1;
                while(nums[j]==1)
                {
                    h++;
                    j++;
                }
                v.push_back(l+h);
                l=0,h=0;
            }
            else if(nums[i]==0 and i==nums.size()-1)
            {
                h=0;
                int j=i-1;
                while(nums[j]==1)
                {
                    h++;
                    j--;
                }
                v.push_back(l+h);
                l=0,h=0;
            }
            else if(nums[i]==0 and (i!=0 and i!=nums.size()-1))
            {
                int j=i-1;
                int k=i+1;
                while(nums[j]==1)
                {
                    l++;
                    j--;
                    if(j<0)
                    {
                        break;
                    }
                }
                while(nums[k]==1)
                {
                    h++;
                    k++;
                    if(k==nums.size())
                    {
                        break;
                    }
                }
                v.push_back(l+h);
                l=0,h=0;
            }
        }
        return *max_element(v.begin(),v.end());
    }
};