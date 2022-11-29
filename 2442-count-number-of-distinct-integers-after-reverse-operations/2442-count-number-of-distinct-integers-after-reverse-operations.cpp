class Solution {
public:
    int countDistinctIntegers(vector<int>& nums) {
        unordered_set<int> s(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++)
        {
            int num=0;
            while(nums[i])
            {
                int rem=nums[i]%10;
                num=num*10 +rem;
                nums[i]/=10;
            }
            s.insert(num);
        }
        return s.size();
    }
};