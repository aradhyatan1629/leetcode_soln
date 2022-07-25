class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        unordered_map<int,int> m;
        int i=0,sum=0;
        for(auto x:nums)
        {
            m[x]++;
        }
       for(int i=0;i<nums.size();i++)
       {
           if(m[nums[i]]==1)
           {
               sum+=nums[i];
           }
       }
        return sum;
    }
};