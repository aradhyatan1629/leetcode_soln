class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        unordered_map<int,int> m;
        vector<int> ans;
        for(int i=0;i<nums.size();i++)
        {
            if(m[nums[i]]>=1)
            {
                ans.push_back(nums[i]);
            }
            m[nums[i]]++;
        }
        for(int i=1;i<=nums.size();++i)
        {
            if(m[i]==0)
            {
                ans.push_back(i);
                break;
            }
        }
        return ans;
    }
};