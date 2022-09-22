class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        unordered_set<int> s;
        int n=nums.size();
        int x=0,y=0;
        for(int i=0;i<nums.size();i++)
        {
            if(s.find(nums[i])==s.end())
            {
                s.insert(nums[i]);
            }
            else
            {
                x=nums[i];
            }
        }
        for(int i=1;i<=n;i++)
        {
            if(s.find(i)==s.end())
            {
                y=i;
                break;
            }
        }
        return {x,y};
    }
};