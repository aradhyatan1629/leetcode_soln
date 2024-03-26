class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_map<int,int> m;
        for(int i=0;i<nums.size();i++)
            m[nums[i]]=1;
        int i=1;int ans;
        while(true)
        {
            if(m[i]==0)
            {
                ans=i;
                break;
            }
            i++;
        }
        return ans;
    }
};