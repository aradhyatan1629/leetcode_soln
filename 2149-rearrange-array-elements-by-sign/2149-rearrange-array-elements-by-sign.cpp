class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> p,n;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]>0)
                p.push_back(nums[i]);
            else
                n.push_back(nums[i]);
        }
        bool flag=true;int j=0,k=0;
        for(int i=0;i<nums.size();i++)
        {
            if(flag)
            {
                nums[i]=p[j];j++;
            }
            else
            {
                nums[i]=n[k];k++;
            }
            flag=!flag;
        }
        return nums;
    }
};