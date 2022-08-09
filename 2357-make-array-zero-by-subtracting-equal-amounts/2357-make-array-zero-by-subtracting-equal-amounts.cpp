class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int op=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0)
            {
                continue;
            }
            else
            {
                int mn = nums[i];
                for(int j=i;j<nums.size();j++)
                {
                    nums[j]-=mn;
                }
                op++;
            }
        }
        return op;
    }
};


//0,1,3,5,5