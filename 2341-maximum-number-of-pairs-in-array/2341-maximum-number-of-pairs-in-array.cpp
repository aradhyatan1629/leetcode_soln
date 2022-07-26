class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size(),pr=0,flag=1;
        for(int i=0;i<nums.size()-1;i++)
        {
            if(nums[i]==nums[i+1] and flag==1)
            {
                pr++;
                flag=-1;
            }
            else
            {
                flag=1;
            }
        }
        int t = n - pr*2;
        vector<int> v;
        v.push_back(pr);
        v.push_back(t);
        return v;
    }
};