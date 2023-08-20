class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<vector<int>> ans;
        for(int i=0;i<nums.size();i++)
        {
            if(i>0 and nums[i]==nums[i-1])
            {
                continue;
            }
            int j = i+1;
            int k = n-1;
            while(j<k)
            {
                int sum = nums[i] + nums[j] + nums[k];
                if(sum<0)
                {
                    j++;
                }
                else if(sum>0)
                {
                    k--;
                }
                else
                {
                    ans.push_back({nums[i],nums[j],nums[k]});
                    j++;
                    k--;
                    while(j<k and nums[j]==nums[j-1]){j++;}
                    while(j<k and nums[k]==nums[k+1]){k--;}
                }
            }
        }
        return ans;
    }
};