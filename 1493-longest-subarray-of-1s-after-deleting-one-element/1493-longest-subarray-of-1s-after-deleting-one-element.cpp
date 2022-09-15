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
                // cout<<"hi1"<<endl;
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
                // cout<<"hi2"<<endl;
                h=0;
                int j=i-1;
                while(nums[j]==1)
                {
                    // cout<<"entered"<<endl;
                    h++;
                    j--;
                }
                v.push_back(l+h);
                l=0,h=0;
            }
            else if(nums[i]==0 and (i!=0 and i!=nums.size()-1))
            {
                // cout<<"hi3"<<endl;
                int j=i-1;
                int k=i+1;
                while(nums[j]==1)
                {
                    // cout<<"entered1"<<endl;
                    // cout<<"j: "<<j<<endl;
                    l++;
                    j--;
                    if(j<0)
                    {
                        break;
                    }
                }
                while(nums[k]==1)
                {
                    // cout<<"entered2"<<endl;
                    // cout<<"k: "<<k<<endl;
                    h++;
                    k++;
                    if(k==nums.size())
                    {
                        // cout<<"break";
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